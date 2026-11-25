// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// AIProcess: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function6ff270: GUESS(low); provisional member name
// 0x6ff270 AIProcess::Function6ff270
// CI hash: 0x6ff270 ?Function6ff270@AIProcess@@QEAAXAEBUPoint6ff270@@@Z
#include "AIProcess_6ff270.h"

// Guess: Set and normalize a high-process vector.
void AIProcess::Function6ff270(const Point6ff270& value)
{
    if (high) {
        high->point = value;
        high->point.Normalize();
    }
}
