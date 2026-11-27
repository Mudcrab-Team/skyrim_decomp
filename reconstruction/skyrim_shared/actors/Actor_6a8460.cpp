// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// Actor: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function6a8460: GUESS(low); provisional member name
// 0x6a8460 Actor::Function6a8460
// CI hash: 0x6a8460 ?Function6a8460@Actor@@QEAAHXZ
#include "Actor_6a8460.h"

// Guess: Perform the process-dependent actor update and return success.
int Actor::Function6a8460()
{
    if (process && !process->flag) { Update(); }
    return 1;
}
