// Maciej Poleski
#ifndef DEBUG
#ifndef NDEBUG
#define NDEBUG
#endif
#define check(x)
#else
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
#include <error.h>
#include <errno.h>

typedef struct {
    char name[101];
    char size;
    double price;
    unsigned int count;
} Item;

static FILE *databaseFileHandle = NULL;

static void exit0(void) __attribute__((noreturn));
static inline void printName(const char *name) __attribute__((nonnull));
static void updateInDatabase(const Item *item) __attribute__((nonnull));

static void closeDatabase(void)
{
    fclose(databaseFileHandle);
}

static void exit0(void)
{
    exit(0);
}

static const char *getName(void)
{
    printf("Podaj nazwę produktu (maksymalnie 100 bajtów)\n");
    static char name[101] = {0};
    getchar(); // HACK
    fgets(name,101,stdin);
    char *p=strchr(name,'\n');
    if(p!=NULL)
        *p='\0';
    return name;
}

static inline char getSize(void)
{
    printf("Podaj rozmiar produktu (znak)\n");
    char s[2];
    scanf("%1s", s);
    return *s;
}

static inline unsigned int getCount(void)
{
    printf("Podaj ilość produktu (liczba z przedziału [0,%u])\n", UINT_MAX);
    unsigned int s;
    scanf("%u", &s);
    return s;
}

static inline double getPrice(void)
{
    printf("Podaj cenę produktu (liczba typu double)\n");
    double s;
    scanf("%lf", &s);
    return s;
}

static inline void printName(const char *name)
{
    check(name != NULL);
    printf("Nazwa produktu: %s\n", name);
}

static inline void printSize(char size)
{
    printf("Rozmiar: %c\n", size);
}

static inline void printCount(unsigned int count)
{
    printf("Ilość: %u\n", count);
}

static inline void printPrice(double price)
{
    printf("Cena: %.2lf\n", price);
}

static bool askForPermission(void)
{
    while(true) {
        printf("\nCzy chcesz kontynuować? [T/n] ");
        getchar();
        static char buffer[256];
        if(gets(buffer) == NULL) {
            printf("Wystąpił błąd podczas wczytywania wejścia\nKoniec\n");
            exit(3);
        }
        if(buffer[0] == 0 || (toupper(buffer[0]) == 'T' && buffer[1] == '\0'))
            return true;
        else if(toupper(buffer[0]) == 'N' && buffer[1] == '\0')
            return false;
        printf(" >>%s<< nie jest poprawną odpowiedzią.\n", buffer);
    }
    check(false);
}

static Item *readNextItem(void)
{
    static Item item;
    item.name[100]='\0';
    if(fread(item.name, 1, 100, databaseFileHandle) != 100)
        return NULL;
    if(fread(&(item.size), sizeof(char), 1, databaseFileHandle) != 1)
        return NULL;
    if(fread(&(item.price), sizeof(double), 1, databaseFileHandle) != 1)
        return NULL;
    if(fread(&(item.count), sizeof(unsigned int), 1, databaseFileHandle) != 1)
        return NULL;
    return &item;
}

static void updateInDatabase(const Item *item)
{
    check(item != NULL);
    fseek(databaseFileHandle, 0, SEEK_CUR);
    if(fwrite(item->name, 1, 100, databaseFileHandle) != 100)
        error(4, errno, "Błąd podczas zapisu do bazy danych");
    if(fwrite(&(item->size), sizeof(char), 1, databaseFileHandle) != 1)
        error(5, errno, "Błąd podczas zapisu do bazy danych");
    if(fwrite(&(item->price), sizeof(double), 1, databaseFileHandle) != 1)
        error(6, errno, "Błąd podczas zapisu do bazy danych");
    if(fwrite(&(item->count), sizeof(unsigned int), 1, databaseFileHandle) != 1)
        error(7, errno, "Błąd podczas zapisu do bazy danych");
}

