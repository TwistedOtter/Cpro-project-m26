#include <stdio.h>
#include "quoridor.h"

void startGame(int pawns[2][2], int wallsLeft[2], int hWalls[8][8], int vWalls[8][8]) {
    int row, column;

    pawns[0][0] = 0;
    pawns[0][1] = 4;
    pawns[1][0] = 8;
    pawns[1][1] = 4;
    wallsLeft[0] = 10;
    wallsLeft[1] = 10;

    for (row = 0; row < 8; row++) {
        for (column = 0; column < 8; column++) {
            hWalls[row][column] = 0;
            vWalls[row][column] = 0;
        }
    }
}

int tryMove(int pawns[2][2], int player, int row, int column) {
    int i;

    for (i = 0; i < 2; i++) {
        if (pawns[i][0] == row && pawns[i][1] == column) {
            printf("Invalid: that square is occupied\n");
            return 0;
        }
    }

    pawns[player][0] = row;
    pawns[player][1] = column;
    return 1;
}

int tryWall(int wallsLeft[2], int hWalls[8][8], int vWalls[8][8], int player, int row, int column, char direction) {
    int overlaps = 0;

    if (wallsLeft[player] == 0) {
        printf("Invalid: you have no walls left\n");
        return 0;
    }

    if (direction == 'h') {
        if (hWalls[row][column] == 1) overlaps = 1;
        if (column > 0 && hWalls[row][column - 1] == 1) overlaps = 1;
        if (column < 7 && hWalls[row][column + 1] == 1) overlaps = 1;
        if (vWalls[row][column] == 1) overlaps = 1;
    } else {
        if (vWalls[row][column] == 1) overlaps = 1;
        if (row > 0 && vWalls[row - 1][column] == 1) overlaps = 1;
        if (row < 7 && vWalls[row + 1][column] == 1) overlaps = 1;
        if (hWalls[row][column] == 1) overlaps = 1;
    }

    if (overlaps == 1) {
        printf("Invalid: wall overlaps or crosses another wall\n");
        return 0;
    }

    if (direction == 'h') {
        hWalls[row][column] = 1;
    }
    else {
        vWalls[row][column] = 1;
    }

    wallsLeft[player]--;
    return 1;
}