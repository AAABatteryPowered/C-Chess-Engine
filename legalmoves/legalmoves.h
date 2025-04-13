#pragma once

#include "../fen/fen.h"

typedef uint16_t move;
// 000000 000000 00             00
// from   to     promotion type move type

typedef struct movearray {
	Move* moves;
	size_t size;
} MoveArray;

typedef struct piecemoves {
	u64 pawn[64];
	u64 knight[64];
	u64 bishop[64];
	u64 rook[64];
	u64 queen[64];
	u64 king[64];
} PieceMoves;

void GenerateAllPieceMoves(PieceMoves* pmoves);

void calcKnightXray(u64* board);

MoveArray* genLegalMoves(Board*);