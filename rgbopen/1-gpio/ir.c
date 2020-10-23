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
	TL1 = (8192-8192) & 0x1F;       //��ʼֵ���ֽڣ�TL0 �ĸ� 3 λ����Ч��
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
	TL1 = (8192-8192) & 0x1F;       //��ʼֵ���ֽڣ�TL0 �ĸ� 3 λ����Ч��
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
*�������ƣ�void init_timer1(void)
*�������ܣ�Timer1��ʼ������
*��ڲ�����
*���ڲ�����
*****************************************************/
void init_timer1(void)
{
	TMOD &= 0x0f;                	//��ʱ��,ʱ��Ϊϵͳʱ�� 12 ��Ƶ 
									//ģʽ0,TL1 �� TH1 ��� 13 λ��ʱ��/������
    TL1 = (8192-41) & 0x1F;       //��ʼֵ���ֽڣ�TL1 �ĸ� 3 λ����Ч��
    TH1 = (8192-41) >> 5;         //��ʼֵ���ֽ�(1ms@16MHz)
								
    ET1 = 1;	//���ж� ��ʱ�� 1 �ж�ʹ�ܿ���λ
    EA = 1;		//���ж�
    TR1 = 1;	//������ʱ��
}


/*****************************************************
* �жϷ�����
*****************************************************/
void timer1_isr (void) interrupt 3  
{
    /* set timer1 as mode0 (13-bit) */
    TL1 = (8192-8192) & 0x1F;       //��ʼֵ���ֽڣ�TL0 �ĸ� 3 λ����Ч��
    TH1 = (8192-8192) >> 5;         //��ʼֵ���ֽ�(1ms@16MHz)
	// todo ...
		++accTimeH;
		//P35=~P35;
}