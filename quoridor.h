#ifndef QUORIDORH
#define QUORIDORH

void startGame(int pawns[2][2], int wallsLeft[2], int hWalls[8][8], int vWalls[8][8]);
int tryMove(int pawns[2][2], int player, int row, int column);
int tryWall(int wallsLeft[2], int hWalls[8][8], int vWalls[8][8], int player, int row, int column, char direction);

void drawBoard(int pawns[2][2], int wallsLeft[2], int hWalls[8][8], int vWalls[8][8]);
void showHelp();

int readWord(char word[]);
char wordKind(char word[]);
int squareColumn(char word[], int size);
int squareRow(char word[], int size);
char wallDirection(char word[]);

#endif