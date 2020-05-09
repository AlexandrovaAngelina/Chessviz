#include "board_read.h"
#include "board.h"

extern char input[7];
extern int Y1, Y2, X1, X2;
extern char board[8][8];

void scan(int flag)
{
    while (1) {
        while (1) {
            fgets(input, 7, stdin);
            if (chartoint(input)) {
                break;
            }
        }
        if (flag == 1) {
            if (white() == 1) {
                break;
            } else {
            }
        }
        if (flag == 2) {
            if (black() == 1) {
                break;
            } else {
            }
        }
    }
}

int chartoint(char input[7])
{
    if ((input[2] != '-') && (input[2] != 'x')) {
        return 0;
    }
    X1 = (int)input[0] - 'a';
    Y1 = (int)input[1] - '1';
    X2 = (int)input[3] - 'a';
    Y2 = (int)input[4] - '1';
    if ((input[2] == 'x') && (board[Y2][X2] == ' ')) {
        return 0;
    }
    if ((X2 < 8) && (X2 >= 0) && (Y2 >= 0) && (Y2 < 8) && (X1 >= 0) && (X1 < 8)
        && (Y1 >= 0) && (Y1 < 8))
        return 1;
    return 0;
}
