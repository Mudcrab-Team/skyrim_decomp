// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// Hazard: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function7ee900: GUESS(low); provisional member name
// 0x7ee900 Hazard::Function7ee900
// CI hash: 0x7ee900 ?Function7ee900@Hazard@@QEAAXXZ
#include "Hazard_7ee900.h"

// Guess: Update the active hazard when its lifetime is not negative.
void Hazard::Function7ee900()
{
    if (!Disabled() && !(time < 0.0f)) { Update(); }
}
