#include "../common.h"

u64 setBit(u64 N, int K) {
	 return (N | (1ULL << K));
}