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
    int z;
    int *currentPermutation=NULL;
    int currentSize=0;
    int *temporaryPermutation=NULL;
    int temporarySize=0;
    input("%i",&z);
    while(z--)
    {
        int n,i;
        input("%i",&n);
        if(currentSize<n)
        {
            currentSize=n;
            currentPermutation=realloc(currentPermutation,currentSize*sizeof(int));
        }
        for(i=0;i<n;++i)
            input("%i",currentPermutation+i);
        int valueToSwap,positionToSwap=-1;
        for(i=n-1;i>0;--i)
        {
            if(currentPermutation[i-1]<currentPermutation[i])
            {
                // FOUND!
                positionToSwap=i-1;
                valueToSwap=currentPermutation[positionToSwap];
                break;
            }
        }
        if(positionToSwap==-1)
        {
            // BRAK
            output("BRAK\n");
        }
        else
        {
            int newValue=positionToSwap+1;
            for(i=positionToSwap;i<n;++i)
                if(currentPermutation[i]<currentPermutation[newValue] && currentPermutation[i]>valueToSwap)
                    newValue=i;
            int tmp=currentPermutation[newValue];
            currentPermutation[newValue]=currentPermutation[positionToSwap];
            currentPermutation[positionToSwap]=tmp;
            if(temporarySize<n-positionToSwap-1)
            {
                temporarySize=n-positionToSwap-1;
                temporaryPermutation=realloc(temporaryPermutation,temporarySize*sizeof(int));
            }
            for(i=n-1;i>positionToSwap;--i)
                temporaryPermutation[n-i-1]=currentPermutation[i];
            for(i=positionToSwap+1;i<n;++i)
                currentPermutation[i]=temporaryPermutation[i-positionToSwap-1];
            for(i=0;i<n;++i)
                output("%d ",currentPermutation[i]);
            output("\n");
        }
    }
    free(currentPermutation);
    free(temporaryPermutation);
    end();
    return 0;
}
