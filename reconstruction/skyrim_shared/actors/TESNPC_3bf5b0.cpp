// TESNPC, Function3bf5b0, Function3c8bd0, GetState, stateZero, stateNonzero, Cache, cache: GUESS(low)
// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis (local binary analysis only).
// 0x3bf5b0 TESNPC::Function3bf5b0
// 0x3c8bd0 TESNPC::Function3c8bd0

#include "TESNPC_3bf5b0.h"
float TESNPC::Function3bf5b0() { if (GetState() == 0) return stateZero; return stateNonzero; }
void TESNPC::Function3c8bd0() { if (cache) { delete cache; cache = nullptr; } }
