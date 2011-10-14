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

int main(int argc,char**argv)
{
    init(argc,argv);
    const uint_fast32_t maxPrime=10000001;
    uint_fast32_t i,j;
    uint32_t *numbers=malloc(maxPrime*sizeof(uint32_t));
    for(i=2; i<maxPrime; ++i)
        numbers[i]=1;
    numbers[0]=numbers[1]=0;
    for(i=2; ((long long)i)*i<=maxPrime; ++i)
    {
        if(numbers[i]==0)
            continue;
        for(j=i*i; j<maxPrime; j+=i)
        {
            numbers[j]=0;
        }
    }
    for(i=1; i<maxPrime; ++i)
        numbers[i]+=numbers[i-1];
    int z;
    input("%i",&z);
    while(z--)
    {
        int a,b;
        input("%i%i",&a,&b);
        output("%d\n",numbers[b]-numbers[a-1]);
    }
    free(numbers);
    end();
    return 0;
}
