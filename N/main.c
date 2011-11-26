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
    _input=fopen(argv<:1:>,"r");
    _output=fopen(argv<:2:>,"w");
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

typedef uint16_t number;
typedef uint32_t code;
code bits[128];
char decodeBits[32];
char command[8];
char *textToEncode;
number *textEncoded;
char *textDecoded;

inline void solution(void)
{
    int z;
    textToEncode=malloc(sizeof(char)*3001);
    textEncoded=malloc(sizeof(number)*940);
    textDecoded=malloc(sizeof(char)*3001);
    input("%i",&z);
    while(z--)
    {
        char c;
        for(c='A';c<='Z';++c)
        {
            input("%u",&bits[c]);
            decodeBits[bits[c]]=c;
        }
        input("%u",&bits['.']);
        decodeBits[bits['.']]='.';
        int n;
        input("%i",&n);
        while(n--)
        {
            input("%s",command);
            if(*command=='K')
            {
                input("%s",textToEncode);
                int c=0,l=0;
                number *place=textEncoded;
                code buffer=0U;
                uint8_t position=31U;
                for(;textToEncode[l];++l)
                {
                    check(position>=16);
                    buffer|=bits[textToEncode[l]]<<(position-4);
                    position-=5;
                    if(position<16)
                    {
                        *place=(number)(buffer>>16);
                        buffer<<=16;
                        position+=16;
                        c+=__builtin_popcount((code)(*place));
                        ++place;
                    }
                }
                if(position!=31)
                {
                    *place=(number)(buffer>>16);
                    c+=__builtin_popcount((code)(*place));
                    ++place;
                }
                output("%d %d",l,c);
                number *ptr;
                for(ptr=textEncoded;ptr!=place;++ptr)
                    output(" %hu",*ptr);
                output("\n");
            }
            else
            {
                check(*command=='D');
                int l,c;
                input("%d%d",&l,&c);
                code buffer=0U;
                uint8_t position=15U;
                char *place=textDecoded;
                for(;l>0;--l)
                {
                    if(position<=19)
                    {
                        input("%hu",(number*)(&buffer));
                    }
                    code oneCharacter=(buffer>>(position-4))&((1<<5)-1);
                    *place++=decodeBits[oneCharacter];
                    c-=__builtin_popcount(oneCharacter);
                    if(position<=19)
                    {
                        buffer<<=16;
                        position+=16;
                    }
                    position-=5;
                }
                if(c==0)
                {
                    char *ptr=textDecoded;
                    for(;ptr!=place;++ptr)
                    {
                        outchar(*ptr);
                    }
                    outchar('\n');
                }
                else
                {
                    output("BLAD KONTROLI\n");
                }
            }
        }
    }
    free(textToEncode);
    free(textEncoded);
    free(textDecoded);
}

#ifdef DEBUG

inline checkAll(void)
{

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
