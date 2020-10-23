
/*********************************************************
*Copyright (C), 2020-2030, 深圳前海维晟智能技术有限公司
*文件名:	nvr.c
*作  者:	
*版  本:	V1.00
*日  期:	20200418
*描  述:	
*备  注:     
**********************************************************/
#include	"WS51F7030.h"

#define NVR_UNLOCK 					0x78
#define NVR_WRITE 					0x82
#define NVR_ERASE 					0x83
#define NVR_LOCK 					0x87
#define NVR_READ 					0x81


void EraseNVR(unsigned short SectorAddr)
{
	//1  Flash unlock
	FSFLG=NVR_UNLOCK;

	//2  write address
	FSADRL=(SectorAddr&0xff);
	FSADRH=((SectorAddr>>8)&0xff);
	//3  Flash erase cmd
	FSCMD=NVR_ERASE;
	//4 NVR lock
	FSFLG=NVR_LOCK;
}

void WriteDataNVR(unsigned char *buf,unsigned short SectorAddr,unsigned short len)
{
	unsigned char i=0;
	//1  Flash unlock
	FSFLG=NVR_UNLOCK;
	//2  Flash  write cmd
	FSCMD=NVR_WRITE;	
	for(i=0;i<len;++i)
	{
		//3  write address		
		FSADRL=(SectorAddr&0xff);
		FSADRH=((SectorAddr>>8)&0xff);
		SectorAddr++;
		//4 write data
		FSDAT=buf[i];
	}
	//4 NVR lock
	FSFLG=NVR_LOCK;
}

void readDatafromNVR(unsigned char *buf,unsigned short SectorAddr,unsigned short len)
{
	unsigned char i=0;
	//1  read cmd
	FSCMD=NVR_READ;
	for(i=0;i<len;++i)
	{
		//2  write address		
		FSADRL=(SectorAddr&0xff);
		FSADRH=((SectorAddr>>8)&0xff);
		++SectorAddr;
		//3 read data
		buf[i]=FSDAT;
	}
}












