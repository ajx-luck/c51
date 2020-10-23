
/*********************************************************
*Copyright (C), 2020-2030, 深圳前海维晟智能技术有限公司
*文件名:	gpio.c
*作  者:	
*版  本:	V1.00
*日  期:	20200418
*描  述:	
*备  注:     
**********************************************************/
#include "user.h"

//IR






//RGB





//ctr


static void delay(int i)
{
	long j;
	for(j=0;j<10*i;++j);
}

static void delay_1ms(void)
{
	int j;
	for(j=0;j<1700;++j);
}

static void delay_10ms(void)
{
	int j;
	for(j=0;j<17700;++j);
}

void Delay80us()
{
	int j;
	for(j =0;j<100;j++)
	{
		_nop_();
		if(IR == 0)
			return;
	}
}


void Delay10Us(void){
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
}

/******************************************************************
说明：
*******************************************************************/
void main()
{
	u8 i;
	//系统时钟配置
    SCCON = 0x00;//HRC
	HRCON |= 0x80;
	
	P10F = 2; 
	P10=0;
	delay_10ms();	// 如果使用了下载口P33/P34 , 需要在mian函数中初始化P33/34之前加延时，复位后才能下载程序
	P10=0;
    /****************** 管脚配置 ********************/
	P10F = 0x81; //输入，打开上拉
    P11F = 2; 
    P12F = 2;
    P13F = 2; 
    P14F = 2; 
    P15F = 2;
    P16F = 2; 
    P17F = 2; 
	
    P30F = 2;
    P31F = 2;
    P32F = 2;
   // P33F = 1;
   // P34F = 2;
    P35F = 1;
	INT1Level = 1;
	init_timer0();
	init_timer1();
	while(1)
	{
		
		if(ReadOver)
		{
			proData();
		}
		if(INT1Level && IR == 1)
		{ 
			INT1Level = 0;
			proLow();
		}
		else if(INT1Level == 0 && IR == 0)
		{

			INT1Level = 1;
			proHight();
		}
		WDTFLG=0XA5;//??
		if(!IntFlag || MaybeRemoteStart || RemoteStart)
        	continue;			//10ms????
		IntFlag = 0;
		if(keyRead(~P10) == 2)
		{
				if(workStep == 0)
				{
						powerOn();
				}
				else
				{
						powerOff();
				}
		}
	
		if(workStep == 0)
		{
			//sendtoLast(BLACK,1,LED_OPEN);
			//sendtoLast(BLACK,2,LED_HL);
			sendtoLast(BLACK,3,LED_HL);
			deadLock = 0;
			deadtime = 0;
		}
		else
		{
				workCtr();
			  
		}
		
	
        //i= 5;while(i--)delay(100);
	}
}


void proData()
{

	irCode = (u8t)(~data4);
	if(irCode == data3 && keyTime == 0)
	{
		keyTime = 10;
		switch(irCode)
		{
			case 0x45:
			sendtoLast(RED,3,LED_HL);
			break;
			case 0x46:
			sendtoLast(GREEN,3,LED_HL);
			break;
			case 0x1E:
			powerOff();
			break;
			case 0x1F:
			powerOn();
			break;
			case 0x1C:				//light inc
			if(++duty >= 20)
				duty = 20;
			break;
			case 0x1D:				//light dec
			if(--duty < 8)
						duty = 8;
			break;
			case 0x00:
				colorStep = 1;
			break;
			case 0x04:
				colorStep = 2;
			break;
			case 0x08:
				colorStep = 3;
			break;
			case 0x0C:
				colorStep = 4;
			break;
			case 0x10:
				colorStep = 5;
			break;
			
			case 0x01:
				colorStep = 6;
			break;
			case 0x05:
				colorStep = 7;
			break;
			case 0x09:
				colorStep = 8;
			break;
			case 0x0D:
				colorStep = 9;
			break;
			case 0x11:
				colorStep = 10;
			break;
			
			case 0x02:
				colorStep = 11;
			break;
			case 0x06:
				colorStep = 12;
			break;
			case 0x0A:
				colorStep = 13;
			break;
			case 0x0E:
				colorStep = 14;
			break;
			case 0x12:
				colorStep = 15;
			break;
			case 0x03:
				colorStep = 16;
			break;
			
//			case 0x09:
//			break;
//			case 0x0C:
//			break;
//			case 0x0D:
//			break;
//			case 0x0E:
			default:
			break;
		}
	}
	ReadOver = 0;
	writeNvr();
}

