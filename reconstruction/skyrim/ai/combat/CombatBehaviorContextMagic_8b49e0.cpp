// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// CombatBehaviorContextMagic: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function8b49e0: GUESS(low); provisional member name
// 0x8b49e0 CombatBehaviorContextMagic::Function8b49e0
// CI hash: 0x8b49e0 ?Function8b49e0@CombatBehaviorContextMagic@@QEAA_NXZ
#include "CombatBehaviorContextMagic_8b49e0.h"

// Guess: Accept a missing combat state or query the existing state.
bool CombatBehaviorContextMagic::Function8b49e0()
{
    return state ? state->Check() : true;
}
