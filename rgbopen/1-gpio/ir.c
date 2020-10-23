#include "user.h"


//????
void cleanData()
{
        accTimeH = 0;
				MaybeRemoteStart = 0;       //?????
        RemoteStart = 0;
        sleepFlag = 0;
        bitIndex = 0;
        OneCode = 0;
        ZeroCode = 0;
        ReadOver = 0;
}

void proHight()
{
		TR1 = 0;
	T1Counter = TH1;
	T1Counter = T1Counter << 5;
	T1Counter = T1Counter + (TL1&0x1F);
	T1Counter = T1Counter + (accTimeH*8192);
	T1Counter = T1Counter;
	TL1 = (8192-8192) & 0x1F;       //初始值低字节，TL0 的高 3 位是无效的
  TH1 = (8192-8192) >> 5; 
	accTimeH = 0;
	TR1 = 1;
		if(MaybeRemoteStart && T1Counter > (HeadCont_H - (FaultTolerant*FaultTolerantX)) && T1Counter < (HeadCont_H + (FaultTolerant*FaultTolerantX)))
		{
                MaybeRemoteStart = 0;       //?????
                RemoteStart = 1;
                sleepFlag = 0;
                bitIndex = 0;
                OneCode = 0;
                ZeroCode = 0;
                ReadOver = 0;
		}
		else if(RemoteStart)
		{
			if((T1Counter> (OneCode_H - FaultTolerant))&&(T1Counter < (OneCode_H + FaultTolerant)))
            {
                OneCode = 1;
                ZeroCode = 0;
            }
            else
            {
                if((T1Counter > (Zero_H - FaultTolerant))&&(T1Counter < (Zero_H + FaultTolerant)))
                {
                    ZeroCode = 1;
                    OneCode = 0;
                }
                else
                {
                    ZeroCode = 0;
                    OneCode = 0;
                }
            }
            
            if(OneCode)
            {
                //?????bit ?1
                GetOneByte(1);
            }
         	else if(ZeroCode)
            {
                //?????bit ?0
                GetOneByte(0);
            }
		}
		else
		{
			 MaybeRemoteStart = 0;       //?????
             RemoteStart = 0;
            sleepFlag = 0;
            bitIndex = 0;
            OneCode = 0;
            ZeroCode = 0;
            ReadOver = 0;
		
		}
	
		
}

void proLow()
{
	TR1 = 0;
	T1Counter = TH1;
	T1Counter = T1Counter << 5;
	T1Counter = T1Counter + (TL1&0x1F);
	T1Counter = T1Counter + (accTimeH*8192);
	T1Counter = T1Counter;
	TL1 = (8192-8192) & 0x1F;       //初始值低字节，TL0 的高 3 位是无效的
  TH1 = (8192-8192) >> 5; 
	accTimeH = 0;
	TR1 = 1;
	if((T1Counter > (HeadCont_L - (FaultTolerant*FaultTolerantX)))&&(T1Counter < (HeadCont_L + (FaultTolerant*FaultTolerantX))))
    {
        RemoteStart = 0;       //?????
        MaybeRemoteStart = 1;		//???????
        sleepFlag = 0;
        bitIndex = 0;
        OneCode = 0;
        ZeroCode = 0;
        ReadOver = 0;
    }
	else if(RemoteStart)
	{
//	    if((T1Counter > (FootCont_L - FaultTolerant)) &&(T1Counter < (FootCont_L + (FaultTolerant*FaultTolerantX)))) //???,??????????
//        {
//            ReadOver = 1;
//            OneCode = 0;
//            ZeroCode = 0;
//            RemoteStart = 0;
//            bitIndex = 0;
//        }
		
		if((T1Counter >(OneCode_L - FaultTolerant))&&(T1Counter < (OneCode_L + FaultTolerant)))
        {
            //????
           _nop_();
        }
        else
        {
            //????,??????
            cleanData();
            
        }
	}
		
}


void GetOneByte(u8t bitNub)
{
	if(RemoteStart)
	{
		    if(bitIndex == 0)
			{
				bitIndex = 0;
				value = 0;
				data1 = data2 = data3 = data4 = 0;
			}
			++bitIndex;
			if(bitNub)
			{
				value |= 0x80;
			
			}
			if(bitIndex == 8)
			{
				data1 = value;
			}
			else if(bitIndex == 16)
			{
				data2 = value;

			}
			else if(bitIndex == 24)
			{
				data3 = value;

			}
			else if(bitIndex == 32)
			{
				data4 = value;
		        ReadOver = 1;
                OneCode = 0;
                ZeroCode = 0;
                RemoteStart = 0;
                bitIndex = 0;
				
			}
			value = value >> 1;
	}
}


/*****************************************************
*函数名称：void init_timer1(void)
*函数功能：Timer1初始化配置
*入口参数：
*出口参数：
*****************************************************/
void init_timer1(void)
{
	TMOD &= 0x0f;                	//定时器,时钟为系统时钟 12 分频 
									//模式0,TL1 和 TH1 组成 13 位定时器/计数器
    TL1 = (8192-41) & 0x1F;       //初始值低字节，TL1 的高 3 位是无效的
    TH1 = (8192-41) >> 5;         //初始值高字节(1ms@16MHz)
								
    ET1 = 1;	//开中断 定时器 1 中断使能控制位
    EA = 1;		//总中断
    TR1 = 1;	//启动定时器
}


/*****************************************************
* 中断服务函数
*****************************************************/
void timer1_isr (void) interrupt 3  
{
    /* set timer1 as mode0 (13-bit) */
    TL1 = (8192-8192) & 0x1F;       //初始值低字节，TL0 的高 3 位是无效的
    TH1 = (8192-8192) >> 5;         //初始值高字节(1ms@16MHz)
	// todo ...
		++accTimeH;
		//P35=~P35;
}