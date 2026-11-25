// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESObjectREFR: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function2df5d0: GUESS(low); provisional member name
// 0x2df5d0 TESObjectREFR::Function2df5d0
// CI hash: 0x2df5d0 ?Function2df5d0@TESObjectREFR@@QEAA_NPEAV1@@Z
#include "TESObjectREFR_2df5d0.h"

// Guess: Query and classify the numeric values of two reference bases.
bool TESObjectREFR::Function2df5d0(TESObjectREFR* other)
{
    if (other) {
        double value = base ? base->Value() : 1.0f;
        if (Classify2df5d0(value)) { Normalize2df5d0(value); }
        double second = other->base ? other->base->Value() : 1.0f;
        if (Classify2df5d0(second)) { Normalize2df5d0(second); }
    }
    return true;
}
