// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// Recipe: reconstruction/recipes/o2-fpfast.json
// hkFloatParseUtil: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functioncc1ac0: GUESS(low); provisional member name
// 0xcc1ac0 hkFloatParseUtil::Functioncc1ac0
// CI hash: 0xcc1ac0 ?Functioncc1ac0@hkFloatParseUtil@@SAPEA_NPEA_NMM@Z
#include "hkFloatParseUtil_cc1ac0.h"

// Guess: Compare floating-point classifications and finite values.
bool* hkFloatParseUtil::Functioncc1ac0(bool* output, float first, float second)
{
    int firstKind = FloatKind(first);
    int secondKind = FloatKind(second);
    if (firstKind != secondKind) { *output = false; }
    else { *output = firstKind != 5 || first == second; }
    return output;
}
