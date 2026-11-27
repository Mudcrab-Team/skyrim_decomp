// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// Recipe: reconstruction/recipes/o2-fpfast.json
// hkFloatParseUtil: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functioncc1ac0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// FloatKind: GUESS(low); floating-point value classification
extern "C" int FloatKind(float);

class hkFloatParseUtil
{
public:

    static bool* Functioncc1ac0(bool* output, float first, float second);
};
