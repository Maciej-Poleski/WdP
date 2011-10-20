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

int *seq=NULL;

uint_fast32_t binarySearch(uint_fast32_t b,uint_fast32_t e,int q)
{
    while(e>b+1)
    {
        uint_fast32_t s=(b+e)/2;
        if(seq[s]>q)
        {
            e=s;
        }
        else
        {
            b=s;
        }
    }
    return b;
}

#ifdef TWEAK_BS

int main(int argc,char**argv)
{
    init(argc,argv);
    int z;
    input("%i",&z);
    int seqSize=0;
    while(z--)
    {
        int n,i,q;
        input("%i",&n);
        if(seqSize<n)
        {
            seqSize=n;
            seq=realloc(seq,seqSize*sizeof(int));
        }
        for(i=0;i<n;++i)
            input("%i",seq+i);
        for(i=0;i<n;++i)
        {
            output("%3d",i);
        }
        output("\n");
        for(i=0;i<n;++i)
        {
            output("%3d",seq[i]);
        }
        output("\n");
        for(i=0;i<n;++i)
        {
            output("%3u",(unsigned int)binarySearch(0,n,seq[i]));
        }
        output("%3u%3u%3u\n",(unsigned int)binarySearch(0,n,seq[n-1]+1),
               (unsigned int)binarySearch(0,n,0),
               (unsigned int)binarySearch(0,n,seq[0]-1)
        );
    }
    free(seq);
    end();
    return 0;
}

#else

int main(int argc,char**argv)
{
    init(argc,argv);
    int z;
    input("%i",&z);
    int seqSize=0;
    while(z--)
    {
        int n,i,q;
        input("%i",&n);
        if(seqSize<n+2)
        {
            seqSize=n+2;
            seq=realloc(seq,seqSize*sizeof(int));
        }
        seq[0]=INT_MIN;
        seq[n+1]=INT_MAX;
        for(i=1;i<=n;++i)
            input("%i",seq+i);
        input("%i",&q);
        for(i=0;i<q;++i)
        {
            int s;
            input("%i",&s);
            uint_fast32_t r=binarySearch(0,n+2,s);
            if(seq[r]==s)
            {
                uint_fast32_t l=binarySearch(0,n+2,s-1);
                output("%u\n",(unsigned int)r-l);       // Źle to wygląda
            }
            else
            {
                output("0\n");
            }
        }
    }
    free(seq);
    end();
    return 0;
}
#endif
