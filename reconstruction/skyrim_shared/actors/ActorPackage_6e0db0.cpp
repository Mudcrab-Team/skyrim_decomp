// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ActorPackage: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function6e0db0: GUESS(low); provisional member name
// 0x6e0db0 ActorPackage::Function6e0db0
// CI hash: 0x6e0db0 ?Function6e0db0@ActorPackage@@QEAAXPEBUOverride6e0db0@@@Z
#include "ActorPackage_6e0db0.h"

// Guess: Merge package defaults with the supplied flag overrides.
void ActorPackage::Function6e0db0(const Override6e0db0* change)
{
    flags = package->flags;
    flags2 = package->flags2;
    mode = package->GetMode();
    if (change) {
        flags &= ~change->clear;
        flags2 &= ~change->clear2;
        flags |= change->set;
        flags2 |= change->set2;
        if (change->set & 0x2000) { mode = change->mode; }
    }
}
