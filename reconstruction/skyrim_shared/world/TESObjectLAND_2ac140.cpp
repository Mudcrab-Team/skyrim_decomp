// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESObjectLAND: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function2ac140: GUESS(low); provisional member name
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x2ac140 TESObjectLAND::Function2ac140
// CI hash: 0x2ac140 ?Function2ac140@TESObjectLAND@@QEAA_NEM@Z
#include "TESObjectLAND_2ac140.h"

// Guess: Remove terrain layers whose weight lies below the threshold.
bool TESObjectLAND::Function2ac140(unsigned char quadrant, float threshold)
{
    bool changed = false;
    if (quadrant < 4) {
        for (unsigned short layer = 0; layer < 5; ++layer) {
            if (ReadWeight(quadrant, layer) < threshold) {
                ClearWeight2ac140(quadrant, layer, data);
                Refresh();
                changed = true;
            }
        }
    }
    return changed;
}
