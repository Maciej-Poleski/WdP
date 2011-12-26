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
    long long coefficient;
    long long exponent;
    struct node_t *next;
    struct node_t *back;
} Node;

Node frontGuard['Z'-'A'+3];
Node backGuard['Z'-'A'+3];

inline void removeNode(Node *node) __attribute__((nonnull,artificial));
inline void add(char id1,char id2) __attribute__((artificial));

#ifdef DEBUG

inline void checkNotGuard(Node *node) __attribute__((nonnull,artificial));
inline void checkList(char id);

#else

#define checkNotGuard(x)
#define checkList(x)

#endif

inline void print_asc(const char id)
{
    Node *i=frontGuard[id-'A'].next;
    const Node * const e=&backGuard[id-'A'];
    if(i!=e)
    {
        printf(i->exponent==0?"%lld":"%lldx^%lld",i->coefficient,i->exponent);
        i=i->next;
        for(; i!=e; i=i->next)
        {
            printf(i->exponent==0?"%+lld":"%+lldx^%lld",i->coefficient,i->exponent);
        }
        printf("\n");
    }
    else
        printf("EMPTY\n");
}

inline void print_desc(const char id)
{
    Node *i=backGuard[id-'A'].back;
    const Node * const e=&frontGuard[id-'A'];
    if(i!=e)
    {
        printf(i->exponent==0?"%lld":"%lldx^%lld",i->coefficient,i->exponent);
        i=i->back;
        for(; i!=e; i=i->back)
        {
            printf(i->exponent==0?"%+lld":"%+lldx^%lld",i->coefficient,i->exponent);
        }
        printf("\n");
    }
    else
        printf("EMPTY\n");
}

inline void removeNode(Node *node)
{
    checkNotGuard(node);
    check(node!=NULL);
    node->back->next=node->next;
    node->next->back=node->back;
    free(node);
}

inline void derivative(const char id)
{
    Node *i=frontGuard[id-'A'].next;
    const Node * const e=&backGuard[id-'A'];
    for(; i!=e; i=i->next)
    {
        i->coefficient*=i->exponent;
        --(i->exponent);
    }
    i=frontGuard[id-'A'].next;
    if(i!=e && i->coefficient==0)
    {
        removeNode(i);
    }
}

inline void add_mono(char id, long long a, long long b)
{
    printf("ADD OK\n"); // Z góry wiem że się uda
    if(b==0)
        return;
    Node *i=frontGuard[id-'A'].next;
    const Node * const e=&backGuard[id-'A'];
    for(; i!=e; i=i->next)
    {
        if(i->exponent<a)
            continue;
        else if(i->exponent==a)
        {
            i->coefficient+=b;
            if(i->coefficient==0)
            {
                removeNode(i);
            }
            return; // Nie można wrócić do pętli, iterator może być uszkodzony
        }
        else
        {
            break; // Kod poniżej
        }
    }
    Node *n=malloc(sizeof(Node));
    n->coefficient=b;
    n->exponent=a;
    n->next=i;
    n->back=i->back;
    n->next->back=n;
    n->back->next=n;
}

inline void addSilent(char id1, char id2)
{
    Node *i=frontGuard[id1-'A'].next;
    const Node * const ei=&backGuard[id1-'A'];
    Node *j=frontGuard[id2-'A'].next;
    const Node * const ej=&backGuard[id2-'A'];
    while(i!=ei && j!=ej)
    {
        if(i->exponent<j->exponent)
            i=i->next;
        else if(i->exponent==j->exponent)
        {
            i->coefficient+=j->coefficient;
            j=j->next;
            if(i->coefficient==0)
            {
                Node *n=i->next;
                removeNode(i);
                i=n; // Naprawiam iterator
            }
            else
                i=i->next;
        }
        else
        {
            Node *n=malloc(sizeof(Node));
            n->coefficient=j->coefficient;
            n->exponent=j->exponent;
            n->next=i;
            n->back=i->back;
            n->next->back=n;
            n->back->next=n;
            j=j->next;
        }
    }
    while(j!=ej)
    {
        Node *n=malloc(sizeof(Node));
        n->coefficient=j->coefficient;
        n->exponent=j->exponent;
        n->next=i;
        n->back=i->back;
        n->next->back=n;
        n->back->next=n;
        j=j->next;
    }
}

