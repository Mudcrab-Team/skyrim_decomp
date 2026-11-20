// TESNPC, Function3bf5b0, Function3c8bd0, GetState, stateZero, stateNonzero, Cache, cache: GUESS(low)
// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis (local binary analysis only).

#pragma once
// TESNPC, Function3bf5b0, Function3c8bd0, GetState, stateZero, stateNonzero, Cache, cache: GUESS(low)
class Cache { public: virtual ~Cache(); };
extern Cache* cache;
extern const float stateZero;
extern const float stateNonzero;
class TESNPC { public:
    int GetState();
    float Function3bf5b0();
    static void Function3c8bd0();
};
