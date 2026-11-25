// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// CombatBehaviorContextMagic: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function8b47f0: GUESS(low); provisional member name
// 0x8b47f0 CombatBehaviorContextMagic::Function8b47f0
// CI hash: 0x8b47f0 ?Function8b47f0@CombatBehaviorContextMagic@@QEAAPEAXPEAX@Z
#include "CombatBehaviorContextMagic_8b47f0.h"

// Guess: Copy the magic behavior thread context through its provider.
void* CombatBehaviorContextMagic::Function8b47f0(void* output)
{
    provider->Copy(output,magicThread8b47f0->context->value);
    return output;
}
