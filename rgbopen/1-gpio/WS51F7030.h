#ifndef __WS51F7030_H
#define __WS51F7030_H
sfr SP          = 0x81;
sfr DP0L        = 0x82;
sfr DP0H        = 0x83;
sfr DP1L        = 0x84;
sfr DP1H        = 0x85;
sfr SCCON       = 0x86;
sfr PCON        = 0x87;
sfr TCON        = 0x88;
sfr TMOD        = 0x89;
sfr TL0         = 0x8a;
sfr TL1         = 0x8b;
sfr TH0         = 0x8c;
sfr TH1         = 0x8d;

sfr P1          = 0x90;
sfr HRCON       = 0x96;
sfr LRCON       = 0x97;
sfr S0CON       = 0x98;
sfr S0BUF       = 0x99;
sfr S0CFG       = 0x9a;
sfr RSTFLG      = 0x9f;

sfr I2CCON      = 0xa1;
sfr I2CADR      = 0xa2;
sfr I2CFG0      = 0xa3;
sfr I2CFG1      = 0xa4;
sfr I2CTXD      = 0xa5;
sfr I2CRXD      = 0xa6;
sfr I2CFLG      = 0xa7;
sfr IE          = 0xa8;
sfr WDTCON      = 0xa9;
sfr WDTFLG      = 0xaa;

sfr P3          = 0xb0;
sfr DACON       = 0xb1;
sfr IP          = 0xb8;
sfr LVDCON      = 0xb9;

sfr T2CON       = 0xc8;
sfr T2MOD       = 0xc9;
sfr T2CL        = 0xca;
sfr T2CH        = 0xcb;
sfr TL2         = 0xcc;
sfr TH2         = 0xcd;

sfr PSW         = 0xd0;
sfr WKTCON      = 0xd1;
sfr EPIE        = 0xd8;
sfr EPIF        = 0xd9;
sfr EP0CON      = 0xda;
sfr EP1CON      = 0xdb;

sfr ACC         = 0xe0;
sfr PCOMS       = 0xE4;
sfr PDRVS       = 0xE5;
sfr TKMXF0      = 0xe9;
sfr TKMXF1      = 0xea;
sfr TKMNF0      = 0xec;
sfr TKMNF1      = 0xed;

sfr B           = 0xf0;
sfr TKCON       = 0xf1;
sfr TKCFG0      = 0xf2;
sfr TKCFG1      = 0xf3;
sfr TKNUM       = 0xf4;
sfr TKFLG0      = 0xf5;
sfr TKFLG1      = 0xf6;

sfr PWCON       = 0xf9;
sfr IT0CON      = 0xfa;
sfr IT1CON      = 0xfb;
sfr IDLF        = 0xfc;
sfr STPF        = 0xfe;



extern xdata unsigned char P10F	   ;
extern xdata unsigned char P11F	   ;
extern xdata unsigned char P12F	   ;
extern xdata unsigned char P13F	   ;
extern xdata unsigned char P14F	   ;
extern xdata unsigned char P15F	   ;
extern xdata unsigned char P16F	   ;
extern xdata unsigned char P17F	   ;
extern xdata unsigned char P30F	   ;
extern xdata unsigned char P31F	   ;
extern xdata unsigned char P32F	   ;
extern xdata unsigned char P33F	   ;
extern xdata unsigned char P34F	   ;
extern xdata unsigned char P35F	   ;

extern xdata unsigned char PWMEN    ;
extern xdata unsigned char PWMIE 	 ;
extern xdata unsigned char PWMFLG	 ;

extern xdata unsigned char PWM0CFG 	;
extern xdata unsigned char PWM0DUTL	;
extern xdata unsigned char PWM0DUTH	;
extern xdata unsigned char PWM0DIVL	;
extern xdata unsigned char PWM0DIVH	;
extern xdata unsigned char PWM1DUTL	;
extern xdata unsigned char PWM1DUTH	;
extern xdata unsigned char PWM1DIVL	;
extern xdata unsigned char PWM1DIVH	;