static void sell(void)
{
    printf("Sprzedaż produktu\n");
    const char *name = getName();
    char size = getSize();
    printf("Zweryfikuj dane:\n");
    printName(name);
    printSize(size);
    if(askForPermission()) {
        fseek(databaseFileHandle, 0L, SEEK_SET);
        while(true) {
            long oldPosition = ftell(databaseFileHandle);
            Item *item = readNextItem();
            if(item == NULL) {
                printf("Błąd - takiego produktu nie ma w bazie!\n");
                return;
            }
            if(strcmp(name, item->name) == 0 && size == item->size) {
                if(item->count == 0) {
                    printf("Błąd - nakład wyczerpany!\n");
                    return;
                } else {
                    --item->count;
                    fseek(databaseFileHandle, oldPosition, SEEK_SET);
                    updateInDatabase(item);
                    printf("Sprzedano\n");
                    return;
                }
            }
        }
        check(false);
    }
}

static void reclamation(void)
{
    printf("Reklamacja produktu\n");
    const char *name = getName();
    char size = getSize();
    printf("Zweryfikuj dane:\n");
    printName(name);
    printSize(size);
    if(askForPermission()) {
        fseek(databaseFileHandle, 0L, SEEK_SET);
        while(true) {
            long oldPosition = ftell(databaseFileHandle);
            Item *item = readNextItem();
            if(item == NULL) {
                printf("Błąd - takiego produktu nie ma w bazie!\n");
                return;
            }
            if(strcmp(name, item->name) == 0 && size == item->size) {
                ++item->count;
                fseek(databaseFileHandle, oldPosition, SEEK_SET);
                updateInDatabase(item);
                printf("Zwrócono\n");
                return;
            }
        }
        check(false);
    }
}

static void delivery(void)
{
    Item item;
    printf("Dostawa produktu\n");
    strcpy(item.name, getName());
    item.count = getCount();
    item.size = getSize();
    item.price = getPrice();
    printf("Zweryfikuj dane:\n");
    printName(item.name);
    printCount(item.count);
    printSize(item.size);
    printPrice(item.price);
    if(askForPermission()) {
        fseek(databaseFileHandle, 0L, SEEK_SET);
        while(true) {
            long oldPosition = ftell(databaseFileHandle);
            Item *i = readNextItem();
            if(i == NULL) {
                fseek(databaseFileHandle, 0L, SEEK_END);
                updateInDatabase(&item);
                printf("Dodano nowy produkt do bazy danych\n");
                return;
            }
            if(strcmp(item.name, i->name) == 0 && item.size == i->size) {
                if(fabs(i->price - item.price) >= 0.01) {
                    if(i->count == 0) {
                        fseek(databaseFileHandle, oldPosition, SEEK_SET);
                        updateInDatabase(&item);
                        printf("Dodano nowe egzemplarze w nowej cenie do bazy danych\n");
                        return;
                    } else {
                        printf("Błąd - nakład nie został wyczerpany - nie można"
                               " zmienić ceny! (%.2lf -> %.2lf)\n", i->price, item.price);
                        return;
                    }
                } else {
                    item.count += i->count;
                    fseek(databaseFileHandle, oldPosition, SEEK_SET);
                    updateInDatabase(&item);
                    printf("Dodano nowe egzemplarze do bazy danych\n");
                    return;
                }
            }
        }
        check(false);
    }
}

static void search(void)
{
    printf("Wyszukiwanie produktu\n");
    const char *name = getName();
    char size = getSize();
    printf("Zweryfikuj dane:\n");
    printName(name);
    printSize(size);
    if(askForPermission()) {
        fseek(databaseFileHandle, 0L, SEEK_SET);
        while(true) {
            Item *item = readNextItem();
            if(item == NULL) {
                printf("Takiego produktu nie ma w bazie!\n");
                return;
            }
            if(strcmp(name, item->name) == 0 && size == item->size) {
                printf("Znaleziono:\n");
                printName(item->name);
                printSize(item->size);
                printPrice(item->price);
                printCount(item->count);
                return;
            }
        }
        check(false);
    }
}

