// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// Actor: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function693940: GUESS(low); provisional member name
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x693940 Actor::Function693940
// CI hash: 0x693940 ?Function693940@Actor@@QEAAX_N@Z
#include "Actor_693940.h"

// Guess: Enable the actor mode or restore its state and numeric value on disabling.
void Actor::Function693940(bool enabled)
{
    if (enabled) { SetState(false); SetMode(7); return; }
    if ((flags & 0x1e00000) == 0xe00000) {
        SetMode(0);
        if (!manager693940->Busy()) {
            float value = ReadValue(2, 24);
            if (value < 0.0f) { SetValue(24, 1.0f - value); }
        }
        state &= ~0x40u;
    }
}
