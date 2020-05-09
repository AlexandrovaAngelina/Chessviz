#ifndef BOARD_H
#define BOARD_H

#include "board.h"
#include <stdio.h>
#include <string.h>

int white();
int black();
void move();
int chY();
int chX();
int chD();
void choose_a_pawn();
int checkWIn(int status);

#endif