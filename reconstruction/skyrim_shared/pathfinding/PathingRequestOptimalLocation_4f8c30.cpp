// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// PathingRequestOptimalLocation: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function4f8c30: GUESS(low); provisional member name
// 0x4f8c30 PathingRequestOptimalLocation::Function4f8c30
// CI hash: 0x4f8c30 ?Function4f8c30@PathingRequestOptimalLocation@@QEAAPEAV1@PEAUCopySource4f8c30@@@Z
#include "PathingRequestOptimalLocation_4f8c30.h"

// Guess: Copy a pathing request through the source interface.
PathingRequestOptimalLocation* PathingRequestOptimalLocation::Function4f8c30(CopySource4f8c30* source)
{
    source->CopyTo(this);
    return this;
}
