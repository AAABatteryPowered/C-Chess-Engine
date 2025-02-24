#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "fen.h"
#include "../common.h"

u64 setBit(u64 N, int K)
{
	return (N | (1ULL << K));
}

Board* FenToBitboard(char fen[]) {
	Board* board = calloc(1, sizeof(Board));

	int bbPointer = 0;

	char codes[] = "RrNnBbQqKkPp";

	for (int i = 0;i < strlen(fen);i++) {
		int gap = fen[i] - '0';

		if (!(gap < 0 || gap > 8)) {
			bbPointer += gap;
		}
		else {
			//rooks
			if (fen[i] == codes[0]) {
				board->rooks = setBit(board->rooks, bbPointer);
				board->colours = setBit(board->colours, bbPointer);
				bbPointer++;
			} else if (fen[i] == codes[1]) {
				board->rooks = setBit(board->rooks, bbPointer);
				bbPointer++;
			}
			//knights
			else if (fen[i] == codes[2]) {
				board->knights = setBit(board->knights, bbPointer);
				board->colours = setBit(board->colours, bbPointer);
				bbPointer++;
			}
			else if (fen[i] == codes[3]) {
				board->knights = setBit(board->knights, bbPointer);
				bbPointer++;
			}
			//bishops
			else if (fen[i] == codes[4]) {
				board->bishops = setBit(board->bishops, bbPointer);
				board->colours = setBit(board->colours, bbPointer);
				bbPointer++;
			}
			else if (fen[i] == codes[5]) {
				board->bishops = setBit(board->bishops, bbPointer);
				bbPointer++;
			}
			//queens
			else if (fen[i] == codes[6]) {
				board->queens = setBit(board->queens, bbPointer);
				board->colours = setBit(board->colours, bbPointer);
				bbPointer++;
			}
			else if (fen[i] == codes[7]) {
				board->queens = setBit(board->queens, bbPointer);
				bbPointer++;
			}
			//kings
			else if (fen[i] == codes[8]) {
				board->kings = setBit(board->kings, bbPointer);
				board->colours = setBit(board->colours, bbPointer);
				bbPointer++;
			}
			else if (fen[i] == codes[9]) {
				board->kings = setBit(board->kings, bbPointer);
				bbPointer++;
			}
			//pawns
			else if (fen[i] == codes[10]) {
				board->pawns = setBit(board->pawns, bbPointer);
				board->colours = setBit(board->colours, bbPointer);
				bbPointer++;
			}
			else if (fen[i] == codes[11]) {
				board->pawns = setBit(board->pawns, bbPointer);
				bbPointer++;
			}
		}
	}

	return board;
}