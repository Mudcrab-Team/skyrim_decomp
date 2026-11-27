// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// Actor: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function6a7f00: GUESS(low); provisional member name
// 0x6a7f00 Actor::Function6a7f00
// CI hash: 0x6a7f00 ?Function6a7f00@Actor@@SAXXZ
#include "Actor_6a7f00.h"

// Guess: Initialize shared actor storage on first use.
void Actor::Function6a7f00()
{
    if (!singleton6a7f00) { singleton6a7f00 = storage6a7f00.Initialize(); }
}