//0为关机 1为三色常亮模式	2为灯带全彩流水	3为等带跑马流水 4多单色移动 5整体流水模式
void workCtr()
{
		if(workStep == 1)
		{
				showSingleColor();
		}


}



//显示单色
void showSingleColor()
{

	sendtoLast2(rgbs[colorStep],1,LED_OPEN);
	sendtoLast2(rgbs[colorStep],2,LED_HL);
	sendtoLast2(rgbs[colorStep],3,LED_HL);
	/**
	switch(colorStep)
				{
					case 1:
						sendtoLast(RED,1,LED_OPEN);
						sendtoLast(RED,2,LED_HL);
						sendtoLast(RED,3,LED_HL);
						break;
						case 2:
						sendtoLast(COLOR2,1,LED_OPEN);
						sendtoLast(COLOR2,2,LED_HL);
						sendtoLast(COLOR2,3,LED_HL);
						break;
						case 3:
						sendtoLast(COLOR3,1,LED_OPEN);
						sendtoLast(COLOR3,2,LED_HL);
						sendtoLast(COLOR3,3,LED_HL);
						break;
						case 4:
						sendtoLast(COLOR4,1,LED_OPEN);
						sendtoLast(COLOR4,2,LED_HL);
						sendtoLast(COLOR4,3,LED_HL);
						break;
							case 5:
						sendtoLast(COLOR5,1,LED_OPEN);
						sendtoLast(COLOR5,2,LED_HL);
						sendtoLast(COLOR5,3,LED_HL);
						break;
							
							case 6:
						sendtoLast(GREEN,1,LED_OPEN);
						sendtoLast(GREEN,2,LED_HL);
						sendtoLast(GREEN,3,LED_HL);
						break;
						case 7:
						sendtoLast(COLOR7,1,LED_OPEN);
						sendtoLast(COLOR7,2,LED_HL);
						sendtoLast(COLOR7,3,LED_HL);
						break;
						case 8:
						sendtoLast(COLOR8,1,LED_OPEN);
						sendtoLast(COLOR8,2,LED_HL);
						sendtoLast(COLOR8,3,LED_HL);
						break;
						case 9:
						sendtoLast(COLOR9,1,LED_OPEN);
						sendtoLast(COLOR9,2,LED_HL);
						sendtoLast(COLOR9,3,LED_HL);
						break;
							case 10:
						sendtoLast(COLOR10,1,LED_OPEN);
						sendtoLast(COLOR10,2,LED_HL);
						sendtoLast(COLOR10,3,LED_HL);
						break;
							
							case 11:
						sendtoLast(BLUE,1,LED_OPEN);
						sendtoLast(BLUE,2,LED_HL);
						sendtoLast(BLUE,3,LED_HL);
						break;
						case 12:
						sendtoLast(COLOR12,1,LED_OPEN);
						sendtoLast(COLOR12,2,LED_HL);
						sendtoLast(COLOR12,3,LED_HL);
						break;
						case 13:
						sendtoLast(COLOR13,1,LED_OPEN);
						sendtoLast(COLOR13,2,LED_HL);
						sendtoLast(COLOR13,3,LED_HL);
						break;
						case 14:
						sendtoLast(COLOR14,1,LED_OPEN);
						sendtoLast(COLOR14,2,LED_HL);
						sendtoLast(COLOR14,3,LED_HL);
						break;
						case 15:
						sendtoLast(COLOR15,1,LED_OPEN);
						sendtoLast(COLOR15,2,LED_HL);
						sendtoLast(COLOR15,3,LED_HL);
						break;
						case 16:
						sendtoLast(WHITE,1,LED_OPEN);
						sendtoLast(WHITE,2,LED_HL);
						sendtoLast(WHITE,3,LED_HL);
						break;
				}
				
				*/
}



char keyRead(char keyStatus)	
{ 
	if(keyStatus)
	{
		keyCount++;
		if(keyCount >= 200)
		{
			keyCount = 200;
			if(!longPressFlag)
			{
				longPressFlag = 1;
				return 2;
			}
		}
	}
	else
	{
		if(keyCount >= 200)
		{
			keyCount = 0;
			longPressFlag = 0;
			return	0;
		}
		else if(keyCount >= 8)
		{
			keyCount = 0;
			return	1;
		}
		keyCount = 0;
	}
	return 0;
}


void powerOn()
{
	u8t i;
	for(i=0;i<SECTOR_SIZE;i++)
			rbuf[i]=0;
		readDatafromNVR(rbuf,NVR1_START_ADDR,SECTOR_SIZE);
		delay_1ms();
		workStep = rbuf[0];
		colorStep = rbuf[1];
		starFlag = rbuf[2];
		allIncStep = rbuf[3];
		duty = 20;
		if(workStep == 0 || workStep > 5)
				workStep = 1;
		if(colorStep == 0 || colorStep > 16)
				colorStep = 1;
}

