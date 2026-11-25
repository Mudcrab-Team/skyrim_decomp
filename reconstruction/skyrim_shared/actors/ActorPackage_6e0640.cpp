// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ActorPackage: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function6e0640: GUESS(low); provisional member name
// 0x6e0640 ActorPackage::Function6e0640
// CI hash: 0x6e0640 ?Function6e0640@ActorPackage@@QEAAXXZ
#include "ActorPackage_6e0640.h"

// Guess: Release the attached package if present.
void ActorPackage::Function6e0640()
{
    if (package) { package->Release(); }
}
