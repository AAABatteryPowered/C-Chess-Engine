#pragma once

#include "../common.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "../bit/bit.h"

typedef struct board {
	u64 white_pawns;
	u64 black_pawns;

	u64 white_knights;
	u64 black_knights;

	u64 white_bishops;
	u64 black_bishops;

	u64 white_rooks;
	u64 black_rooks;

	u64 white_queens;
	u64 black_queens;

	u64 white_kings;
	u64 black_kings;

	int turnToMove;
} Board;

void setBitOnBoard(u64* board, int8_t* bit);

Board* FenToBitboard(char fen[], int turnToMove);