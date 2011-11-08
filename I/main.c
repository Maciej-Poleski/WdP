// Maciej Poleski
#ifndef DEBUG
#ifndef NDEBUG
#define NDEBUG
#endif
#define init(x,y)
#define end()
#define input(format,...) scanf(format,## __VA_ARGS__)
#define output(format,...) printf(format,## __VA_ARGS__)
#define assertE(x)
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
#define assertE(x) assert(x)
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

int main(int argc,char**argv)
{
    init(argc,argv);
    int z,i;
    input("%i",&z);
    char *storage=malloc(1000000*11*sizeof(char));
    char **a=malloc(1000000*sizeof(char*));
    char **b=malloc(1000000*sizeof(char*));
    uint_fast32_t *count=malloc(('Z'+1)*sizeof(uint_fast32_t));
    for(i=0;i<1000000;++i)
    {
        a[i]=&storage[11*i];
    }
    while(z--)
    {
        int n,j;
        input("%i",&n);
        memset(storage,0,n*11*sizeof(char));
        for(i=0;i<n;++i)
        {
            input("%s%*s",a[i]);
        }
        for(i=9;i>=0;--i)
        {
            memset(count,0,('Z'+1)*sizeof(uint_fast32_t));
            for(j=0;j<n;++j)
            {
                assertE(a[j]);
                assertE(a[j][i]== 0 || (a[j][i]>='A' && a[j][i]<='Z'));
                ++count[a[j][i]];
            }
            for(j=1;j<='Z';++j)
            {
                assertE(j-1>=0);
                assertE(j<='Z');
                count[j]+=count[j-1];
            }
            for(j=n-1;j>=0;--j)
            {
                assertE(a[j]);
                b[--count[a[j][i]]]=a[j];
            }
            for(j=1;j<n;++j)
            {
                assertE(b[j-1]);
                assertE(b[j]);
                assertE(b[j-1][i]<=b[j][i]);
            }
            void *t=a;
            a=b;
            b=t;
        }
        for(i=0;i<n;++i)
        {
            static int count=1;
            if(i<n-1 && strcmp(a[i],a[i+1])==0)
                ++count;
            else
            {
                output("%s %d\n",a[i],count);
                count=1;
            }
        }
    }
    free(storage);
    free(a);
    free(b);
    free(count);
    end();
    return 0;
}
