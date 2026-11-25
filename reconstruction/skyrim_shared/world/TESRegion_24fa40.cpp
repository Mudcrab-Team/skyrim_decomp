// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESRegion: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function24fa40: GUESS(low); provisional member name
// 0x24fa40 TESRegion::Function24fa40
// CI hash: 0x24fa40 ?Function24fa40@TESRegion@@QEAAMXZ
#include "TESRegion_24fa40.h"

// Guess: Accumulate an extreme region boundary over its point lists.
float TESRegion::Function24fa40()
{
    float result = regionBound24fa40;
    auto* item = points;
    while (item && item->point) {
        float value = item->point->Get();
        result = value > result ? value : result;
        item = item->next;
    }
    return result;
}
