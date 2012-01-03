// Maciej Poleski
#ifndef DEBUG
#ifndef NDEBUG
#define NDEBUG
#endif
#define init(x,y)
#define end()
#define check(x)
#else
#include <stdio.h>
#include <stdlib.h>
void init(int argc,char**argv)
{
    if(argc!=3)
    {
        fprintf(stderr,"Potrzebne są dwa argumenty <wejście> <wyjście>\n");
        exit(1);
    }
    freopen(argv[1],"r",stdin);
    freopen(argv[2],"w",stdout);
}
void end(void)
{
}
#define check(x) assert(x)
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
#include <stdarg.h>
#include <math.h>

typedef struct
{
    int left,right;
    long long value;
} Node;

Node *tree;

void nadsumuj(int v, long long value)
{
    if(v==0)
        return;
    tree[v].value+=value;
    nadsumuj(tree[v].left,tree[v].value);
    nadsumuj(tree[v].right,tree[v].value);
}

long long podsumuj(int v)
{
    if(v==0)
        return 0LL;
    return tree[v].value+=podsumuj(tree[v].left)+podsumuj(tree[v].right);
}

void preorder(int v)
{
    if(v==0)
        return;
    printf("%lld ",tree[v].value);
    preorder(tree[v].left);
    preorder(tree[v].right);
}

void inorder(int v)
{
    if(v==0)
        return;
    inorder(tree[v].left);
    printf("%lld ",tree[v].value);
    inorder(tree[v].right);
}

void postorder(int v)
{
    if(v==0)
        return;
    postorder(tree[v].left);
    postorder(tree[v].right);
    printf("%lld ",tree[v].value);
}

void bfs(int v)
{
    int *queue=malloc(sizeof(int)*2000000);
    int *begin=queue;
    int *end=queue;
    *end++=v;
    while(begin!=end)
    {
        v=*begin++;
        printf("%lld ",tree[v].value);
        if(tree[v].left!=0)
            *end++=tree[v].left;
        if(tree[v].right!=0)
            *end++=tree[v].right;
    }
    printf("\n");
    free(queue);
}

#ifdef DEBUG

#else

#endif

inline void solution(void)
{
    tree=malloc(sizeof(Node)*2000000);
    int z;
    scanf("%d",&z);
    while(z--)
    {
        int n;
        scanf("%d",&n);
        int i;
        for(i=1;i<=n;++i)
        {
            int l,r;
            long long v;
            scanf("%lld%d%d",&v,&l,&r);
            tree[i].value=v;
            tree[i].left=l;
            tree[i].right=r;
        }
        char first[10];
        char second[10];
        scanf("%s%s",first,second);
        if(*first=='N')
        {
            check(strcmp(first,"NADSUMUJ")==0);
            nadsumuj(1,0LL);
        }
        else
        {
            check(strcmp(first,"PODSUMUJ")==0);
            podsumuj(1);
        }
        switch(second[1])
        {
            case 'R':
                check(strcmp(second,"PREORDER")==0);
                preorder(1);
                printf("\n");
                break;
            case 'N':
                check(strcmp(second,"INORDER")==0);
                inorder(1);
                printf("\n");
                break;
            case 'O':
                check(strcmp(second,"POSTORDER")==0);
                postorder(1);
                printf("\n");
                break;
            default:
                check(strcmp(second,"BFS")==0);
                bfs(1);
                break;
        }
    }
}

#ifdef DEBUG

inline void checkAll(void)
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

