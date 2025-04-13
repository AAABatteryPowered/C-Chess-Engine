#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "fen.h"
#include "../common.h"
#include "../bit/bit.h"

void setBitOnBoard(u64* board, int8_t* bit) {   
	*board = setBit(*board, *bit);
	(*bit)++;
}

Board* FenToBitboard(char fen[], int turnToMove) {
	Board* board = calloc(1, sizeof(Board));

	if (board == NULL) {
		return 0;
	}

	int8_t bbPointer = 0;

	char codes[] = "RrNnBbQqKkPp";

	board->turnToMove = turnToMove;

	for (int i = 0;i < strlen(fen);i++) {
		int gap = fen[i] - '0';

		if (!(gap < 0 || gap > 8)) {
			bbPointer += gap;
		}
		else {
			if (fen[i] == codes[0]) setBitOnBoard(&board->white_rooks, &bbPointer);
			if (fen[i] == codes[1]) setBitOnBoard(&board->black_rooks, &bbPointer);
			if (fen[i] == codes[2]) setBitOnBoard(&board->white_knights, &bbPointer);
			if (fen[i] == codes[3]) setBitOnBoard(&board->black_knights, &bbPointer);
			if (fen[i] == codes[4]) setBitOnBoard(&board->white_bishops, &bbPointer);
			if (fen[i] == codes[5]) setBitOnBoard(&board->black_bishops, &bbPointer);
			if (fen[i] == codes[6]) setBitOnBoard(&board->white_queens, &bbPointer);
			if (fen[i] == codes[7]) setBitOnBoard(&board->black_queens, &bbPointer);
			if (fen[i] == codes[8]) setBitOnBoard(&board->white_kings, &bbPointer);
			if (fen[i] == codes[9]) setBitOnBoard(&board->black_kings, &bbPointer);
			if (fen[i] == codes[10]) setBitOnBoard(&board->white_pawns, &bbPointer);
			if (fen[i] == codes[11]) setBitOnBoard(&board->black_pawns, &bbPointer);
		}
	}

	return board;
}