extern xdata unsigned char PWM2CFG 	;
extern xdata unsigned char PWM2DUTL	;
extern xdata unsigned char PWM2DUTH	;
extern xdata unsigned char PWM2DIVL	;
extern xdata unsigned char PWM2DIVH	;
extern xdata unsigned char PWM3DUTL	;
extern xdata unsigned char PWM3DUTH	;
extern xdata unsigned char PWM3DIVL	;
extern xdata unsigned char PWM3DIVH	;

extern xdata unsigned char PWM4CFG 	;
extern xdata unsigned char PWM4DUTL	;
extern xdata unsigned char PWM4DUTH	;
extern xdata unsigned char PWM4DIVL	;
extern xdata unsigned char PWM4DIVH	;
extern xdata unsigned char PWM5DUTL	;
extern xdata unsigned char PWM5DUTH	;
extern xdata unsigned char PWM5DIVL	;
extern xdata unsigned char PWM5DIVH	;

extern xdata unsigned char TKPCS0	 ;
extern xdata unsigned char TKPCS1	 ;
extern xdata unsigned char TKPCS2	 ;

extern xdata unsigned char TK0MXL   ;
extern xdata unsigned char TK0MXH   ;
extern xdata unsigned char TK1MXL   ;
extern xdata unsigned char TK1MXH   ;
extern xdata unsigned char TK2MXL   ;
extern xdata unsigned char TK2MXH   ;
extern xdata unsigned char TK3MXL   ;
extern xdata unsigned char TK3MXH   ;
extern xdata unsigned char TK4MXL   ;
extern xdata unsigned char TK4MXH   ;
extern xdata unsigned char TK5MXL   ;
extern xdata unsigned char TK5MXH   ;
extern xdata unsigned char TK6MXL   ;
extern xdata unsigned char TK6MXH   ;
extern xdata unsigned char TK7MXL   ;
extern xdata unsigned char TK7MXH   ;
extern xdata unsigned char TK8MXL   ;
extern xdata unsigned char TK8MXH   ;
extern xdata unsigned char TK9MXL   ;
extern xdata unsigned char TK9MXH   ;
extern xdata unsigned char TK10MXL  ;
extern xdata unsigned char TK10MXH  ;
extern xdata unsigned char TK11MXL  ;
extern xdata unsigned char TK11MXH  ;

extern xdata unsigned char TK0MNL 	;
extern xdata unsigned char TK0MNH 	;
extern xdata unsigned char TK1MNL 	;
extern xdata unsigned char TK1MNH 	;
extern xdata unsigned char TK2MNL 	;
extern xdata unsigned char TK2MNH 	;
extern xdata unsigned char TK3MNL 	;
extern xdata unsigned char TK3MNH 	;
extern xdata unsigned char TK4MNL 	;
extern xdata unsigned char TK4MNH 	;
extern xdata unsigned char TK5MNL 	;
extern xdata unsigned char TK5MNH 	;
extern xdata unsigned char TK6MNL 	;
extern xdata unsigned char TK6MNH 	;
extern xdata unsigned char TK7MNL 	;
extern xdata unsigned char TK7MNH 	;
extern xdata unsigned char TK8MNL 	;
extern xdata unsigned char TK8MNH 	;
extern xdata unsigned char TK9MNL 	;
extern xdata unsigned char TK9MNH 	;
extern xdata unsigned char TK10MNL	;
extern xdata unsigned char TK10MNH	;
extern xdata unsigned char TK11MNL	;
extern xdata unsigned char TK11MNH	;