void powerOff()
{
		workStep = 0;
		
}

void writeNvr()
{
		EraseNVR(NVR1_START_ADDR);
		delay_1ms();
		buf[0] = workStep;
		buf[1] = colorStep;
		buf[2] = starFlag;
		buf[3] = allIncStep;
		WriteDataNVR(buf,NVR1_START_ADDR,SECTOR_SIZE);
}




//RGB


void breath3(unsigned char *data1,unsigned char *data2,unsigned char *data3,char index)
{
    if((*data3) > 10)
	{
		--(*data3);
	}
	
 	if((*data2) > 10)
	{
		--(*data2);
	}
	
	if((*data1) > 10)
	{
		--(*data1);
	}
	sendtoLast(*data1,*data2,*data3,index);
}

void sendRGB(unsigned char colorR,unsigned char colorG,unsigned char colorB)
{
//		Rdata = colorR;
//		Gdata = colorG;
		EA = 0;
		Rdata = colorR;
		Gdata = colorG;
		Bdata = colorB ;
		
		if(R7)
		NUB1();
		else
		NUB0();
		if(R6)
		NUB1();
		else
		NUB0();
		if(R5)
		NUB1();
		else
		NUB0();
		if(R4)
		NUB1();
		else
		NUB0();
		if(R3)
		NUB1();
		else
		NUB0();
		if(R2)
		NUB1();
		else
		NUB0();
		if(R1)
		NUB1();
		else
		NUB0();
		if(R0)
		NUB1();
		else
		NUB0();
		//G
		if(G7)
		NUB1();
		else
		NUB0();
		if(G6)
		NUB1();
		else
		NUB0();
		if(G5)
		NUB1();
		else
		NUB0();
		if(G4)
		NUB1();
		else
		NUB0();
		if(G3)
		NUB1();
		else
		NUB0();
		if(G2)
		NUB1();
		else
		NUB0();
		if(G1)
		NUB1();
		else
		NUB0();
		if(G0)
		NUB1();
		else
		NUB0();
		//B
		if(B7)
		NUB1();
		else
		NUB0();
		if(B6)
		NUB1();
		else
		NUB0();
		if(B5)
		NUB1();
		else
		NUB0();
		if(B4)
		NUB1();
		else
		NUB0();
		if(B3)
		NUB1();
		else
		NUB0();
		if(B2)
		NUB1();
		else
		NUB0();
		if(B1)
		NUB1();
		else
		NUB0();
		if(B0)
		NUB1();
		else
		NUB0();

	PB3 = 0;	
		EA = 1;
}

void sendRGB2(unsigned char colorR,unsigned char colorG,unsigned char colorB)
{
//		Rdata = colorR;
//		Gdata = colorG;
		EA = 0;
		Rdata = colorR;
		Gdata = colorG;
		Bdata = colorB ;
		
		if(R7)
		NUB21();
		else
		NUB20();
		if(R6)
		NUB21();
		else
		NUB20();
		if(R5)
		NUB21();
		else
		NUB20();
		if(R4)
		NUB21();
		else
		NUB20();
		if(R3)
		NUB21();
		else
		NUB20();
		if(R2)
		NUB21();
		else
		NUB20();
		if(R1)
		NUB21();
		else
		NUB20();
		if(R0)
		NUB21();
		else
		NUB20();
		//G
		if(G7)
		NUB21();
		else
		NUB20();
		if(G6)
		NUB21();
		else
		NUB20();
		if(G5)
		NUB21();
		else
		NUB20();
		if(G4)
		NUB21();
		else
		NUB20();
		if(G3)
		NUB21();
		else
		NUB20();
		if(G2)
		NUB21();
		else
		NUB20();
		if(G1)
		NUB21();
		else
		NUB20();
		if(G0)
		NUB21();
		else
		NUB20();
		//B
		if(B7)
		NUB21();
		else
		NUB20();
		if(B6)
		NUB21();
		else
		NUB20();
		if(B5)
		NUB21();
		else
		NUB20();
		if(B4)
		NUB21();
		else
		NUB20();
		if(B3)
		NUB21();
		else
		NUB20();
		if(B2)
		NUB21();
		else
		NUB20();
		if(B1)
		NUB21();
		else
		NUB20();
		if(B0)
		NUB21();
		else
		NUB20();

	PA7 = 0;
	EA = 1;
}