inline void add(char id1,char id2)
{
    printf("ADD OK\n"); // Z góry wiem że się uda
    addSilent(id1,id2);
}

inline void cleanSilent(char id)
{
    Node *i=frontGuard[id-'A'].next;
    const Node * const e=&backGuard[id-'A'];
    while(i!=e)
    {
        Node *n=i->next;
        free(i);
        i=n;
    }
    frontGuard[id-'A'].next=&backGuard[id-'A'];
    backGuard[id-'A'].back=&frontGuard[id-'A'];
}

inline void multi_const(char id,long long a)
{
    printf("MULTI OK\n"); // Z góry wiem że się uda
    if(a==0)
        cleanSilent(id);
    else if(a==1)
        return;
    else
    {
        Node *i=frontGuard[id-'A'].next;
        const Node * const e=&backGuard[id-'A'];
        for(; i!=e; i=i->next)
        {
            i->coefficient*=a;
        }
    }
}

inline bool isEmpty(char id)
{
    return frontGuard[id-'A'].next==&backGuard[id-'A'];
}

inline int length(char id)
{
    const Node *i=frontGuard[id-'A'].next;
    const Node * const ei=&backGuard[id-'A'];
    int len=0;
    for(;i!=ei;i=i->next)
        ++len;
    return len;
}

inline void multi(char id1,char id2)
{
    printf("MULTI OK\n"); // Z góry wiem że się uda
    if(isEmpty(id2))
    {
        cleanSilent(id1);
        return;
    }
    if(isEmpty(id1))
        return;
    static const char mono_mul_poly='Z'-'A'+1;
    static const char poly_mul_poly='Z'-'A'+2;
    /* Wprowadzam heurystyczne optymalizacje. Niech len(1)<len(2) */
    int len1 = length(id1);
    int len2=length(id2);
    if(len1>len2)
    {
        char t=id1;
        id1=id2;
        id2=t;
    }
    const Node *i=frontGuard[id1-'A'].next;
    const Node * const ei=&backGuard[id1-'A'];
    for(; i!=ei; i=i->next)
    {
        const Node *j=frontGuard[id2-'A'].next;
        const Node * const ej=&backGuard[id2-'A'];
        for(; j!=ej; j=j->next)
        {
            Node *n=malloc(sizeof(Node));
            n->coefficient=i->coefficient*j->coefficient;
            n->exponent=i->exponent+j->exponent;
            n->back=backGuard[mono_mul_poly].back;
            n->back->next=n;
            backGuard[mono_mul_poly].back=n;
        }
        backGuard[mono_mul_poly].back->next=&backGuard[mono_mul_poly];
        addSilent(poly_mul_poly+'A',mono_mul_poly+'A');
        cleanSilent(mono_mul_poly+'A');
    }
    if(len1>len2)
    {
        char t=id1;
        id1=id2;
        id2=t;
    }
    cleanSilent(id1);
    addSilent(id1,poly_mul_poly+'A');
    cleanSilent(poly_mul_poly+'A');
}

inline void min(char id)
{
    if(isEmpty(id))
        printf("ERROR\n");
    else
        printf("%lld\n",frontGuard[id-'A'].next->coefficient);
}

inline void max(char id)
{
    if(isEmpty(id))
        printf("ERROR\n");
    else
        printf("%lld\n",backGuard[id-'A'].back->coefficient);
}

inline void clean(char id)
{
    if(isEmpty(id))
        printf("EMPTY\n");
    else
    {
        printf("CLEAN OK\n");
        cleanSilent(id);
    }
}

