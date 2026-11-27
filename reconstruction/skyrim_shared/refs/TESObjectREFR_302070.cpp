// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESObjectREFR: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function302070: GUESS(low); provisional member name
// 0x302070 TESObjectREFR::Function302070
// CI hash: 0x302070 ?Function302070@TESObjectREFR@@QEAA_NXZ
#include "TESObjectREFR_302070.h"

// Guess: Detect whether the reference links return to this reference.
bool TESObjectREFR::Function302070()
{
    auto* current = extra.GetNext(0);
    while (current) {
        if (this == current) { return true; }
        current = current->extra.GetNext(0);
    }
    return false;
}
