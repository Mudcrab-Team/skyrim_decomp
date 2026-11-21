// Source exposure: mixed (pinned image and public declarations).
// Code origin: original reconstruction of the player-specific fall-damage caller.
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// 0x679990 PlayerCharacter::ApplyShortFallDamage
#include "PlayerCharacter_679990.h"

void PlayerCharacter::ApplyShortFallDamage()
{
    if (auto* process = currentProcess) {
        if (auto* controller = process->GetController()) {
            const auto damage = CalculateFallDamage(controller->GetFallDistance(), 0.25f);
            if (damage > 0.0f) {
                return DamageHealth(damage, nullptr, false);
            }
        }
    }
}
