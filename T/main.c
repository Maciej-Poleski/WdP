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

typedef struct node_t
{
    char name[9];
    struct node_t *next;
} Node;

Node *head=NULL;

inline void insert(Node *node, int where) __attribute__((nonnull));
inline void prepend(Node *node) __attribute__((nonnull,artificial));
inline void append(Node *node) __attribute__((nonnull,artificial));
inline bool removeNode(const char *name) __attribute__((nonnull));

inline void deleteList(void)
{
    Node *node=head;
    while(node!=NULL)
    {
        Node *next=node->next;
        free(node);
        node=next;
    }
    head=NULL;
}

inline void insert(Node *node, int where)
{
    check(node!=NULL);
    if(head==NULL)
    {
        head=node;
        node->next=NULL;
        return;
    }
    Node **i=&head;
    while((*i!=NULL) && (where !=1))
    {
        --where;
        i=&((*i)->next);
    }
    node->next=*i;
    *i=node;
}

inline void prepend(Node *node)
{
    insert(node,1);
}

inline void append(Node *node)
{
    insert(node,0);
}

inline void dump(void)
{
    if(head==NULL)
    {
        printf("PUSTY\n");
        return;
    }
    Node *i;
    for(i=head;i!=NULL;i=i->next)
    {
        printf("%s ",i->name);
    }
    printf("\n");
}

inline void reverse(void)
{
    if(head==NULL)
        return;
    Node *i=head->next;
    head->next=NULL;
    Node *next;
    while(i!=NULL)
    {
        next=i->next;
        prepend(i);
        i=next;
    }
}

inline bool removeNode(const char *name)
{
    if(head==NULL)
        return false;
    Node **i=&head;
    while(*i!=NULL)
    {
        if(strcmp(name,(*i)->name)==0)
        {
            Node *t=*i;
            *i=t->next;
            free(t);
            return true;
        }
        i=&((*i)->next);
    }
    return false;
}

inline bool move(int i,int j)
{
    if(i<=0)
        return false;
    if(head==NULL)
        return false;
    Node **it=&head;
    for(;i!=1;--i)
    {
        it=&((*it)->next);
        if(*it==NULL)
            return false;
    }
    Node *t=*it;
    *it=t->next;
    insert(t,j);
    return true;
}

inline void solution(void)
{
    int z;
    scanf("%d",&z);
    while(z--)
    {
        deleteList();
        int n;
        scanf("%d",&n);
        while(n--)
        {
            char command[10];
            int i,j;
            char name[9];
            Node *handle;
            scanf("%s",command);
            switch(*command)
            {
                case 'G':
                    check(strcmp(command,"GORA")==0);
                    scanf("%s",name);
                    handle=malloc(sizeof(Node));
                    strcpy(handle->name,name);
                    append(handle);
                    break;
                case 'D':
                    switch(command[2])
                    {
                        case 'L':
                            check(strcmp(command,"DOL")==0);
                            scanf("%s",name);
                            handle=malloc(sizeof(Node));
                            strcpy(handle->name,name);
                            prepend(handle);
                            break;
                        case 'D':
                            check(strcmp(command,"DODAJ")==0);
                            scanf("%s%d",name,&i);
                            handle=malloc(sizeof(Node));
                            strcpy(handle->name,name);
                            insert(handle,i);
                            break;
                        default:
                            check(false);
                            break;
                    }
                    break;
                case 'U':
                    check(strcmp(command,"USUN")==0);
                    scanf("%s",name);
                    if(removeNode(name)==false)
                        printf("BLAD %s\n",name);
                    break;
                case 'Z':
                    check(strcmp(command,"ZMIEN")==0);
                    scanf("%d%d",&i,&j);
                    if(!move(i,j))
                        printf("BLAD %d\n",i);
                    break;
                case 'O':
                    check(strcmp(command,"ODWROC")==0);
                    reverse();
                    break;
                case 'W':
                    check(strcmp(command,"WYPISZ")==0);
                    dump();
                    break;
                case 'K':
                    check(strcmp(command,"KONIEC")==0);
                    deleteList();
                    break;
                default:
                    check(false);
                    break;
            }
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
