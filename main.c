#include <stdio.h>
#include <math.h>

#include "fen/fen.h"


int main() {
	Board* bb = FenToBitboard("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");

	printf("%llu", bb->pawns);

	//printf("the amount of white rooks on the board is %i", (*pos).whiteRooks);

	return 0;
}