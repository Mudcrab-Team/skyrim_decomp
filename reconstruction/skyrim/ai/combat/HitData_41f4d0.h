// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// HitData, GetPercentageBlocked: CRASHLOGGER_PDB(59818@2026.10.24)
// fBlockSkillMax, fBlockSkillBase, fBlockAmountWeaponMult, fBlockAmountWeaponBase, fBlockAmountHandToHandMult, fBlockAmountHandToHandBase, fBlockPowerAttackMult: GUESS(low)
#pragma once

class HitData
{
public:
    static float GetPercentageBlocked(float skillFactor, float armorRating, float weaponWeight, bool isWeapon, bool isHandToHand, bool isPowerAttack);

    static float fBlockSkillMax;
    static float fBlockSkillBase;
    static float fBlockAmountWeaponMult;
    static float fBlockAmountWeaponBase;
    static float fBlockAmountHandToHandMult;
    static float fBlockAmountHandToHandBase;
    static float fBlockPowerAttackMult;
};
