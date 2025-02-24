#pragma once

#include "../common.h"

typedef struct board {
	u64 pawns;
	u64 knights;
	u64 bishops;
	u64 rooks;
	u64 queens;
	u64 kings;
	u64 colours;
} Board;

Board* FenToBitboard(char fen[]);