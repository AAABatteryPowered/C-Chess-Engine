#pragma once

#include "../common.h"

u64 setBit(u64 N, int K);

#define CHECK_BIT(var,pos) (((var)>>(pos)) & 1)