extern xdata unsigned char TK0MSL  ;
extern xdata unsigned char TK0MSH  ;
extern xdata unsigned char TK1MSL  ;
extern xdata unsigned char TK1MSH  ;
extern xdata unsigned char TK2MSL  ;
extern xdata unsigned char TK2MSH  ;
extern xdata unsigned char TK3MSL  ;
extern xdata unsigned char TK3MSH  ;
extern xdata unsigned char TK4MSL  ;
extern xdata unsigned char TK4MSH  ;
extern xdata unsigned char TK5MSL  ;
extern xdata unsigned char TK5MSH  ;
extern xdata unsigned char TK6MSL  ;
extern xdata unsigned char TK6MSH  ;
extern xdata unsigned char TK7MSL  ;
extern xdata unsigned char TK7MSH  ;
extern xdata unsigned char TK8MSL  ;
extern xdata unsigned char TK8MSH  ;
extern xdata unsigned char TK9MSL  ;
extern xdata unsigned char TK9MSH  ;
extern xdata unsigned char TK10MSL ;
extern xdata unsigned char TK10MSH ;
extern xdata unsigned char TK11MSL ;
extern xdata unsigned char TK11MSH ;

extern xdata unsigned char LSCON  	;
extern xdata unsigned char LSCFG  	;
extern xdata unsigned char LSDTM0 	;
extern xdata unsigned char LSDTM1 	;
extern xdata unsigned char LSPTM0 	;
extern xdata unsigned char LSPTM1 	;
extern xdata unsigned char LSCOM  	;

extern xdata unsigned char LSPE0 	;
extern xdata unsigned char LSPE1 	;
extern xdata unsigned char LSDAT0	;
extern xdata unsigned char LSDAT1	;

extern xdata unsigned char MECON 	;
extern xdata unsigned char FSCMD 	;
extern xdata unsigned char BTMSK 	;
extern xdata unsigned char FSDAT 	;
extern xdata unsigned char FSFLG 	;
extern xdata unsigned char PADR 	;
extern xdata unsigned char FSADRL	;
extern xdata unsigned char FSADRH	;

extern xdata unsigned char CKSUML 	;
extern xdata unsigned char CKSUMH 	;
extern xdata unsigned char IDCODE0	;
extern xdata unsigned char IDCODE1	;
extern xdata unsigned char IDCODE2	;

extern xdata unsigned char CHIPIDL	;
extern xdata unsigned char CHIPIDH	;
 
    
sbit P10 = P1^0;
sbit P11 = P1^1;
sbit P12 = P1^2;
sbit P13 = P1^3;
sbit P14 = P1^4;
sbit P15 = P1^5;
sbit P16 = P1^6;
sbit P17 = P1^7;

sbit P30 = P3^0;
sbit P31 = P3^1;
sbit P32 = P3^2;
sbit P33 = P3^3;
sbit P34 = P3^4;
sbit P35 = P3^5;

/* 中断优先级寄存器 IP (B8H) */
sbit PX4 = IP^6;		/* INT4 优先级控制位，用于 Touch Key/WDT/LVD/WKT/EP1 中断 */
sbit PX3 = IP^5;		/* INT3 优先级控制位， 用于 IIC/Timer2/PWM/EP0 中断 */
sbit PX2 = IP^4;		/* INT2 优先级控制位，用于 UART0 中断 */
sbit PT1 = IP^3;		/* Timer 1 优先级控制位 */
sbit PX1 = IP^2;		/* INT1 优先级控制位 */
sbit PT0 = IP^1;		/* Timer 0 优先级控制位 */
sbit PX0 = IP^0;		/* INT0 优先级控制位 */

/* 中断使能寄存器 IE (A8H) */
sbit EA = 	 IE^7;		/* 全局中断使能控制位 */
sbit EINT3 = IE^6;		/* 用于 Touch Key/WDT/LVD/WKT/EP1 中断 */
sbit EINT2 = IE^5;		/* 用于 IIC/Timer2/PWM/EP0 中断 */
sbit ES0 = IE^4;		/* UART0 中断 */
sbit ET1 = 	 IE^3;		/* 定时器 1 中断使能控制位 */
sbit EINT1 = IE^2;		/* 中断 1 使能控制位（中断 1 用于外部中断 1） */
sbit ET0 = 	 IE^1;		/* 定时器 0 中断使能控制位 */
sbit EINT0 = IE^0;		/* 0 使能控制位（中断 0 用于外部中断 0） */


