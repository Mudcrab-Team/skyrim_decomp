// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// AIProcess: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function6f2230: GUESS(low); provisional member name
// 0x6f2230 AIProcess::Function6f2230
// CI hash: 0x6f2230 ?Function6f2230@AIProcess@@QEAAXPEAX@Z
#include "AIProcess_6f2230.h"

// Guess: Set a high-process pointer when high-process data exists.
void AIProcess::Function6f2230(void* value)
{
    if (high) {
        high->unknown28 = value;
    }
}
