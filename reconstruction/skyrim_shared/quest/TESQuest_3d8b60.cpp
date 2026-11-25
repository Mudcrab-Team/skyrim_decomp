// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESQuest: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function3d8b60: GUESS(low); provisional member name
// 0x3d8b60 TESQuest::Function3d8b60
// CI hash: 0x3d8b60 ?Function3d8b60@TESQuest@@QEAA_NXZ
#include "TESQuest_3d8b60.h"

// Guess: Test whether a condition in the quest chain succeeds.
bool TESQuest::Function3d8b60()
{
    bool found = false;
    auto* item = &conditions;
    while (item && !found) {
        if (item->value && item->value->Check()) { found = true; }
        item = item->next;
    }
    return found;
}
