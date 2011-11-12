// Maciej Poleski
#ifndef DEBUG
#ifndef NDEBUG
#define NDEBUG
#endif
#define init(x,y)
#define end()
#define input(format,...) scanf(format,## __VA_ARGS__)
#define output(format,...) printf(format,## __VA_ARGS__)
#define check(x)
#else
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
FILE *_input=NULL;
FILE *_output=NULL;
bool _initialized=false;
void init(int argc,char**argv)
{
    if(argc!=3)
    {
        fprintf(stderr,"Potrzebne są dwa argumenty <wejście> <wyjście>\n");
        exit(1);
    }
    _input=fopen(argv[1],"r");
    _output=fopen(argv[2],"w");
    _initialized=true;
}
void end(void)
{
    fclose(_input);
    fclose(_output);
}
#define input(format,...) fscanf(_input,format,## __VA_ARGS__)
#define output(format,...) fprintf(_output,format,## __VA_ARGS__)
#define check(x) assert(x)
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>

char command[6];        ///< Polecenie (WRITE|CODE|READ)
char encoded[33];       ///< Postać wejściowa zaszyfrowana @warning BIG-ENDIAN!
char input[34];         ///< Potencjalnie zawiera znak.
char decoded[33];       ///< Liczba zakodowana (C-string).

/**
 * @brief Zamienia ciąg znaków na ciąg liczb [0,15]
 *
 * @param what Ciąg znaków (C-string)
 * @return void
 **/
inline void translateInputToInternal(char * what)
{
    for(;*what;++what)
    {
        if(*what>='0' && *what<='9')
        {
            *what-='0';
        }
        else
        {
            check(*what>='A');
            check(*what<='F');
            *what-=('A'-10);
        }
    }
}

/**
 * @brief Dopełnia ciąg znaków cyframi '0'. Najmniej znacząca cyfra (big-endian)
 * trafi na pozycję what[31]
 *
 * @param what Ciąg znaków ['0','F'] (C-string)
 * @return void
 **/
inline void shiftRight(char* const what)
{
    check(what);
    int p=0;
    while(what[p]) ++p;
    if(p!=32)
    {
        int e=32;
        for(;p>=0;--p,--e)
            what[e]=what[p];
        for(;e>=0;--e)
            what[e]='0';
    }
    check(what[32]==0);
}

/**
 * @brief Dekoduje liczbę w zapisie naturalnym o wskazanej podstawie.
 *
 * @param base Podstawa źródłowego systemu liczbowego.
 * @return int Zdekodowana liczba naturalna.
 **/
inline int decodeAny(int base)
{
    check(encoded[32]==0);
    check(base!=0);
    check(base!=1);
    check(base<=16);
    int result=0;
    int i=0;
    for(;i<32;++i)
    {
        result=result*base+encoded[i];
    }
    return result;
}

/**
 * @brief Neguje liczbę w zapisie binarnym.
 *
 * @param what Wskaźnik na początek ciągu bitów.
 * @param count Ilość bitów do zanegowania.
 * @return void
 **/
inline void neg(char * what,int count)
{
    while(count--)
    {
        *what=(*what==0)?1:0;
        ++what;
    }
}

/**
 * @brief Inkrementuje liczbę w zapisie dwójkowym.
 *
 * @param what Wskaźnik na najmniej znaczący bit w zapisie big-endian.
 * @return void
 **/
inline void inc(char *what)
{
    while(*what==1)
        *what--=0;
    *what=1;
}

/**
 * @brief Dekoduje liczbę w formacie U2 (16 bitową)
 *
 * @return int
 **/
inline int decodeU2()
{
    {
        check(encoded[0]==0);
        check(encoded[1]==0);
        check(encoded[2]==0);
        check(encoded[3]==0);
        check(encoded[4]==0);
        check(encoded[5]==0);
        check(encoded[6]==0);
        check(encoded[7]==0);
        check(encoded[8]==0);
        check(encoded[9]==0);
        check(encoded[10]==0);
        check(encoded[11]==0);
        check(encoded[12]==0);
        check(encoded[13]==0);
        check(encoded[14]==0);
        check(encoded[15]==0);
    }
    check(encoded[32]==0);
    char sign=encoded[32-16];
    if(sign)
    {
        neg(&encoded[32-16],16);
        inc(&encoded[31]);
        //encoded[15]=0;
    }
    int result=decodeAny(2);
    if(sign)
        result=-result;
    return result;
}

