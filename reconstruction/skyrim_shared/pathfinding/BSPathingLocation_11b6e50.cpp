// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSPathingLocation: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function11b6e50: GUESS(low); provisional member name
// 0x11b6e50 BSPathingLocation::Function11b6e50
// CI hash: 0x11b6e50 ?Function11b6e50@BSPathingLocation@@QEAA_NPEAPEAURef11b6e50@@@Z
#include "BSPathingLocation_11b6e50.h"

// Guess: Release the old output and resolve the pathing location anew.
bool BSPathingLocation::Function11b6e50(Ref11b6e50** output)
{
    auto* previous = *output;
    if (previous) {
        *output = nullptr;
    // Balance the shared reference atomically.
        if (_InterlockedExchangeAdd(&previous->references, -1) == 1) { delete previous; }
    }
    if (location) { location->Resolve(output); }
    return *output != nullptr;
}