/* 外部中断使能寄存器 EPIE (D8H) */
//sbit EP3IE = EPIE^3;		/* EP3 中断使能信号 */
//sbit EP2IE = EPIE^2;		/* EP2 中断使能信号 */
sbit EP1IE = EPIE^1;		/* EP1 中断使能信号 */
sbit EP0IE = EPIE^0;		/* EP0 中断使能信号 */


/* 串口UART0寄存器 S0CON (98H) */
sbit SM00 = S0CON^7;	/* 串口 0 模式选择位， */
sbit SM10 = S0CON^6;	/* 串口 0 模式选择位， */
sbit SM20 = S0CON^5;	/* 多机通信使能位， 1 有效 */
sbit REN0 = S0CON^4;	/* 串行接收使能位， 1 有效 */
sbit TB80 = S0CON^3;	/* 发送的第 9 位数据 */
sbit RB80 = S0CON^2;	/* 接收的第 9 位数据 */
sbit TI0 = 	S0CON^1;	/* 发送中断标志， 1 有效，写 0 清除 */
sbit RI0 =  S0CON^0;	/* 接收中断标志， 1 有效，写 0 清除 */

/* 定时器0/1 TCON (88H) */
sbit TF1 = TCON^7;		/* 定时器 0 模式 3 的 TH0 溢出/定时器 1 溢出标志位，中断被响应后自动清 0. */
sbit TR1 = TCON^6;		/* 定时器 1 运行控制位， 1 有效 */
sbit TF0 = TCON^5;		/* 定时器 0 溢出标志位，中断被响应后自动清 0 */
sbit TR0 = TCON^4;		/* 定时器 0 运行控制位， 1 有效 */
sbit IE1 = TCON^3;		/* 外部中断 1 使能位， 1 有效 */
sbit IT1 = TCON^2;		/* 外部中断 1 触发类型控制位 */
sbit IE0 = TCON^1;		/* 外部中断 0 使能位， 1 有效 */
sbit IT0 = TCON^0;		/* 外部中断 0 触发类型控制位 */

/* 定时器2 T2CON (C8H) */
sbit TF2 =   T2CON^7;		/* 定时器 2 溢出标志位。 当 RCLK 或 TCLK 为 1， TF2 不会被置 1 */
sbit EXF2 =  T2CON^6;		/* T2EX 触发标志。 */
sbit RCLK =  T2CON^5;		/* UART0 在模式 1 和 3 时使用定时器 1/2 作为接收波特率时钟 */
sbit TCLK =  T2CON^4;		/* UART0 在模式 1 和 3 时使用定时器 1/2 作为发送波特率时钟 */
sbit EXEN2 = T2CON^3;		/* T2EX 使能信号，在定时器没有作为 UART0 时钟时 T2EX 有效 */
sbit TR2 =   T2CON^2;		/* 定时器 2 启动信号， 1 有效 */
sbit CT2 =   T2CON^1;		/* 定时功能或计数功能选择信号 */
sbit CPRL2 = T2CON^0;		/* 抓取或重载功能选择信号。当 RCLK 或 TCLK 为 1 时，定时器强制进入 Timer 2 重载模式 */



#define ROR_8BIT(X,Y) ((X<<(8-Y))|(X>>Y))
#define ROL_8BIT(X,Y) ((X>>(8-Y))|(X<<Y)) 
typedef 	unsigned char	u8;
typedef 	unsigned int	u16;
typedef 	unsigned long	u32;
typedef 	signed char	s8;
typedef 	signed int	s16;
typedef 	signed long	s32;

typedef     unsigned char   uint8_t;
typedef     unsigned int    uint16_t;
typedef     unsigned long   uint32_t;

typedef     signed char     int8_t;
typedef     signed int      int16_t;
typedef     signed long     int32_t;
#endif