/**
 * @brief Parsuje ciąg znaków z tablicy encoded zgodnie z podanym argumentem.
 *
 * @param day Dzień w którym zakodowano liczbę.
 * @return int Zgekodowana liczba.
 **/
inline int decode(int day)
{
    check(day>=1);
    check(day<=31);
    shiftRight(encoded);
    translateInputToInternal(encoded);
    check(encoded[32]==0);
    day%=16;
    if(day==0)
        day=16;
    if(day==1)
        return decodeU2();
    else
        return decodeAny(day);
}

/**
 * @brief Koduje liczbę naturalną do zapisu naturalnego o wskazanej podstawie
 *
 * Format Little-Endian.
 *
 * @param number Wejściowa liczba naturalna.
 * @param base Podstawa docelowego systemu liczbowego.
 * @return char* Zakodowany ciąg cyfr w postaci Little-Endian.
 **/
inline char * encodeToLittleEndianInternal(int number,int base)
{
    check(base!=0);
    check(base!=1);
    check(number>=0);
    static char buffer[33];
    int i=0;
    for(;i<32;++i)
    {
        if(number==0)
            break;
        buffer[i]=number%base;
        number/=base;
    }
    for(;i<=32;++i)
        buffer[i]=0;
    if(number>0)
        buffer[0]=100;
    return buffer;
}

/**
 * @brief Koduje dowolną liczbę całkowitą do zapisu naturalnego z minusem
 * o wskazanej podstawie.
 *
 * @param number Liczba do zakodowania
 * @param base Podstawa docelowego systemu liczbowego.
 * @return void
 **/
inline void encodeAny(int number,int base)
{
    char sign=number<0?'-':'+';
    if(number<0)
        number=-number;
    if(sign=='-')
        output("%c",'-');
    char *internal=encodeToLittleEndianInternal(number,base);
    int i=32;
    for(;i>0;--i)
        if(internal[i])
            break;
    for(;i>=0;--i)
        output("%c",internal[i]<=9?internal[i]+'0':internal[i]+'A'-10);
    output("\n");
}

/**
 * @brief Koduje dowolną liczbę całkowitą do formatu U2 lub wypisuje informację
 * o błędzie.
 *
 * @param number Wejściowa liczba całkowita
 * @return void
 **/
inline void encodeU2(int number)
{
    if(number==-32768)
    {
        output("1000000000000000\n");
        return;
    }
    char sign=number<0?'-':'+';
    if(number<0)
        number=-number;
    char *internal=encodeToLittleEndianInternal(number,2);
    if(internal[0]==100)
    {
        output("ERROR\n");
        return;
    }
    int i=32;
    for(;i>0;--i)
        if(internal[i])
            break;
    if(i>=15)
    {
        output("ERROR\n");
        return;
    }
    int j=0;
    for(;j<=i;++j)
        decoded[31-j]=internal[j];
    for(;j<=15;++j)
        decoded[31-j]=0;
    if(sign=='-')
    {
        neg(&decoded[16],16);
        inc(&decoded[31]);
    }
    for(j=16;j<32;++j)
        output("%c",decoded[j]+'0');
    output("\n");
}

/**
 * @brief Koduje wskazaną liczbę w wskazanym dniu.
 *
 * @param number Liczba całkowita do zakodowania
 * @param day Dzień w którym odbędzie się kodowanie [1,31]
 * @return void
 **/
inline void encode(int number, int day)
{
    day%=16;
    if(day==0)
        day=16;
    if(day==1)
        encodeU2(number);
    else
        encodeAny(number,day);
}

inline void solution(void)
{
    int z;
    input("%i",&z);
    while(z--)
    {
        input("%s",command);
        if(command[0]=='W')
        {
            time_t currentTime=time(NULL);
            int number,day=localtime(&currentTime)->tm_mday;
            input("%i",&number);
            encode(number,day);
        }
        else if(command[0]=='C')
        {
            int number,day;
            input("%i%i",&number,&day);
            encode(number,day);
        }
        else
        {
            // READ
            check(command[0]=='R');
            int day;
            input("%s%i",input,&day);
            if(input[0]=='-')
                strcpy(encoded,input+1);
            else
                strcpy(encoded,input);
            check(day>=1);
            check(day<=31);
            output("%d\n",decode(day)*((input[0]=='-')?-1:1));
        }
    }
}

