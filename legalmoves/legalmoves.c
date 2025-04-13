#include <stdio.h>
#include <stdlib.h>

#include "../bit/bit.h"
#include "legalmoves.h"

MoveArray* createArray() {
	MoveArray* arr = calloc(1, sizeof(MoveArray));
	if (arr != NULL) {
		arr->size = 0;
		arr->moves = calloc(2, sizeof(Move));
		if (arr == NULL) {
			free(arr);
			return NULL;
		}
	}

	return arr;
}

void GenerateAllPieceMoves(PieceMoves* pmoves) {
	for (int i = 0;i < 64;i++) {
		if ((i > 7) && (i < 23)) {
			pmoves->pawn[i] = setBit(pmoves->pawn[i], i + 16);
		}
		
	}
}

void appendToArray(MoveArray* arr, Move val) {

	if ((arr->size * sizeof(Move) >= sizeof(*arr))) {
		size_t newSize = sizeof(*arr) + sizeof(Move);
		void* newArr = realloc(arr->moves, sizeof(Move) * newSize);
		if (NULL == newArr) {
			return 0;
		}
		else {
			arr->moves = (Move**)newArr;
		}

	}

	arr->moves[arr->size] = val;
	++arr->size;


	return 1;
}

void calcKnightXray(u64* board) {
	for (int i = 0; i < 64; i++) {
		/*if (i == 7) {
			setBit(board[i], 13);
			setBit(board[i], 22);
		} else if (i == 63) {
			setBit(board[i], 53);
			setBit(board[i], 46);
		} else if (i == 0) {
			setBit(board[i], 10);
			setBit(board[i], 17);
		} else if (i == 56) {
			setBit(board[i], 50);
			setBit(board[i], 41);
		} else if (i % 8 == 0) {
			setBit(board[i], i - 6);
			setBit(board[i], i + 10);
		} else if (i + 1 % 8 == 0) {
			setBit(board[i], i + 6);
			setBit(board[i], i - 10);
		} else if (i < 8 && i > -1) {
			setBit(board[i], i + 17);
			setBit(board[i], i + 15);
		} else if (i < 64 && i > 55) {
			setBit(board[i], i - 17);
			setBit(board[i], i - 15);
		} else {

		}
		board[i] ^= board[i] << 1;
		board[i] ^= board[i] >> 1;
		board[i] ^= board[i] << 7;
		board[i] ^= board[i] >> 7;
		board[i] ^= board[i] << 8;
		board[i] ^= board[i] >> 8;
		board[i] ^= board[i] << 9;
		board[i] ^= board[i] >> 9;
	}
}

int checkIfKnightMoveIsLegal(int i, int inc,  int knightcolour, u64 colours) {
	if (!(CHECK_BIT(colours, i + inc) == knightcolour) && i + inc > -1) {
		return 1;
	}
	return 0;
}

MoveArray* genLegalMoves(Board* board) {
	MoveArray* legalMovesArray = createArray();
	int counter = 1;

	for (int i = 0;i < 64;i++) {
		if (CHECK_BIT(board->colours, i) == board->turnToMove) {
			if (CHECK_BIT(board->pawns, i) == 12) {
				if (board->turnToMove == 1) {
					if (i < 23 && i > 7) {
						if ((CHECK_BIT(board->emptysquares, i+16)) && (CHECK_BIT(board->emptysquares, i + 8))) {
							Move genmove = { i, i + 16 };
							appendToArray(legalMovesArray, genmove);
							counter++;
						}
					}
					if ((i < 56) && (CHECK_BIT(board->emptysquares, i + 8))) {
						Move genmove = { i, i + 8 };
						appendToArray(legalMovesArray, genmove);
						counter++;
					}
				}
				else {
					if (i < 40 && i > 63) {
						if ((CHECK_BIT(board->emptysquares, i - 16)) && (CHECK_BIT(board->emptysquares, i - 8))) {
							Move genmove = { i, i - 16 };
							appendToArray(legalMovesArray, genmove);
							counter++;
						}
					}
					if ((i > 7) && (CHECK_BIT(board->emptysquares, i - 8))) {
						Move genmove = { i, i - 8 };
						appendToArray(legalMovesArray, genmove);
						counter++;
					}
				}
			}
			else if (CHECK_BIT(board->knights, i) == 1) {
				if (checkIfKnightMoveIsLegal(i, 10, board->turnToMove, board->colours)) {
					Move genmove = { i, i + 10 };
					appendToArray(legalMovesArray, genmove);
					counter++;
				}
				if (checkIfKnightMoveIsLegal(i, -10, board->turnToMove, board->colours)) {
					Move genmove = { i, i - 10 };
					appendToArray(legalMovesArray, genmove);
					counter++;
				}
				if (checkIfKnightMoveIsLegal(i, 6, board->turnToMove, board->colours)) {
					Move genmove = { i, i + 6 };
					appendToArray(legalMovesArray, genmove);
					counter++;
				}
				if (checkIfKnightMoveIsLegal(i, -6, board->turnToMove, board->colours)) {
					Move genmove = { i, i - 6};
					appendToArray(legalMovesArray, genmove);
					counter++;
				}
				if (checkIfKnightMoveIsLegal(i, 17, board->turnToMove, board->colours)) {
					Move genmove = { i, i + 17 };
					appendToArray(legalMovesArray, genmove);
					counter++;
				}
				if (checkIfKnightMoveIsLegal(i, 15, board->turnToMove, board->colours)) {
					Move genmove = { i, i + 15 };
					appendToArray(legalMovesArray, genmove);
					counter++;
				}
				if (checkIfKnightMoveIsLegal(i, -17, board->turnToMove, board->colours)) {
					Move genmove = { i, i - 17 };
					appendToArray(legalMovesArray, genmove);
					counter++;
				}
				if (checkIfKnightMoveIsLegal(i, -15, board->turnToMove, board->colours)) {
					Move genmove = { i, i - 15 };
					appendToArray(legalMovesArray, genmove);
					counter++;
				}
			}
		}
	}

	return legalMovesArray;
}
*/