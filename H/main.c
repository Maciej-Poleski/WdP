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

typedef struct
{
    char name[16];
    char upperName[16];
    int s;
    double f;
} Employee;

inline bool lt(Employee *l,Employee *r)
{
    return l->f < r->f || (l->f == r->f && l->s > r->s) ||
    (l->f == r->f && l->s == r->s && strcmp(l->upperName,r->upperName)>0);
}

int main(int argc,char**argv)
{
    init(argc,argv);
    int z,i;
    input("%i",&z);
    Employee *storage=malloc(100000*sizeof(Employee));
    while(z--)
    {
        int n;
        input("%i",&n);
        for(i=0;i<n;++i)
        {
            input("%s%i%lf",&storage[i].name[0],&storage[i].s,&storage[i].f);
            char *s=&storage[i].name[0];
            char *d=&storage[i].upperName[0];
            while(*s) *d++=toupper(*s++);
            *d=0;
        }
        for(i=0;i<n;++i)
        {
            Employee *b=storage+i;
            int j;
            for(j=i;j<n;++j)
            {
                if(lt(b,storage+j))
                    b=storage+j;
            }
            Employee t=*b;
            *b=storage[i];
            storage[i]=t;
        }
        for(i=0;i<n;++i)
            output("%s %d %.3lf\n",storage[i].name,storage[i].s,storage[i].f);
    }
    free(storage);
    end();
    return 0;
}
