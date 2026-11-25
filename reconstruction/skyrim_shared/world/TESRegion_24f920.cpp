// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESRegion: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function24f920: GUESS(low); provisional member name
// 0x24f920 TESRegion::Function24f920
// CI hash: 0x24f920 ?Function24f920@TESRegion@@QEAAMXZ
#include "TESRegion_24f920.h"

// Guess: Accumulate an extreme region boundary over its point lists.
float TESRegion::Function24f920()
{
    float result = regionBound24f920;
    auto* item = points;
    while (item && item->point) {
        float value = item->point->Get();
        result = value < result ? value : result;
        item = item->next;
    }
    return result;
}