static void search_all(void)
{
    printf("Wyszukiwanie produktu w dowolnym rozmiarze\n");
    const char *name = getName();
    printf("Zweryfikuj dane:\n");
    printName(name);
    if(askForPermission()) {
        fseek(databaseFileHandle, 0L, SEEK_SET);
        bool found = false;
        while(true) {
            Item *item = readNextItem();
            if(item == NULL) {
                printf(found ? "Więcj produktów nie znaleziono\n" : "Takiego produktu nie ma w bazie!\n");
                return;
            }
            if(strcmp(name, item->name) == 0) {
                printf("Znaleziono:\n");
                printName(item->name);
                printSize(item->size);
                printPrice(item->price);
                printCount(item->count);
                printf("\n");
            }
        }
        check(false);
    }
}

static void decrease(void)
{
    printf("Promocja produktu\n");
    const char *name = getName();
    double price = getPrice();
    printf("Zweryfikuj dane:\n");
    printName(name);
    printPrice(price);
    if(askForPermission()) {
        fseek(databaseFileHandle, 0L, SEEK_SET);
        while(true) {
            long oldPosition = ftell(databaseFileHandle);
            Item *item = readNextItem();
            if(item == NULL) {
                printf("Gotowe\n");
                return;
            }
            if(strcmp(name, item->name) == 0) {
                fseek(databaseFileHandle, oldPosition, SEEK_SET);
                item->price = price;
                updateInDatabase(item);
            }
        }
        check(false);
    }
}

static void decrease_all(void)
{
    printf("Promocja wszystkich produktów\n");
    int c;
    while(true) {
        printf("Podaj wysokość promocji (w procentach, liczba z przedziału [0,100])\n");
        scanf("%d", &c);
        if(c >= 0 && c <= 100)
            break;
        printf("Podana wartość (%d) nie jest akceptowana\n", c);
    }
    printf("Zweryfikuj dane:\n");
    printf("Wysokość promocji: %d%%\n", c);
    if(askForPermission()) {
        fseek(databaseFileHandle, 0L, SEEK_SET);
        while(true) {
            long oldPosition = ftell(databaseFileHandle);
            Item *item = readNextItem();
            if(item == NULL) {
                printf("Gotowe\n");
                return;
            }
            fseek(databaseFileHandle, oldPosition, SEEK_SET);
            item->price *= (100.0 - (double)c) / 100;
            updateInDatabase(item);
        }
        check(false);
    }
}

static void print(void)
{
    printf("Zawartość bazy danych:\n");
    fseek(databaseFileHandle, 0L, SEEK_SET);
    while(true) {
        Item *item = readNextItem();
        if(item == NULL) {
            printf("Gotowe\n");
            return;
        }
        printName(item->name);
        printSize(item->size);
        printPrice(item->price);
        printCount(item->count);
        printf("\n");
    }
}

static void (*menu[])(void) = {exit0, sell, reclamation, delivery, search, search_all, decrease, decrease_all, print};

int main(int argc, char **argv)
{
    if(argc != 2)
        error(1, 0, "Należy podać dokładnie jeden argument");
    databaseFileHandle = fopen(argv[1], "r+b");
    if(databaseFileHandle == NULL) {
        databaseFileHandle = fopen(argv[1], "w+b");
        if(databaseFileHandle == NULL)
            error(2, errno, "Błąd podczas otwierania pliku >>%s<<", argv[1]);
    }
    atexit(closeDatabase);

    while(true) {
        int c;
        printf("Menu:\n");
        printf("1 - Sprzedaz\n");
        printf("2 - Reklamacja\n");
        printf("3 - Dostawa\n");
        printf("4 - Sprawdz\n");
        printf("5 - Sprawdz_all\n");
        printf("6 - Promocja\n");
        printf("7 - Promocja_all\n");
        printf("8 - Wypisz\n");
        printf("0 - Koniec\n");
        scanf("%d", &c);
        if(c < 0 || c > 8) {
            printf("%d nie jest poprawną pozycją w menu\n", c);
            continue;
        }
        menu[c]();
    }
    check(false);
    return 0;
}