inline void solution(void)
{
    {
        char a;
        for(a=0; a<='Z'-'A'+2; ++a)
        {
            frontGuard[a].next=&backGuard[a];
            frontGuard[a].back=NULL;
            backGuard[a].back=&frontGuard[a];
            backGuard[a].next=NULL;
            frontGuard[a].coefficient=frontGuard[a].exponent=backGuard[a].coefficient=backGuard[a].exponent=-1L;
        }
    }
    int z;
    scanf("%d",&z);
    while(z--)
    {
        {
            char a;
            for(a='A'; a<='Z'; ++a)
            {
                cleanSilent(a);
            }
        }
        int n;
        scanf("%d",&n);
        while(n--)
        {
            char command[20];
            scanf("%s",command);
            if(*command=='P')
            {
                if(command[6]=='A')
                {
                    check(strcmp(command,"PRINT_ASC")==0);
                    char id[2];
                    scanf("%s",id);
                    checkList(*id);
                    print_asc(*id);
                    checkList(*id);
                }
                else
                {
                    check(strcmp(command,"PRINT_DESC")==0);
                    char id[2];
                    scanf("%s",id);
                    checkList(*id);
                    print_desc(*id);
                    checkList(*id);
                }
            }
            else if(*command=='D')
            {
                check(strcmp(command,"DERIVATIVE")==0);
                char id[2];
                scanf("%s",id);
                checkList(*id);
                derivative(*id);
                checkList(*id);
            }
            else if(*command=='A')
            {
                if(command[3]!='\0')
                {
                    check(strcmp(command,"ADD_MONO")==0);
                    char id[2];
                    long long a,b;
                    scanf("%s%lld%lld",id,&a,&b);
                    checkList(*id);
                    add_mono(*id,a,b);
                    checkList(*id);
                }
                else
                {
                    check(strcmp(command,"ADD")==0);
                    char id1[2],id2[2];
                    scanf("%s%s",id1,id2);
                    checkList(*id1);
                    checkList(*id2);
                    add(*id1,*id2);
                    checkList(*id1);
                    checkList(*id2);
                }
            }
            else if(*command=='M')
            {
                if(command[1]=='I')
                {
                    check(strcmp(command,"MIN")==0);
                    char id[2];
                    scanf("%s",id);
                    checkList(*id);
                    min(*id);
                    checkList(*id);
                }
                else if(command[1]=='A')
                {
                    check(strcmp(command,"MAX")==0);
                    char id[2];
                    scanf("%s",id);
                    checkList(*id);
                    max(*id);
                    checkList(*id);
                }
                else if(command[5]=='\0')
                {
                    check(strcmp(command,"MULTI")==0);
                    char id1[2],id2[2];
                    scanf("%s%s",id1,id2);
                    checkList(*id1);
                    checkList(*id2);
                    multi(*id1,*id2);
                    checkList(*id1);
                    checkList(*id2);
                }
                else
                {
                    check(strcmp(command,"MULTI_CONST")==0);
                    char id[2];
                    long long a;
                    scanf("%s%lld",id,&a);
                    checkList(*id);
                    multi_const(*id,a);
                    checkList(*id);
                }
            }
            else
            {
                check(strcmp(command,"CLEAN")==0);
                char id[2];
                scanf("%s",id);
                checkList(*id);
                clean(*id);
                checkList(*id);
            }
        }
    }
}

#ifdef DEBUG

inline void checkNotGuard(Node *node)
{
    check(node!=NULL);
    char a;
    for(a=0; a<='Z'-'A'+2; ++a)
    {
        check(node!=&frontGuard[a]);
        check(node!=&backGuard[a]);
    }
}

inline void checkList(char id)
{
    Node *i=frontGuard[id-'A'].next;
    const Node * const e=&backGuard[id-'A'];
    for(; i!=e; i=i->next)
    {
        check(i->coefficient!=0);
        if(i->next!=e)
            check(i->exponent<i->next->exponent);
    }
}

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
