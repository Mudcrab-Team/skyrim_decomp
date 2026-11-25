// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// Actor: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function675600: GUESS(low); provisional member name
// 0x675600 Actor::Function675600
// CI hash: 0x675600 ?Function675600@Actor@@QEAAXXZ
#include "Actor_675600.h"

// Guess: Refresh the actor cached value and its state flag.
void Actor::Function675600()
{
    if(CheckState()) {
        if(state) {
            cached=state->value;
            bool enabled=state->Check();
            unsigned value=flags;
            if(enabled) { value|=0x4000; } else { value&=~0x4000u; }
            flags=value;
        }
    } else { flags&=~0x4000u; cached=0; }
}
