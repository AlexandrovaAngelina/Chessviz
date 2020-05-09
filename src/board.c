#include "board.h"
#include "board_read.h"

extern char input[7];
extern int Y1, Y2, X1, X2;
extern char board[8][8];

int checkWIn(int status)
{
    int i, j, player = 0;
    if (status == 1) {
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                if (board[i][j] == 'q') {
                    player = 1;
                }
            }
        }
    }
    if (status == 2) {
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                if (board[i][j] == 'Q') {
                    player = 2;
                }
            }
        }
    }

    if (player == 0) {
        return status;
    }

    return 0;
}

void move()
{
    board[Y2][X2] = board[Y1][X1];
    board[Y1][X1] = ' ';
}

int white()
{
    if ((board[Y2][X2] > 'A') && (board[Y2][X2] < 'S')) {
        return 0;
    }
    switch (board[Y1][X1]) {
    case 'P':
        if ((input[2] == '-') && (board[Y2][X2] != ' ')) {
            break;
        }
        if ((board[Y2][X2] == ' ') && (Y1 == 1) && (X1 == X2) && (Y2 - Y1 > 0)
            && (Y2 - Y1 < 3) && chY()) {
            return 1;
        }
        if ((board[Y2][X2] == ' ') && (X2 == X1) && (Y2 - Y1 == 1)) {
            choose_a_pawn();
            return 1;
        }
        if ((board[Y2][X2] < 's' && board[Y2][X2] > 'a')
            && ((X2 - X1 == 1) || (X2 - X1 == -1)) && (Y2 - Y1 == 1)
            && (input[2] == 'x')) {
            return 1;
        }
        break;
    case 'R':
        if ((input[2] == '-') && (board[Y2][X2] != ' ')) {
            break;
        }
        if ((Y2 == Y1) && (chX())) {
            return 1;
        }
        if ((X2 == X1) && (chY())) {
            return 1;
        }
        break;
    case 'N':
        if ((input[2] == '-') && (board[Y2][X2] != ' ')) {
            break;
        }
        if ((Y1 - Y2 == 2) && (X1 - X2 == 1)) {
            return 1;
        }
        if ((Y2 - Y1 == 2) && (X2 - X1 == 1)) {
            return 1;
        }
        if ((Y2 - Y1 == 2) && (X1 - X2 == 1)) {
            return 1;
        }
        if ((Y1 - Y2 == 2) && (X2 - X1 == 1)) {
            return 1;
        }
        if ((Y1 - Y2 == 1) && (X2 - X1 == 2)) {
            return 1;
        }
        if ((Y2 - Y1 == 1) && (X2 - X1 == 2)) {
            return 1;
        }
        if ((Y1 - Y2 == 1) && (X1 - X2 == 2)) {
            return 1;
        }
        if ((Y2 - Y1 == 1) && (X1 - X2 == 2)) {
            return 1;
        }
        break;
    case 'B':
        if ((input[2] == '-') && (board[Y2][X2] != ' ')) {
            break;
        }
        if (chD()) {
            return 1;
        }
        break;
    case 'K':
        if ((input[2] == '-') && (board[Y2][X2] != ' ')) {
            break;
        }
        if ((Y1 - Y2 != 1) && (Y2 - Y1 != 1)
            && ((X1 - X2 != 1) && (X2 - X1 != 1))) {
            break;
        } else {
            return 1;
        }
        break;
    case 'Q':
        if ((input[2] == '-') && (board[Y2][X2] != ' ')) {
            break;
        }
        if (chX() || chY() || chD()) {
            return 1;
        }
        break;
    }
    return 0;
}

