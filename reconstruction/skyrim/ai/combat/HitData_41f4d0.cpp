// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// Adapted bodies: none
// 0x41f4d0 HitData::GetPercentageBlocked
#include "HitData_41f4d0.h"

// Computes the fraction of incoming hit damage absorbed by a block.
float HitData::GetPercentageBlocked(float skillFactor, float armorRating, float weaponWeight, bool isWeapon, bool isHandToHand, bool isPowerAttack)
{
    float base = ((fBlockSkillMax - fBlockSkillBase) * armorRating) * 0.01f + fBlockSkillBase;
    float result;
    if (!isHandToHand && !isWeapon)
    {
        result = (((base + weaponWeight) * skillFactor) * fBlockAmountWeaponMult) * 0.01f + fBlockAmountWeaponBase;
    }
    else
    {
        result = ((base * skillFactor) * fBlockAmountHandToHandMult) * 0.01f + fBlockAmountHandToHandBase;
    }

    if (isPowerAttack)
    {
        result *= fBlockPowerAttackMult;
    }
    return result;
}
