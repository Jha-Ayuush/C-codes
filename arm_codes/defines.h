#define SETBIT(WORD,BIT) (WORD |=1<<BIT)
#define SSETBIT(WORD,BIT) (WORD =1<<BIT)
#define SCLRBIT(WORD,BIT) (WORD =1<<BIT)
#define CLRBIT(WORD,BIT) (WORD &=~(1<<BIT))
#define CPLBIT(WORD,BIT) (WORD ^=1<<BIT)
#define READBIT(WORD,BIT) ((WORD>>BIT) &1)
#define WRITEBIT(WORD,BITPOS,BIT) WORD=((WORD&~(1<<BITPOS) | (BIT<<BITPOS)))
#define WRITENIBBLE(WORD,BITPOS,NIBBLE) WORD=(((WORD& ~(15<<BITPOS))) | (NIBBLE<<BITPOS) )
#define WRITEBYTE(WORD,BITPOS,BYTE) WORD=(((WORD& ~(255<<BITPOS))) | (BYTE<<BITPOS) )
