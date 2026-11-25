// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESRegion: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function24f980: GUESS(low); provisional member name
// 0x24f980 TESRegion::Function24f980
// CI hash: 0x24f980 ?Function24f980@TESRegion@@QEAAMXZ
#include "TESRegion_24f980.h"

// Guess: Accumulate an extreme region boundary over its point lists.
float TESRegion::Function24f980()
{
    float result = regionBound24f980;
    auto* item = points;
    while (item && item->point) {
        float value = item->point->Get();
        result = value > result ? value : result;
        item = item->next;
    }
    return result;
}