int black()
{
    if ((board[Y2][X2] > 'a') && (board[Y2][X2] < 's')) {
        return 0;
    }
    switch (board[Y1][X1]) {
    case 'p':
        if ((input[2] == '-') && (board[Y2][X2] != ' ')) {
            break;
        }
        if ((board[Y2][X2] == ' ') && (Y1 == 6) && (X1 == X2) && (Y1 - Y2 > 0)
            && (Y1 - Y2 < 3) && chY()) {
            return 1;
        }
        if ((board[Y2][X2] == ' ') && (X2 == X1) && (Y1 - Y2 == 1)) {
            choose_a_pawn();
            return 1;
        }
        if ((board[Y2][X2] < 'S' && board[Y2][X2] > 'A')
            && ((X1 - X2 == 1) || (X1 - X2 == -1)) && (Y1 - Y2 == 1)) {
            return 1;
        }
        break;
    case 'r':
        if ((input[2] == '-') && (board[Y2][X2] != ' ')) {
            break;
        }
        if ((Y2 == Y1) && (chX())) {
            return 1;
        }
        if ((X2 == X1) && (chY())) {
            return 1;
        }
        break;
    case 'n':
        if ((input[2] == '-') && (board[Y2][X2] != ' ')) {
            break;
        }
        if ((Y1 - Y2 == 2) && (X1 - X2 == 1)) {
            return 1;
        }
        if ((Y2 - Y1 == 2) && (X2 - X1 == 1)) {
            return 1;
        }
        if ((Y2 - Y1 == 2) && (X1 - X2 == 1)) {
            return 1;
        }
        if ((Y1 - Y2 == 2) && (X2 - X1 == 1)) {
            return 1;
        }
        if ((Y1 - Y2 == 1) && (X2 - X1 == 2)) {
            return 1;
        }
        if ((Y2 - Y1 == 1) && (X2 - X1 == 2)) {
            return 1;
        }
        if ((Y1 - Y2 == 1) && (X1 - X2 == 2)) {
            return 1;
        }
        if ((Y2 - Y1 == 1) && (X1 - X2 == 2)) {
            return 1;
        }
        break;
    case 'b':
        if ((input[2] == '-') && (board[Y2][X2] != ' ')) {
            break;
        }
        if (chD()) {
            return 1;
        }
        break;
    case 'k':
        if ((input[2] == '-') && (board[Y2][X2] != ' ')) {
            break;
        }
        if ((Y1 - Y2 != 1) && (Y2 - Y1 != 1)
            && ((X1 - X2 != 1) && (X2 - X1 != 1))) {
            break;
        } else {
            return 1;
        }
    case 'q':
        if ((input[2] == '-') && (board[Y2][X2] != ' ')) {
            break;
        }
        if (chX() || chY() || chD()) {
            return 1;
        }
        break;
    }
    return 0;
}

int chY()
{
    int i, c1 = Y1, c2 = Y2;
    if (X1 != X2) {
        return 0;
    }
    if (Y1 > Y2) {
        c1 = Y2;
        c2 = Y1;
    }
    for (i = c1 + 1; i < c2; i++) {
        if ((board[i][X1] > 'a' && board[i][X1] < 's')
            || (board[i][X1] > 'A' && board[i][X1] < 'S')) {
            return 0;
        }
    }
    return 1;
}

int chX()
{
    int i, c1 = X1, c2 = X2;
    if (Y1 != Y2) {
        return 0;
    }
    if (X1 > X2) {
        c1 = X2;
        c2 = X1;
    }
    for (i = c1 + 1; i < c2; i++) {
        if ((board[Y1][i] > 'a' && board[Y1][i] < 's')
            || (board[Y1][i] > 'A' && board[Y1][i] < 'S')) {
            return 0;
        }
    }
    return 1;
}

int chD()
{
    int i, j, c1 = Y2, c2 = Y1, ci, cj;
    if (((Y2 - Y1) != (X2 - X1)) && ((Y2 - Y1) != (X1 - X2))) {
        return 0;
    }
    if (Y2 > Y1) {
        c1 = Y1;
        c2 = Y2;
        ci = 1;
    } else {
        ci = -1;
    }
    if (X2 > X1) {
        cj = 1;
    } else {
        cj = -1;
    }
    i = Y1 + ci;
    j = X1 + cj;
    while ((i < c2) && (i > c1)) {
        if (((board[i][j] > 'a') && (board[i][j] < 's'))
            || ((board[i][j] > 'A') && (board[i][j] < 'S'))) {
            return 0;
        }
        i += ci;
        j += cj;
    }
    return 1;
}

void choose_a_pawn()
{
    char npawn;
    if ((board[Y1][X1] == 'p') && (Y2 == 0)) {
        while (1) {
            printf("Choice need figure:");
            npawn = getchar();
            if ((npawn == 'r') || (npawn == 'n') || (npawn == 'b')
                || (npawn == 'q')) {
                board[Y1][X1] = npawn;
                break;
            } else {
                printf("Incorrectly figure\n");
            }
        }
    }
    if ((board[Y1][X1] == 'P') && (Y2 == 7)) {
        while (1) {
            printf("Choice need figure:");
            npawn = getchar();
            if ((npawn == 'R') || (npawn == 'N') || (npawn == 'B')
                || (npawn == 'Q')) {
                board[Y1][X1] = npawn;
                break;
            } else {
                printf("Incorrcetly figure\n");
            }
        }
    }
}
