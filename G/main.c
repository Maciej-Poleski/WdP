// Maciej Poleski
#ifndef DEBUG
#ifndef NDEBUG
#define NDEBUG
#endif
#define init(x,y)
#define end()
#define input(format,...) scanf(format,## __VA_ARGS__)
#define output(format,...) printf(format,## __VA_ARGS__)
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
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

int main(int argc,char**argv)
{
    init(argc,argv);
    int z,i;
    char *storage=malloc(10000*151*2*sizeof(char));
    char **input=malloc(10000*sizeof(char*));
    char **upperCase=malloc(10000*sizeof(char*));
    for(i=0;i<10000;++i)
    {
        input[i]=&storage[i*151];
        upperCase[i]=&storage[10000*151+i*151];
    }
    input("%i",&z);
    while(z--)
    {
        int n;
        input("%i",&n);
        for(i=0;i<n;++i)
            input("%s",input[i]);
        for(i=0;i<n;++i)
        {
            char *s=input[i];
            char *d=upperCase[i];
            while(*s) *d++=toupper(*s++);
            *d=0;
        }
        for(i=1;i<n;++i)
        {
            char *inputS=input[i];
            char *upperS=upperCase[i];
            int j=i;
            while(strcmp(upperCase[j-1],upperS)>0)
            {
                input[j]=input[j-1];
                upperCase[j]=upperCase[j-1];
                if(--j==0)
                    break;
            }
            upperCase[j]=upperS;
            input[j]=inputS;
        }
        for(i=0;i<n;++i)
            output("%s ",input[i]);
        output("\n");
    }
    free(storage);
    free(input);
    free(upperCase);
    end();
    return 0;
}
