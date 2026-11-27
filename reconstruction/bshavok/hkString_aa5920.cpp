// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// hkString: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionaa5920: GUESS(low); provisional member name
// 0xaa5920 hkString::Functionaa5920
// CI hash: 0xaa5920 ?Functionaa5920@hkString@@SAHPEBD0I@Z
#include "hkString_aa5920.h"

// Guess: Compare at most count characters through the imported string routine.
int hkString::Functionaa5920(const char* left, const char* right, unsigned count)
{
    return CompareBounded(left, right, count);
}
