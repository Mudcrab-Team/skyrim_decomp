// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// AIProcess: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function6f1280: GUESS(low); provisional member name
// 0x6f1280 AIProcess::Function6f1280
// CI hash: 0x6f1280 ?Function6f1280@AIProcess@@QEAAXE@Z
#include "AIProcess_6f1280.h"

// Guess: Update a high-process byte unless the one-shot override is active.
void AIProcess::Function6f1280(std::uint8_t value)
{
    if (high) {
        if (!high->unknown456) {
            high->unknown455 = value;
        } else {
            high->unknown456 = 0;
        }
    }
}
