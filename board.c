#include <stdio.h>
#include "quoridor.h"

int vBlocked(int vWalls[8][8], int row, int column) {
    if (row < 8 && vWalls[row][column] == 1) return 1;
    if (row > 0 && vWalls[row - 1][column] == 1) return 1;
    return 0;
}

int hBlocked(int hWalls[8][8], int row, int column) {
    if (column < 8 && hWalls[row][column] == 1) return 1;
    if (column > 0 && hWalls[row][column - 1] == 1) return 1;
    return 0;
}

void drawLetters() {
    int column;
    printf("  ");
    for (column = 0; column < 9; column++) {
        printf(" %c  ", 'a' + column);
    }
    printf("\n");
}

void drawBoard(int pawns[2][2], int wallsLeft[2], int hWalls[8][8], int vWalls[8][8]) {
    int row, column, gap;
    char mark;

    printf("\n");
    drawLetters();

    for (row = 8; row >= 0; row--) {
        printf("%d ", row + 1);
        for (column = 0; column < 9; column++) {
            mark = '.';
            if (pawns[0][0] == row && pawns[0][1] == column) mark = '1';
            if (pawns[1][0] == row && pawns[1][1] == column) mark = '2';
            printf(" %c ", mark);
            if (column < 8) {
                if (vBlocked(vWalls, row, column) == 1) printf("#");
                else printf(" ");
            }
        }
        printf(" %d\n", row + 1);

        if (row > 0) {
            gap = row - 1;
            printf("  ");
            for (column = 0; column < 9; column++) {
                if (hBlocked(hWalls, gap, column) == 1) printf("###");
                else printf("   ");
                if (column < 8) {
                    if (hWalls[gap][column] == 1 || vWalls[gap][column] == 1) printf("#");
                    else printf(" ");
                }
            }
            printf("\n");
        }
    }

    drawLetters();
    printf("\nWalls left: Player 1 = %d, Player 2 = %d\n", wallsLeft[0], wallsLeft[1]);
}

void showHelp() {
    printf("Type one word per turn:\n");
    printf("  (letter)(number) moves pawn to square (eg - e5)\n");
    printf("  (letter)(number)(h)   puts a horizontal wall at the given square(eg- d3h)\n");
    printf("  (letter)(number)(v)  puts a vertical wall at the given square(eg-d3v)\n");
    printf("  help  prints this message\n");
    printf("  quit  ends the game\n");
}