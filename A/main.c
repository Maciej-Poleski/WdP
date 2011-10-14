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
    const uint_fast32_t maxPrime=1000000;
    uint_fast32_t i,j,primesCount=0;
    bool *numbers=calloc(maxPrime,sizeof(bool));
    uint_fast32_t *primes, *pptr;
    for(i=2;((long long)i)*i<=maxPrime;++i)
    {
        if(numbers[i])
            continue;
        for(j=i*i;j<maxPrime;j+=i)
        {
            numbers[j]=true;
        }
    }
    for(i=2;i<maxPrime;++i)
        if(numbers[i]==false)
            ++primesCount;
    pptr=primes=malloc(primesCount*sizeof(uint_fast32_t));
    for(i=2;pptr<primes+primesCount;++i)
    {
        if(numbers[i]==false)
            *pptr++=i;
    }
    numbers[0]=numbers[1]=true;
    int z;
    input("%i",&z);
    while(z--)
    {
        int n;
        uint_fast8_t result=0;
        input("%i",&n);
        for(i=0;i<primesCount && primes[i]*primes[i]<=n;++i)
            if(n%primes[i]==0)
            {
                while(n%primes[i]==0)
                    n/=primes[i];
                ++result;
            }
        if(result>0)
        {
            if(numbers[n]==false)
                ++result;
            output("%d\n",result);
        }
        else
            output("%d jest liczba pierwsza\n",n);
    }
    free(primes);
    free(numbers);
    end();
    return 0;
}
