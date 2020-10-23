
/*********************************************************
*Copyright (h), 2020-2030, 深圳前海维晟智能技术有限公司
*文件名:	nvr.h
*作  者:	
*版  本:	V1.00
*日  期:	20200418
*描  述:	
*备  注:     
**********************************************************/
#ifndef __NVR_H
#define __NVR_H

void EraseNVR(unsigned short SectorAddr);

void WriteDataNVR(unsigned char *buf,unsigned short SectorAddr,unsigned short len);

void readDatafromNVR(unsigned char *buf,unsigned short SectorAddr,unsigned short len);


#endif 