#ifdef DEBUG

void checkTranslateInputToInternal(void)
{
    char t1[]="1234567890";
    translateInputToInternal(t1);
    check(t1[0]==1);
    check(t1[1]==2);
    check(t1[2]==3);
    check(t1[3]==4);
    check(t1[4]==5);
    check(t1[5]==6);
    check(t1[6]==7);
    check(t1[7]==8);
    check(t1[8]==9);
    check(t1[9]==0);
    check(t1[10]==0); // NULL
    char t2[]="12ABCDEF0A1";
    translateInputToInternal(t2);
    check(t2[0]==1);
    check(t2[1]==2);
    check(t2[2]==10);
    check(t2[3]==11);
    check(t2[4]==12);
    check(t2[5]==13);
    check(t2[6]==14);
    check(t2[7]==15);
    check(t2[8]==0);
    check(t2[9]==10);
    check(t2[10]==1);
    check(t2[11]==0); // NULL
    char t3[]="00100";
    translateInputToInternal(t3);
    check(t3[0]==0);
    check(t3[1]==0);
    check(t3[2]==1);
    check(t3[3]==0);
    check(t3[4]==0);
    check(t3[5]==0); // NULL
}

void checkShiftRight(void)
{
    char t1[33]="123456789";
    char t1R[33]="00000000000000000000000123456789";
    shiftRight(t1);
    check(strcmp(t1,t1R)==0);
    char t2[33]="0A3210020";
    char t2R[33]="000000000000000000000000A3210020";
    shiftRight(t2);
    check(strcmp(t2,t2R)==0);
    char t3[33]="0123456789ABCDEF0123456789ABCDEF";
    char t3R[33]="0123456789ABCDEF0123456789ABCDEF";
    shiftRight(t3);
    check(strcmp(t3,t3R)==0);
}

void checkNeg(void)
{
    char t1[33]="0100";
    char t1R[33]="1011";
    shiftRight(t1);
    shiftRight(t1R);
    translateInputToInternal(t1);
    translateInputToInternal(t1R);
    neg(t1+32-4,4);
    check(memcmp(t1,t1R,32)==0);
}

void checkInc(void)
{
    char t1[33]="0100";
    char t1R[33]="0101";
    shiftRight(t1);
    shiftRight(t1R);
    translateInputToInternal(t1);
    translateInputToInternal(t1R);
    inc(t1+31);
    check(memcmp(t1,t1R,32)==0);
    char t2[33]="0111";
    char t2R[33]="1000";
    shiftRight(t2);
    shiftRight(t2R);
    translateInputToInternal(t2);
    translateInputToInternal(t2R);
    inc(t2+31);
    check(memcmp(t1,t1R,32)==0);
}

void checkDecodeAny(void)
{
    char t1[]="1234567890";
    strcpy(encoded,t1);
    shiftRight(encoded);
    translateInputToInternal(encoded);
    check(decodeAny(10)==1234567890);
    char t2[]="10101011101";
    strcpy(encoded,t2);
    shiftRight(encoded);
    translateInputToInternal(encoded);
    check(decodeAny(2)==0x55d);
    char t3[]="1234567230";
    strcpy(encoded,t3);
    shiftRight(encoded);
    translateInputToInternal(encoded);
    check(decodeAny(8)==01234567230);
    char t4[]="A6401AF2";
    strcpy(encoded,t4);
    shiftRight(encoded);
    translateInputToInternal(encoded);
    check(decodeAny(16)==0xA6401AF2);
}

#include <limits.h>

void checkDecodeU2(void)
{
    {
        char t1[]="0000000000000000";
        strcpy(encoded,t1);
        shiftRight(encoded);
        translateInputToInternal(encoded);
        check(decodeU2()==0);
    }
    {
        char t1[]="0000000000000001";
        strcpy(encoded,t1);
        shiftRight(encoded);
        translateInputToInternal(encoded);
        check(decodeU2()==1);
    }
    {
        char t1[]="1111111111111111";
        strcpy(encoded,t1);
        shiftRight(encoded);
        translateInputToInternal(encoded);
        check(decodeU2()==-1);
    }
    {
        char t1[]="1000000000000000";
        strcpy(encoded,t1);
        shiftRight(encoded);
        translateInputToInternal(encoded);
        check(decodeU2()==SHRT_MIN);
    }
    {
        char t1[]="1111111111111101";
        strcpy(encoded,t1);
        shiftRight(encoded);
        translateInputToInternal(encoded);
        check(decodeU2()==-3);
    }
}

