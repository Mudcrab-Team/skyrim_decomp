// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESRegion: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function24f9e0: GUESS(low); provisional member name
// 0x24f9e0 TESRegion::Function24f9e0
// CI hash: 0x24f9e0 ?Function24f9e0@TESRegion@@QEAAMXZ
#include "TESRegion_24f9e0.h"

// Guess: Accumulate an extreme region boundary over its point lists.
float TESRegion::Function24f9e0()
{
    float result = regionBound24f9e0;
    auto* item = points;
    while (item && item->point) {
        float value = item->point->Get();
        result = value < result ? value : result;
        item = item->next;
    }
    return result;
}
