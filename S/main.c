// Maciej Poleski
#ifndef DEBUG
#ifndef NDEBUG
#define NDEBUG
#endif
#define init(x,y)
#define end()
#define check(x)
#else
#include <stdio.h>
#include <stdlib.h>
void init(int argc,char**argv)
{
    if(argc!=3)
    {
        fprintf(stderr,"Potrzebne są dwa argumenty <wejście> <wyjście>\n");
        exit(1);
    }
    freopen(argv[1],"r",stdin);
    freopen(argv[2],"w",stdout);
}
void end(void)
{
}
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
#include <stdarg.h>
#include <math.h>

inline char * iToA(int number)
{
    static char buffer[256];
    buffer[255]='\0';
    if(number==0)
    {
        buffer[254]='0';
        return buffer+254;
    }
    int i;
    for(i=254;number;--i)
    {
        buffer[i]='0'+number%10;
        number/=10;
    }
    return &buffer[i+1];
}

inline char * fToA(double number)
{
    static char buffer[256];
    buffer[255]='\0';
    int i;
    number+=0.0005;
    char *f=iToA((int)floor(number));
    int len=strlen(f);
    char *ptr=buffer+250;
    for(;len;)
    {
        *ptr--=f[--len];
    }
    buffer[251]='.';
    number-=floor(number);
    number*=1000;
    f=iToA((int)floor(number));
    len=strlen(f);
    buffer[254]=len>0?f[--len]:'0';
    buffer[253]=len>0?f[--len]:'0';
    buffer[252]=len>0?f[--len]:'0';
    return ptr+1;
}

inline bool isSpaceOrEOF(int c)
{
    return isspace(c) || c==EOF;
}

inline void skipWhiteSpace(void)
{
    char c;
    while(isSpaceOrEOF(c=getchar()));
    if(c!=EOF)
        ungetc(c,stdin);
}

inline char * readSingleWord(void)
{
    skipWhiteSpace();
    static char buffer[256];
    char *ptr=buffer;
    while(!isSpaceOrEOF(*ptr++=getchar()));
    if(*--ptr!=EOF)
        ungetc(*ptr,stdin);
    *ptr='\0';
    return buffer;
}

inline void myPrintf(const char *format,...)
{
    va_list ap;
    va_start(ap,format);
    for(;*format;++format)
    {
        char *s;
        switch(*format)
        {
            case '%':
                switch(*++format)
                {
                    case '%':
                        putchar('%');
                        break;
                    case 'd':
                        myPrintf("%s",iToA(va_arg(ap,int)));
                        break;
                    case 'f':
                        myPrintf("%s",fToA(va_arg(ap,double)));
                        break;
                    case 's':
                        s=va_arg(ap,char*);
                        while(*s)
                            putchar(*s++);
                        break;
                    default:
                        check(false);
                        break;
                }
                break;
            default:
                putchar(*format);
                break;
        }
    }
    va_end(ap);
}

void myScanf(const char *format,...)
{
    va_list ap;
    va_start(ap,format);
    for(;*format;++format)
    {
        switch(*format)
        {
            case '%':
                switch(*++format)
                {
                    case 'd':
                        *(va_arg(ap,int*))=atoi(readSingleWord());
                        break;
                    case 'f':
                        *(va_arg(ap,double*))=atof(readSingleWord());
                        break;
                    case 's':
                        strcpy(va_arg(ap,char*),readSingleWord());
                        break;
                    default:
                        check(false);
                        break;
                }
                break;
            default:
                check(false);
                break;
        }
    }
    va_end(ap);
}

double *A;
double *B;
double *C;

inline void solution(void)
{
    A=malloc(200000*sizeof(double));
    B=malloc(200000*sizeof(double));
    C=malloc(200000*sizeof(double));
    int z;
    myScanf("%d",&z);
    while(z--)
    {
        char command[20];
        myScanf("%s",command);
        if(*command=='U')
        {
            check(strcmp("UNION",command)==0);
            int n,m;
            double *Aptr=A;
            myScanf("%d",&n);
            int i;
            for(i=0;i<n;++i)
                myScanf("%f",A+i);
            myScanf("%d",&m);
            i=0;
            myPrintf("Zbior:");
            double last=-1.0;
            while(m--)
            {
                double M;
                myScanf("%f",&M);
                for(;i<n && A[i]<M;++i)
                {
                    if(fabs(A[i]-last)>=0.001)
                    {
                        last=A[i];
                        myPrintf(" %f",last);
                    }
                }
                if(fabs(M-last)>=0.001)
                {
                    last=M;
                    myPrintf(" %f",last);
                }
            }
            for(;i<n;++i)
            {
                if(fabs(A[i]-last)>=0.001)
                {
                    last=A[i];
                    myPrintf(" %f",last);
                }
            }
            myPrintf("\n");
        }
        else
        {
            check(strcmp("INTERSECTION",command)==0 || strcmp("INTERSECION",command)==0);
            int n,m;
            myScanf("%d",&n);
            int i;
            for(i=0;i<n;++i)
                myScanf("%f",A+i);
            myScanf("%d",&m);
            for(i=0;i<m;++i)
                myScanf("%f",B+i);
            int Csize=0;
            int aI=0;
            int bI=0;
            while(aI<n && bI<m)
            {
                if(A[aI]-B[bI]>=0.001)
                    ++bI;
                else if(B[bI]-A[aI]>=0.001)
                    ++aI;
                else
                {
                    C[Csize++]=A[aI];
                    while(aI+1<n && A[aI+1]-A[aI]<0.001)
                        ++aI;
                    ++aI;
                }
            }
            if(Csize==0)
                myPrintf("Zbior pusty\n");
            else
            {
                myPrintf("Zbior:");
                int i;
                for(i=0;i<Csize;++i)
                    myPrintf(" %f",C[i]);
                myPrintf("\n");
            }
        }
    }
    free(A);
    free(B);
    free(C);
}

#ifdef DEBUG

inline void checkIToA(void)
{
    check(strcmp("123",iToA(123))==0);
    check(strcmp("0",iToA(0))==0);
    check(strcmp("1",iToA(1))==0);
    check(strcmp("999",iToA(999))==0);
    check(strcmp("123456",iToA(123456))==0);
    check(strcmp("77",iToA(77))==0);
    check(strcmp("10",iToA(10))==0);

}

inline void checkFToA(void)
{
    check(strcmp("123.000",fToA(123.0))==0);
    check(strcmp("0.000",fToA(0.0))==0);
    check(strcmp("1.000",fToA(1.0))==0);
    check(strcmp("1.001",fToA(1.001))==0);
    check(strcmp("9999.999",fToA(9999.999))==0);
    check(strcmp("100.999",fToA(100.9994))==0);
    check(strcmp("101.000",fToA(100.9995))==0);

}

inline void checkAll(void)
{
    checkIToA();
    checkFToA();
}

#endif // DEBUG

int main(int argc,char**argv)
{
#ifdef DEBUG
    init(argc,argv);
    checkAll();
#endif // DEBUG
    solution();
#ifdef DEBUG
    end();
#endif // DEBUG
    return 0;
}
