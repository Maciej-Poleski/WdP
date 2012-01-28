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
void init(int argc, char **argv)
{
    if(argc != 3) {
        fprintf(stderr, "Potrzebne są dwa argumenty <wejście> <wyjście>\n");
        exit(1);
    }
    freopen(argv[1], "r", stdin);
    freopen(argv[2], "w", stdout);
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

typedef struct osoba {
    char stanowisko [31];
    int pensja;
    int wiek;
} Person;

static int compareNumbers(const void *key, const void *ptr, int d) __attribute__((nonnull));
static int compareStrings(const void *key, const void *ptr, int d) __attribute__((nonnull));
static int compareStringsByLength(const void *key, const void *ptr, int d) __attribute__((nonnull));
static int comparePersons(const void *key, const void *ptr, int d) __attribute__((nonnull));

typedef int (*comp)(const void *key, const void *ptr, int d);

static const void *binarySearchLast(const void *key, const void *tab, int tabLength, int keySize, int direction, comp cmp) __attribute__((nonnull));
static const void *binarySearchFirst(const void *key, const void *tab, int tabLength, int keySize, int direction, comp cmp) __attribute__((nonnull));

static int compareNumbers(const void *key, const void *ptr, int d)
{
    check(d == 1 || d == -1);
    if(d == 1)
        return (*((int *)key) - * ((int *)ptr));
    else
        return -(*((int *)key) - * ((int *)ptr));
}

static int compareStrings(const void *key, const void *ptr, int d)
{
    check(d == 1 || d == -1);
    if(d == 1)
        return strcasecmp(key, ptr);
    else
        return -(strcasecmp(key, ptr));
}

static int compareStringsByLength(const void *key, const void *ptr, int d)
{
    check(d == 1 || d == -1);
    size_t kLen = strlen(key);
    size_t pLen = strlen(ptr);
    if(d == 1) {
        if(kLen == pLen)
            return strcasecmp(key, ptr);
        else
            return kLen - pLen;
    } else {
        if(kLen == pLen)
            return -(strcasecmp(key, ptr));
        else
            return -(kLen - pLen);
    }
}

static int comparePersons(const void *key, const void *ptr, int d)
{
    check(d == 1 || d == -1);
    const Person *iKey = key;
    const Person *iPtr = ptr;
    int str = strcasecmp(iKey->stanowisko, iPtr->stanowisko);
    if(d == 1) {
        if(str != 0)
            return str;
        if(iKey->pensja - iPtr->pensja != 0)
            return iKey->pensja - iPtr->pensja;
        return iKey->wiek - iPtr->wiek;
    } else {
        if(str != 0)
            return -(str);
        if(iKey->pensja - iPtr->pensja != 0)
            return -(iKey->pensja - iPtr->pensja);
        return -(iKey->wiek - iPtr->wiek);
    }
}

static const void *binarySearchLast(const void *key, const void *tab, int tabLength, int keySize, int direction, comp cmp)
{
    check(tabLength > 0);
    check(direction == 1 || direction == -1);
    if(tabLength == 1)
        return tab;
    int s = tabLength / 2;
    int c = cmp(key, tab + s * keySize, direction);
    if(c >= 0)
        return binarySearchLast(key, tab + s * keySize, tabLength - s, keySize, direction, cmp);
    else
        return binarySearchLast(key, tab, s, keySize, direction, cmp);
}

static const void *binarySearchFirst(const void *key, const void *tab, int tabLength, int keySize, int direction, comp cmp)
{
    check(tabLength > 0);
    check(direction == 1 || direction == -1);
    if(tabLength == 1)
        return tab;
    int s = tabLength / 2;
    int c = cmp(key, tab + (s - 1) * keySize, direction);
    if(c > 0)
        return binarySearchFirst(key, tab + s * keySize, tabLength - s, keySize, direction, cmp);
    else
        return binarySearchFirst(key, tab, s, keySize, direction, cmp);
}

#ifdef DEBUG

#else

#endif

inline static void solution(void)
{
    int z;
    scanf("%d", &z);
    while(z--) {
        int n;
        char dataType;
        char orderType;
        scanf("%d %c%c", &n, &dataType, &orderType);
        if(dataType == 'l') { // Liczby
            int *tab = malloc((n + 2) * sizeof(int));
            tab[0] = orderType == 'r' ? -1000000001 : 1000000001;
            ++tab;
            tab[n] = orderType == 'r' ? 1000000001 : -1000000001;
            int i;
            for(i = 0; i < n; ++i)
                scanf("%d", tab + i);
            int m;
            scanf("%d", &m);
            while(m--) {
                int what;
                char mode;
                scanf("%d %c", &what, &mode);
                const int *p = mode == 'p'
                               ? binarySearchFirst(&what, tab - 1, n + 2, sizeof(int), orderType == 'r' ? 1 : -1, compareNumbers)
                                   : binarySearchLast(&what, tab - 1, n + 2, sizeof(int), orderType == 'r' ? 1 : -1, compareNumbers);
                check(((void *)p - (void *)tab) % sizeof(int) == 0);
                if(p < tab || p >= tab + n)
                    printf("BRAK\n");
                else
                    printf("%d\n", (int)(p - tab));
            }
            free(tab - 1);
        } else if(dataType == 'n') { // Napisy
            char *tab = malloc((n + 2) * sizeof(char) * 31);
            tab[0] = orderType == 'r' ? '\0' : '~';
            tab[1] = '\0';
            tab += 31;
            tab[n * 31] = orderType == 'r' ? '~' : '\0';;
            tab[n * 31 + 1] = '\0';
            int i;
            for(i = 0; i < n; ++i)
                scanf("%s", tab + i * 31);
            int m;
            scanf("%d", &m);
            while(m--) {
                char what[31];
                char mode;
                scanf("%s %c", what, &mode);
                const char *p = mode == 'p'
                                ? binarySearchFirst(what, tab - 31, n + 2, sizeof(char) * 31, orderType == 'r' ? 1 : -1, compareStrings)
                                    : binarySearchLast(what, tab - 31, n + 2, sizeof(char) * 31, orderType == 'r' ? 1 : -1, compareStrings);
                check((p - tab) % 31 == 0);
                if(p < tab || p >= tab + n * 31)
                    printf("BRAK\n");
                else
                    printf("%d\n", (int)((p - tab) / 31));
            }
            free(tab - 31);
        } else if(dataType == 'd') { // Długość napisów
            char *tab = malloc((n + 2) * sizeof(char) * 31);
            if(orderType == 'r') {
                tab[0] = '\0';
            } else {
                int i;
                for(i = 0; i < 30; ++i)
                    tab[i] = '~';
                tab[30] = '\0';
            }
            tab += 31;
            if(orderType == 'r') {
                int i;
                for(i = 0; i < 30; ++i)
                    tab[n * 31 + i] = '~';
                tab[n * 31 + 30] = '\0';
            } else {
                tab[n * 31] = '\0';
            }
            int i;
            for(i = 0; i < n; ++i)
                scanf("%s", tab + i * 31);
            int m;
            scanf("%d", &m);
            while(m--) {
                char what[31];
                char mode;
                scanf("%s %c", what, &mode);
                const char *p = mode == 'p'
                                ? binarySearchFirst(what, tab - 31, n + 2, sizeof(char) * 31, orderType == 'r' ? 1 : -1, compareStringsByLength)
                                    : binarySearchLast(what, tab - 31, n + 2, sizeof(char) * 31, orderType == 'r' ? 1 : -1, compareStringsByLength);
                check((p - tab) % 31 == 0);
                if(p < tab || p >= tab + n * 31)
                    printf("BRAK\n");
                else
                    printf("%d\n", (int)((p - tab) / 31));
            }
            free(tab - 31);
        } else { // Struktury
            check(dataType == 's');
            Person *tab = malloc((n + 2) * sizeof(Person));
            Person p = {"", -1000000001, -1000000001};
            Person p2 = {"~", 1000000001, 1000000001};
            tab[0] = orderType == 'r' ? p : p2;
            ++tab;
            tab[n] = orderType == 'r' ? p2 : p;
            int i;
            for(i = 0; i < n; ++i)
                scanf("%s%d%d", tab[i].stanowisko, &(tab[i].pensja), &(tab[i].wiek));
            int m;
            scanf("%d", &m);
            while(m--) {
                Person what;
                char mode;
                scanf("%s%d%d %c", what.stanowisko, &(what.pensja), &(what.wiek), &mode);
                const Person *p = mode == 'p'
                                  ? binarySearchFirst(&what, tab - 1, n + 2, sizeof(Person), orderType == 'r' ? 1 : -1, comparePersons)
                                      : binarySearchLast(&what, tab - 1, n + 2, sizeof(Person), orderType == 'r' ? 1 : -1, comparePersons);
                check(((void *)p - (void *)tab) % sizeof(Person) == 0);
                if(p < tab || p >= tab + n)
                    printf("BRAK\n");
                else
                    printf("%d\n", (int)((p - tab)));
            }
            free(tab - 1);
        }
    }
}

#ifdef DEBUG

inline void checkAll(void)
{
}

#endif // DEBUG

int main(int argc, char **argv)
{
#ifdef DEBUG
    init(argc, argv);
    checkAll();
#endif // DEBUG
    solution();
#ifdef DEBUG
    end();
#endif // DEBUG
    return 0;
}

