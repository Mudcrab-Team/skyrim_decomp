// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled in the header
// 0x7573c0 PlayerCharacter::UpdateLowHealthIMod
// Adapted bodies: none
#include "PlayerCharacter_7573c0.h"

void PlayerCharacter::UpdateLowHealthIMod(float healthFraction)
{
    bool low = g_lowHealthIModEnabled && !(healthFraction > g_lowHealthThreshold);
    if (low != g_lowHealthActive) {
        g_lowHealthActive = low;
        if (low) {
            g_lowHealthIntensity = g_lowHealthIntensityDefault;
        }
    }
}
