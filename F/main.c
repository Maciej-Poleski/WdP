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

int main(int argc,char**argv)
{
    init(argc,argv);
    int z;
    input("%i",&z);
    int *input=NULL;
    int size=0;
    while(z--)
    {
        int n,i,j,k;
        input("%i",&n);
        if(size<n)
        {
            size=n;
            input=realloc(input,size*sizeof(int));
        }
        for(i=0;i<n;++i)
            input("%i",input+i);
        // BUBBLE SORT
        for(i=0;i<n-1;++i)
        {
            // i - najbardziej lewy element podlegający wpływowi algorytmu
            uint_fast32_t swapCount=0;
            for(j=n-2;j>=i;--j)
            {
                if(input[j]>input[j+1])
                {
                    ++swapCount;
                    int t=input[j];
                    input[j]=input[j+1];
                    input[j+1]=t;
                }
            }
            if(swapCount==0)
                break;
            output("%d ",input[i]);
        }
        for(;i<n;++i)
            output("%d ",input[i]);
        output("\n");
        // BUBBLE SORT
        // a+b+c=0
        bool found=false;
        for(i=0;i<n;++i)
        {
            j=0,k=n-1;
            while(j<=k)
            {
                if(input[i]+input[j]+input[k]==0)
                {
                    found=true;
                    output("TAK %d %d %d\n",i,j,k);
                    break;
                }
                else if(input[i]+input[j]+input[k]<0)
                {
                    ++j;
                }
                else
                {
                    --k;
                }
            }
            if(found)
                break;
        }
        if(!found)
        {
            output("NIE\n");
        }
        // a+b+c=0
    }
    free(input);
    end();
    return 0;
}
