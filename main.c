#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "fen/fen.h"
#include "legalmoves/legalmoves.h"

int main() {
	Board* bb = FenToBitboard("RNBQKBNR/PPPPPPPP/8/8/8/8/pppppppp/rnbqkbnr", 1);

	printf("black queens are %llu", bb->black_queens);

	return 0;
}