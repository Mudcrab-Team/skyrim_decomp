// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// PlayerCharacter: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function751810: GUESS(low); provisional member name
// 0x751810 PlayerCharacter::Function751810
// CI hash: 0x751810 ?Function751810@PlayerCharacter@@QEAAXM@Z
#include "PlayerCharacter_751810.h"

// Guess: Compute the enabled player value from its defaults and adjustment.
void PlayerCharacter::Function751810(float value)
{
    if (value > 0.0f) {
        amount = defaultAmount751810;
        AdjustPlayerValue(0x17, this, &amount);
        amount *= multiplier751810;
    } else { amount = 0.0f; }
}
