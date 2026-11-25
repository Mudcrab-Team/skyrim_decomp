// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BipedAnim: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function21aff0: GUESS(low); provisional member name
// 0x21aff0 BipedAnim::Function21aff0
// CI hash: 0x21aff0 ?Function21aff0@BipedAnim@@QEAAXXZ
#include "BipedAnim_21aff0.h"

// Guess: Apply the biped state when updates are enabled.
void BipedAnim::Function21aff0()
{
    if (!disable21aff0) { Apply(&state, true, 0); }
}
