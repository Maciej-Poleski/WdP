// Maciej Poleski
#ifndef DEBUG
#define NDEBUG
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

int main(int argc,char**argv)
{
    init(argc,argv);
    int z;
    input("%i",&z);
    while(z--)
    {
        int n,m,i;
        input("%i%i",&n,&m);
        int *tab=malloc(n*sizeof(int));
        for(i=0;i<n;++i)
            input("%i",tab+i);

        for(i=0;i<m;++i)
        {
            int operation,left,right;
            int *source,*destination;
            input("%i",&operation);
            switch(operation)
            {
                case 1:
                    input("%i%i",&left,&right);
                    source=destination=tab;
                    while(source<tab+n)
                    {
                        if(*source==left)
                        {
                            ++source;
                        }
                        else
                        {
                            *destination++=*source++;
                        }
                    }
                    while(destination<tab+n)
                    {
                        *destination++=right;
                    }
                    break;
                case 2:
                    input("%i%i",&left,&right);
                    destination=tab;
                    source=tab+left;
                    while(source<tab+n)
                    {
                        *destination++=*source++;
                    }
                    while(destination<tab+n)
                    {
                        *destination++=right;
                    }
                    break;
                case 3:
                    input("%i%i",&left,&right);
                    source=tab+n-left;
                    destination=tab+n;
                    while(source>tab)
                    {
                        *--destination=*--source;
                    }
                    while(destination>tab)
                    {
                        *--destination=right;
                    }
                    break;
                default:
                    source=tab;
                    while(source<tab+n)
                        output("%d ",*source++);
                    output("\n");
                    break;
            }
        }
        free(tab);
    }
    end();
    return 0;
}