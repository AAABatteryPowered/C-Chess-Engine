#pragma once

#include "../fen/fen.h"

typedef struct move {
	int startSquare;
	int targetSquare;
} Move;

Move* genLegalMoves(Board*);