void checkDecode(void)
{
    {
        char t1[]="1234567890";
        strcpy(encoded,t1);
        check(decode(10)==1234567890);
    }
    {
        char t1[]="1234567890";
        strcpy(encoded,t1);
        check(decode(10+16)==1234567890);
    }
    {
        char t1[]="10101011101";
        strcpy(encoded,t1);
        check(decode(2)==0x55d);
    }
    {
        char t1[]="10101011101";
        strcpy(encoded,t1);
        check(decode(2+16)==0x55d);
    }
    {
        char t1[]="1234567230";
        strcpy(encoded,t1);
        check(decode(8)==01234567230);
    }
    {
        char t1[]="1234567230";
        strcpy(encoded,t1);
        check(decode(8+16)==01234567230);
    }
    {
        char t1[]="A6401AF2";
        strcpy(encoded,t1);
        check(decode(16)==0xA6401AF2);
    }
    {
        char t1[]="0000000000000000";
        strcpy(encoded,t1);
        check(decode(1)==0);
    }
    {
        char t1[]="0000000000000000";
        strcpy(encoded,t1);
        check(decode(1+16)==0);
    }
    {
        char t1[]="0000000000000001";
        strcpy(encoded,t1);
        check(decode(1)==1);
    }
    {
        char t1[]="0000000000000001";
        strcpy(encoded,t1);
        check(decode(1+16)==1);
    }
    {
        char t1[]="1111111111111111";
        strcpy(encoded,t1);
        check(decode(1)==-1);
    }
    {
        char t1[]="1111111111111111";
        strcpy(encoded,t1);
        check(decode(1+16)==-1);
    }
    {
        char t1[]="1000000000000000";
        strcpy(encoded,t1);
        check(decode(1)==SHRT_MIN);
    }
    {
        char t1[]="1000000000000000";
        strcpy(encoded,t1);
        check(decode(1+16)==SHRT_MIN);
    }
    {
        char t1[]="1111111111111101";
        strcpy(encoded,t1);
        check(decode(1)==-3);
    }
    {
        char t1[]="1111111111111101";
        strcpy(encoded,t1);
        check(decode(1+16)==-3);
    }
}

void checkEncodeToLittleEndianInternal(void)
{
    int i;
    {
        char *t=encodeToLittleEndianInternal(0,2);
        for(i=0;i<=32;++i)
            check(t[i]==0);
    }
    {
        char *t=encodeToLittleEndianInternal(1,2);
        check(t[0]==1);
        for(i=1;i<=32;++i)
            check(t[i]==0);
    }
    {
        char *t=encodeToLittleEndianInternal(15,16);
        check(t[0]==15);
        for(i=1;i<=32;++i)
            check(t[i]==0);
    }
    {
        char *t=encodeToLittleEndianInternal(16,16);
        check(t[0]==0);
        check(t[1]==1);
        for(i=2;i<=32;++i)
            check(t[i]==0);
    }
    {
        char *t=encodeToLittleEndianInternal(16,10);
        check(t[0]==6);
        check(t[1]==1);
        for(i=2;i<=32;++i)
            check(t[i]==0);
    }
    {
        char *t=encodeToLittleEndianInternal(15,2);
        check(t[0]==1);
        check(t[1]==1);
        check(t[2]==1);
        check(t[3]==1);
        for(i=4;i<=32;++i)
            check(t[i]==0);
    }
}

#endif // DEBUG

int main(int argc,char**argv)
{
    #ifdef DEBUG
    init(argc,argv);
    checkTranslateInputToInternal();
    checkShiftRight();
    checkNeg();
    checkInc();
    checkDecodeAny();
    checkDecodeU2();
    checkDecode();
    checkEncodeToLittleEndianInternal();
    #endif // DEBUG
    solution();
#ifdef DEBUG
    end();
#endif // DEBUG
    return 0;
}