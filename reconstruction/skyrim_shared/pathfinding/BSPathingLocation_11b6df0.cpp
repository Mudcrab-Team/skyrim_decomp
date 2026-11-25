// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSPathingLocation: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function11b6df0: GUESS(low); provisional member name
// 0x11b6df0 BSPathingLocation::Function11b6df0
// CI hash: 0x11b6df0 ?Function11b6df0@BSPathingLocation@@QEAA_NPEAUPath11b6df0@@@Z
#include "BSPathingLocation_11b6df0.h"

// Guess: Build the pathing output from the location or its fallback.
bool BSPathingLocation::Function11b6df0(Path11b6df0* output)
{
    if (output->storage) { output->count = 0; }
    if (location) { output->Build(&location); }
    else if (fallback) { fallback->Build(output); }
    return output->count != 0;
}
