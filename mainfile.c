#include <stdio.h>
#include "quoridor.h"

int main() {
    int pawns[2][2];
    int wallsLeft[2];
    int hWalls[8][8];
    int vWalls[8][8];
    int player = 0;
    char word[100];
    char kind, direction;
    int row, column, worked;

    startGame(pawns, wallsLeft, hWalls, vWalls);
    showHelp();

    while (1) {
        drawBoard(pawns, wallsLeft, hWalls, vWalls);
        printf("Player %d > ", player + 1);

        if (readWord(word) == 0) break;

        kind = wordKind(word);

        if (kind == 'q') break;

        if (kind == 'h') {
            showHelp();
            continue;
        }

        if (kind == 'm') {
            column = squareColumn(word, 9);
            row = squareRow(word, 9);
            if (column == -1 || row == -1) {
                printf("Error: squares go from a1 to i9\n");
                continue;
            }
            worked = tryMove(pawns, player, row, column);
        } else if (kind == 'w') {
            column = squareColumn(word, 8);
            row = squareRow(word, 8);
            direction = wallDirection(word);
            if (column == -1 || row == -1) {
                printf("Error: wall spots go from a1 to h8\n");
                continue;
            }
            if (direction == 'x') {
                printf("Error: end a wall with h or v, like d3h\n");
                continue;
            }
            worked = tryWall(wallsLeft, hWalls, vWalls, player, row, column, direction);
        } else {
            printf("Error: type a square like e5, a wall like d3h, or help\n");
            continue;
        }

        if (worked == 1) {
            player = 1 - player;
    }
}

    printf("Bye!\n");
    return 0;
}
