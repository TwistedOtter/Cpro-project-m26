#include <stdio.h>
#include <string.h>
#include "quoridor.h"

int readWord(char word[]) {
    if (scanf("%99s", word) == 1) return 1;
    return 0;
}

char wordKind(char word[]) {
    if (strcmp(word, "quit") == 0 || strcmp(word, "q") == 0) return 'q';
    if (strcmp(word, "help") == 0 || strcmp(word, "h") == 0) return 'h';
    if (strlen(word) == 2) return 'm';
    if (strlen(word) == 3) return 'w';
    return 'x';
}

int squareColumn(char word[], int size) {
    char letter = word[0];
    int column;

    if (letter >= 'A' && letter <= 'Z') letter = letter + 32;
    column = letter - 'a';

    if (column < 0 || column >= size) return -1;
    return column;
}

int squareRow(char word[], int size) {
    int row = word[1] - '1';

    if (row < 0 || row >= size) return -1;
    return row;
}

char wallDirection(char word[]) {
    char letter = word[2];

    if (letter == 'h' || letter == 'H') return 'h';
    if (letter == 'v' || letter == 'V') return 'v';
    return 'x';
}