
#ifndef __USER_H
#define __USER_H
#include "WS51F7030.h"
#include "intrins.h"
#include "nvr.h"

#define u8t		unsigned char
#define	u16t	unsigned int
	
//IR模块
//1?? 16us
//???????????0ms,??????4.5ms
#define HeadCont_H 6020     //4.9ms
#define HeadCont_L 12015       //4.9ms
#define FootCont_L 12015      //9ms
 
//????1????0.45ms+???0.08ms
#define OneCode_H 2258        //420us
#define OneCode_L 765        //120us
 
//??0?????0.21ms+???0.3ms
#define Zero_H 785  		//170us
#define Zero_L 720  		//340us
 
//????
#define FaultTolerant 300
#define FaultTolerantX 4

#define IR P35

u8t	bdata Status = 0;
u16t T1Counter;
u16t accTimeH = 0;
u8t	intCount = 0;
u8t IntFlag = 0;
u8t bitIndex;
u8t data1,data2,data3,data4;	
u8t irCode,irCode2;
u8t value;
u8t sleepFlag = 0;
u8t	keyTime = 0;
u8t	lowTime = 0;


sbit ZeroCode = Status^0;           //?????0
sbit OneCode = Status^1;            //?????1
sbit MaybeRemoteStart = Status^2;   //????????
sbit RemoteStart = Status^3;        //????????
sbit ReadOver = Status^4;           //????
sbit INT1Level = Status^5;           //1?????? 0??????
sbit	DOFlag = Status^6;		//DO??

void setLow();
void setHight();
void GetOneByte(u8t bitNub);
void proData();
void keyCallBack();
void cleanData();
void proLow();
void proHight();

//RGB
#define LED_N 4
#define LED_O 	27
#define LED_OP 	51
#define LED_OPE 	74
#define LED_OPEN 	106
#define LED_HL 	37
#define DUTYMAX  20	
u8t duty = 20;

#define PB3 P32		//???
#define PA7 P34		//???
#define PA0 P11		//???


#define	NUB1() do{			\
	PB3 = 0;		\
	_nop_();					\
	_nop_();					\
	PB3 = 1;		\
	_nop_();					\
	_nop_();					\
	_nop_();					\
}							\
while(0)			

#define	NUB0() do{			\
	PB3 = 0;		\
	_nop_();					\
	_nop_();					\
	PB3 = 1;		\
	_nop_();					\
	PB3 = 0;		\
	_nop_();					\
	_nop_();					\
}							\
while(0)

#define	NUB21() do{			\
	PA7 = 0;		\
	_nop_();					\
	_nop_();					\
	PA7 = 1;		\
	_nop_();					\
	_nop_();					\
	_nop_();					\
}							\
while(0)			

#define	NUB20() do{			\
	PA7 = 0;		\
	_nop_();					\
	_nop_();					\
	PA7 = 1;		\
	_nop_();					\
	PA7 = 0;		\
	_nop_();					\
	_nop_();					\
}							\
while(0)

#define	NUB31() do{			\
	PA0 = 0;		\
	_nop_();					\
	_nop_();					\
	PA0 = 1;		\
	_nop_();					\
	_nop_();					\
	_nop_();					\
}							\
while(0)			

#define	NUB30() do{			\
	PA0 = 0;		\
	_nop_();					\
	_nop_();					\
	PA0 = 1;		\
	_nop_();					\
	PA0 = 0;		\
	_nop_();					\
	_nop_();					\
}							\
while(0)
	
#define BLACK 0x00,0x00,0x00
#define RED 0xFF,0x00,0x00
#define COLOR2 236,95,0
#define COLOR3 243,151,0
#define COLOR4 251,200,0
#define COLOR5 196,216,64
#define GREEN 0x00,0xFF,0x00
#define COLOR7 0,162,97
#define COLOR8 0,175,132
#define COLOR9 108,189,101
#define COLOR10 0,105,147
#define BLUE 0x00,0x00,0xFF
#define COLOR12 0,110,183
#define COLOR13 58,130,197
#define COLOR14 0,146,201
#define COLOR15 206,127,154
#define WHITE 0xFF,0xFF,0xFF

u8t	bdata Rdata = 0x00;
u8t	bdata Gdata = 0x00;
u8t	bdata Bdata = 0x00;

u8t	Rdata1 = 0x00;
u8t	Gdata1 = 0x00;
u8t	Bdata1 = 0x00;

sbit R7 = Rdata^7;
sbit R6 = Rdata^6;
sbit R5 = Rdata^5;
sbit R4 = Rdata^4;
sbit R3 = Rdata^3;
sbit R2 = Rdata^2;
sbit R1 = Rdata^1;
sbit R0 = Rdata^0;

sbit G7 = Gdata^7;
sbit G6 = Gdata^6;
sbit G5 = Gdata^5;
sbit G4 = Gdata^4;
sbit G3 = Gdata^3;
sbit G2 = Gdata^2;
sbit G1 = Gdata^1;
sbit G0 = Gdata^0;

sbit B7 = Bdata^7;
sbit B6 = Bdata^6;
sbit B5 = Bdata^5;
sbit B4 = Bdata^4;
sbit B3 = Bdata^3;
sbit B2 = Bdata^2;
sbit B1 = Bdata^1;
sbit B0 = Bdata^0;

struct RGB
{
		u8t red; 
		u8t green; 
		u8t blue;
};

typedef struct RGB SRGB;

struct RGB code rgbs[17] = {{BLACK},{RED},{COLOR2},{COLOR3},{COLOR4},{COLOR5},{GREEN},{COLOR7},{COLOR8},{COLOR9},{COLOR10},{BLUE},{COLOR12},{COLOR13},{COLOR14},{COLOR15},{WHITE}};
//void initRGBArray();

//void initRGB(unsigned char colorR,unsigned char colorG,unsigned char colorB,struct RGB rgb);
void sendtoLast2(SRGB srgb,char index,unsigned char ledCount);
void sendtoLast(unsigned char colorR,unsigned char colorG,unsigned char colorB,char index,unsigned char ledCount);
void sendRGB(unsigned char colorR,unsigned char colorG,unsigned char colorB);
void sendRGB2(unsigned char colorR,unsigned char colorG,unsigned char colorB);
void sendRGB3(unsigned char colorR,unsigned char colorG,unsigned char colorB);
void Delay80us();
void breath3(unsigned char *data1,unsigned char *data2,unsigned char *data3,char index);


//ctr

#define NVR1_START_ADDR 0X00
#define SECTOR_SIZE 4
unsigned char rbuf[SECTOR_SIZE]={0};
unsigned char buf[SECTOR_SIZE]={0};

u8t workStep = 0;	//0为关机 1为三色常亮模式	2为灯带全彩流水	3为等带跑马流水 4多单色移动 5整体流水模式
u8t colorStep = 0;//0红色
u8t starFlag = 0;//0无白色随机爆闪 1 有白色爆闪
u8t allIncStep = 0;//10种整体模式

u16t deadtime = 0;		//定时关机
u8t deadLock = 0;			//定时锁
u8t count1S = 0;
u8t	keyCount = 0;//消抖计数
u8t longPressFlag = 0;

void init_timer0(void);
void init_timer1(void);
void writeNvr();
void powerOff();
void powerOn();
void workCtr();
char keyRead(char keyStatus);
//3路灯显示同一种颜色
void showSingleColor();		


#endif