void sendRGB3(unsigned char colorR,unsigned char colorG,unsigned char colorB)
{
//		Rdata = colorR;
//		Gdata = colorG;
		EA = 0;
		Rdata = colorR;
		Gdata = colorG;
		Bdata = colorB ;
		

		if(R7)
		NUB31();
		else
		NUB30();
		if(R6)
		NUB31();
		else
		NUB30();
		if(R5)
		NUB31();
		else
		NUB30();
		if(R4)
		NUB31();
		else
		NUB30();
		if(R3)
		NUB31();
		else
		NUB30();
		if(R2)
		NUB31();
		else
		NUB30();
		if(R1)
		NUB31();
		else
		NUB30();
		if(R0)
		NUB31();
		else
		NUB30();
		//G
		if(G7)
		NUB31();
		else
		NUB30();
		if(G6)
		NUB31();
		else
		NUB30();
		if(G5)
		NUB31();
		else
		NUB30();
		if(G4)
		NUB31();
		else
		NUB30();
		if(G3)
		NUB31();
		else
		NUB30();
		if(G2)
		NUB31();
		else
		NUB30();
		if(G1)
		NUB31();
		else
		NUB30();
		if(G0)
		NUB31();
		else
		NUB30();
		//B
		if(B7)
		NUB31();
		else
		NUB30();
		if(B6)
		NUB31();
		else
		NUB30();
		if(B5)
		NUB31();
		else
		NUB30();
		if(B4)
		NUB31();
		else
		NUB30();
		if(B3)
		NUB31();
		else
		NUB30();
		if(B2)
		NUB31();
		else
		NUB30();
		if(B1)
		NUB31();
		else
		NUB30();
		if(B0)
		NUB31();
		else
		NUB30();
		
	PA0 = 0;
		EA = 1;
}


void sendtoLast(unsigned char colorR,unsigned char colorG,unsigned char colorB,char index,unsigned char ledCount)
{
	int j;
	char tempcolorR,tempcolorG,tempcolorB;
	Rdata1 = colorR;
	Gdata1 = colorG;
	Bdata1 = colorB;
	tempcolorR = (colorR/DUTYMAX)*duty;
	tempcolorG = (colorG/DUTYMAX)*duty;
	tempcolorB = (colorB/DUTYMAX)*duty;
	for(j=0;j<ledCount;j++)
	{
		if(index == 1)
			sendRGB(tempcolorR,tempcolorG,tempcolorB);
		else if(index == 2)
			sendRGB2(tempcolorR,tempcolorG,tempcolorB);
		else if(index == 3)
			sendRGB3(tempcolorR,tempcolorG,tempcolorB);
		
		if(IR == 0)
			return;
	}
	Delay80us();
}


void sendtoLast2(SRGB srgb,char index,unsigned char ledCount)
{
	sendtoLast(srgb.red,srgb.green,srgb.blue,index,ledCount);
}





/* RGB 单点累加 */
void ledplus(u8t Dir) {
	
}


//IR相关
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
*函数名称：void init_timer0(void)
*函数功能：Timer0初始化配置
*入口参数：
*出口参数：
*****************************************************/
void init_timer0(void)
{
	TMOD &= 0xf0;                	//定时器,时钟为系统时钟 12 分频 
									//模式0,TL0 和 TH0 组成 13 位定时器/计数器
    TL0 = (8192-1334) & 0x1F;       //初始值低字节，TL0 的高 3 位是无效的
    TH0 = (8192-1334) >> 5;         //初始值高字节(1ms@16MHz)
								
    ET0 = 1;	//开中断 定时器 0 中断使能控制位
    EA = 1;		//总中断
    TR0 = 1;	//启动定时器

}


/*****************************************************
* 中断服务函数
*****************************************************/
void timer0_isr (void) interrupt 1  
{
    /* set timer0 as mode0 (13-bit) */
    TL0 = (8192-1334) & 0x1F;       //初始值低字节，TL0 的高 3 位是无效的
    TH0 = (8192-1334) >> 5;         //初始值高字节(1ms@16MHz)
	// todo ...
	//P35=~P35;
	if(++intCount >= 10)
	{
			IntFlag = 1;
			intCount = 0;
			if(keyTime > 0)
			{
				--keyTime;
				if(keyTime == 0)
						cleanData();
			}
			if(++count1S >= 100)
			{
					count1S = 0;
					if(deadLock && deadtime)
					{
							if(--deadtime == 0)
							{
								powerOff();
								deadLock = 0;
								deadtime = 0;
							}
					}
			}
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




