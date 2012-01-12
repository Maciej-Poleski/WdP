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

FILE *input;
FILE *output;

int characterCount['Z' - 'A' + 1] = {0};
int digitCount = 0;
int wordCount = 0;
int lineCount = 0;
int emptyLineCount = 0;
bool lastCharacterIsPartOfWord = false;
bool thisLineIsEmpty = true;

int main(int argc, char **argv)
{
    if(argc != 3) {
        error(1, 0, "Potrzeba dwóch argumentów");
    }
    input = fopen(argv[1], "r");
    if(input == NULL) {
        error(2, errno, "Nie udało się otworzyć pliku >>%s<<", argv[1]);
    }
    output = fopen(argv[2], "w");
    if(output == NULL) {
        error(3, errno, "Nie udało się otworzyć pliku >>%s<<", argv[2]);
    }
    int character;
    for(character = getc(input);; character = getc(input)) {
        if(character == EOF) {
            if(lastCharacterIsPartOfWord)
                ++wordCount;
            if(!thisLineIsEmpty)
                ++lineCount;
            break;
        } else if(character == '\n') {
            ++lineCount;
            if(lastCharacterIsPartOfWord)
                ++wordCount;
            if(thisLineIsEmpty)
                ++emptyLineCount;
            lastCharacterIsPartOfWord = false;
            thisLineIsEmpty = true;
        } else if(isalpha(character)) {
            ++characterCount[toupper(character) - 'A'];
            lastCharacterIsPartOfWord = true;
            thisLineIsEmpty = false;
        } else if(isdigit(character)) {
            if(lastCharacterIsPartOfWord)
                ++wordCount;
            lastCharacterIsPartOfWord = false;
            thisLineIsEmpty = false;
            ++digitCount;
        } else if(character == '\r') {
            // DO NOTHING
        } else {
            if(lastCharacterIsPartOfWord)
                ++wordCount;
            lastCharacterIsPartOfWord = false;
            thisLineIsEmpty = false;
        }
    }
    fclose(input);
    for(character = 'A'; character <= 'Z'; ++character)
        fprintf(output, "%c : %d\n", (char)character, characterCount[character - 'A']);
    fprintf(output, "Cyfr: %d\n", digitCount);
    fprintf(output, "Wyrazy: %d\n", wordCount);
    fprintf(output, "Linie wszystkie: %d\n", lineCount);
    fprintf(output, "Linie puste: %d", emptyLineCount);
    fclose(output);
    return 0;
}

