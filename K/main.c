// Maciej Poleski
#ifndef DEBUG
#ifndef NDEBUG
#define NDEBUG
#endif
#define init(x,y)
#define end()
#define input(format,...) scanf(format,## __VA_ARGS__)
#define output(format,...) printf(format,## __VA_ARGS__)
#define inchar() getchar()
#define outchar(x) putchar((x))
#define uninchar(x) ungetc((x),stdin)
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
#define inchar() getc(_input)
#define outchar(x) putc((x),_output)
#define check(x) assert(x)
#define uninchar(x) ungetc((x),_input)
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

inline long long Npow(long long a,long long n)
{
    if(n<=0)
        return 1;
    if(n&1)
        return a*Npow(a,n&(~(1ull)));
    long long r=Npow(a,n>>1);
    return r*r;
}

int priority[256];

long long values['z'+1];        ///< Wartości kolejnych zmiennych a..z
char *stack,*topStack;
long long *computer,*topComputer;

inline void solution(void)
{
    priority['+']=priority['-']=0;
    priority['*']=priority['/']=1;
    priority['^']=2;
    priority['(']=-1;   ///< HACK
    stack=topStack=malloc(sizeof(char)*100000);
    computer=topComputer=malloc(sizeof(long long)*100000);
    int z;
    input("%i",&z);
    while(z--)
    {
        int i='a';
        for(; i<='z'; ++i)
            input("%lli",&values[i]);
        int n;
        input("%i",&n);
        while(n--)
        {
            {
                char t;
                while(true)
                {
                    t=inchar();
                    if(t==' ' || t=='\n' || t=='\t' || t=='\r')
                        continue;
                    uninchar(t);
                    break;
                }
            }
            check(topStack==stack);
            check(topComputer==computer);
            while(true)
            {
                char c=inchar();
                if(c=='(')
                {
                    *topStack++=c;
                }
                else if(c==')')
                {
                    char a;
                    while((a=*--topStack)!='(')
                    {
                        outchar(a);
                        long long x=*--topComputer;
                        long long y=*--topComputer;
                        long long z;
                        if(a=='+')
                            z=x+y;
                        else if(a=='-')
                            z=y-x;
                        else if(a=='*')
                            z=y*x;
                        else if(a=='/')
                            z=(x==0)?0:y/x;
                        else
                        {
                            check(a=='^');
                            z=Npow(y,x);    // Npow sprawdza argumenty
                        }
                        *topComputer++=z;
                    }
                }
                else if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
                {
                    char a;
                    while(topStack>stack && priority[*(topStack-1)]>=priority[c])
                    {
                        a=*--topStack;
                        outchar(a);
                        long long x=*--topComputer;
                        long long y=*--topComputer;
                        long long z;
                        if(a=='+')
                            z=x+y;
                        else if(a=='-')
                            z=y-x;
                        else if(a=='*')
                            z=y*x;
                        else if(a=='/')
                            z=(x==0)?0:y/x;
                        else
                        {
                            check(a=='^');
                            z=Npow(y,x);    // Npow sprawdza argumenty
                        }
                        *topComputer++=z;
                    }
                    *topStack++=c;
                }
                else if(c>='a' && c<='z')
                {
                    outchar(c);
                    *topComputer++=values[c];
                }
                else
                {
                    check(c=='\n' || c==' ' || c=='\t' || c=='\r' || c==EOF);
                    char a;
                    while(topStack>stack)
                    {
                        a=*--topStack;
                        outchar(a);
                        long long x=*--topComputer;
                        long long y=*--topComputer;
                        long long z;
                        if(a=='+')
                            z=x+y;
                        else if(a=='-')
                            z=y-x;
                        else if(a=='*')
                            z=y*x;
                        else if(a=='/')
                            z=(x==0)?0:y/x;
                        else
                        {
                            check(a=='^');
                            z=Npow(y,x);    // Npow sprawdza argumenty
                        }
                        *topComputer++=z;
                    }
                    break;
                }
            }
            output("\n%lld\n",*--topComputer);
        }
    }
    free(stack);
    free(computer);
}

#ifdef DEBUG

inline void checkNPow(void)
{
    check(Npow(0,0)==1);
    check(Npow(2,0)==1);
    check(Npow(2,-1)==1);
    check(Npow(1,3)==1);
    check(Npow(2,1)==2);
    check(Npow(2,2)==4);
    check(Npow(2,3)==8);
    check(Npow(2,4)==16);
    check(Npow(3,1)==3);
    check(Npow(3,2)==9);
    check(Npow(3,3)==27);
    check(Npow(3,7)==3*3*3*3*3*3*3);
}

#endif // DEBUG

int main(int argc,char**argv)
{
#ifdef DEBUG
    init(argc,argv);
    checkNPow();
#endif // DEBUG
    solution();
#ifdef DEBUG
    end();
#endif // DEBUG
    return 0;
}
