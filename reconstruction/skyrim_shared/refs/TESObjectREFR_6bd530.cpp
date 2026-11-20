// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction of the observed settings and perk dispatch.
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// 0x6bd530 TESObjectREFR::CalculateFallDamage
#include "TESObjectREFR_6bd530.h"

#include <cmath>

// playerReference: GUESS(low)
extern TESObjectREFR* playerReference;

// fJumpFallHeightMin, fJumpFallHeightExponent, fJumpFallHeightMult: OBSERVED
extern float fJumpFallHeightMin;
extern float fJumpFallHeightExponent;
extern float fJumpFallHeightMult;

// fJumpFallHeightMinNPC, fJumpFallHeightExponentNPC, fJumpFallHeightMultNPC: OBSERVED
extern float fJumpFallHeightMinNPC;
extern float fJumpFallHeightExponentNPC;
extern float fJumpFallHeightMultNPC;

// BGSEntryPoint, HandleEntryPoint, kModFallingDamage: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
struct BGSEntryPoint
{
    enum ENTRY_POINT : std::uint32_t
    {
        kModFallingDamage = 58
    };

    static void HandleEntryPoint(ENTRY_POINT entryPoint, TESObjectREFR* subject, float* value);
};

float TESObjectREFR::CalculateFallDamage(float distance, float thresholdScale)
{
    float damage = 0.0f;
    if (distance > 0.0f) {
        if (GetSubmergeLevel(positionZ, parentCell) < 0.7f) {
            float minimum;
            float multiplier;
            float exponent;
            if (this == playerReference) {
                minimum = fJumpFallHeightMin;
                multiplier = fJumpFallHeightMult;
                exponent = fJumpFallHeightExponent;
            } else {
                minimum = fJumpFallHeightMinNPC;
                multiplier = fJumpFallHeightMultNPC;
                exponent = fJumpFallHeightExponentNPC;
            }

            minimum *= thresholdScale;
            if (distance > minimum) {
                damage = std::pow((distance - minimum) * multiplier, exponent);
                BGSEntryPoint::HandleEntryPoint(BGSEntryPoint::kModFallingDamage, this, &damage);
            }
        }
    }
    return damage;
}
