// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// PathingRequestFlee: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function4f4f00: GUESS(low); provisional member name
// 0x4f4f00 PathingRequestFlee::Function4f4f00
// CI hash: 0x4f4f00 ?Function4f4f00@PathingRequestFlee@@QEAAPEAV1@PEAUCopySource4f4f00@@@Z
#include "PathingRequestFlee_4f4f00.h"

// Guess: Copy a pathing request through the source interface.
PathingRequestFlee* PathingRequestFlee::Function4f4f00(CopySource4f4f00* source)
{
    source->CopyTo(this);
    return this;
}
