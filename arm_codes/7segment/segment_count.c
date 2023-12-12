
#include<lpc214x.h>
/*
#include"TYPES.h"
#include"DELAY.h"
*#include"DEFINES1.h"*/

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void delay_ms(unsigned int);

#define SETBIT(WORD,BITPOS) (WORD|=(1<<BITPOS))
#define CLRBIT(WORD,BITPOS) (WORD&=~(1<<BITPOS))
#define WRITEBYTE(WORD,BITPOS,BYTE) (WORD=(WORD&~(255<<BITPOS))|((BYTE)<<BITPOS))

#define CA7SEGMUX 0

#define SEL1 16
#define SEL2 17

const u8 seg_lut[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90}; //{0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67 };

int main()
{
u8 i,j;
WRITEBYTE(IODIR0,CA7SEGMUX,0XFF);
SETBIT(IODIR1,SEL1);
SETBIT(IODIR1,SEL2);

while(1)
{
	for(i=0;i<100;i++)
	{
		for(j=0;j<100;j++)
		{
    WRITEBYTE(IOPIN0,CA7SEGMUX,seg_lut[j/10]);
		//	IOPIN0 |=0Xff;                         
		//	IOPIN0 ^=seg_lut[j/10];               //logic for using cathode value
    SETBIT(IOSET1,SEL1);
    delay_ms(1);
    SETBIT(IOCLR1,SEL1);
    WRITEBYTE(IOPIN0,CA7SEGMUX,seg_lut[j%10]);
		//	IOPIN0 |=0Xff;
		//	IOPIN0 ^=seg_lut[j%10];
    SETBIT(IOSET1,SEL2);
    delay_ms(1);
    SETBIT(IOCLR1,SEL2); 
}
	
}
}
}
void delay_ms(unsigned int count)
{
 unsigned int i,j;
 for(j=0;j<count;j++)
 {
 for(i=0;i<300000;i++);
 }
}
