// Source exposure: binary-analysis
// Code origin: declarations and layout reconstruction using the labelled sources.
// EnchantmentItem, ModifyPower: CRASHLOGGER_PDB(59818@2026.10.24)
// enchantmentPowerScale, enchantmentSkillOffset, enchantmentSkillScale: GUESS(low); roles inferred from arithmetic
#pragma once

extern float enchantmentPowerScale;
extern const float enchantmentSkillOffset;
extern const float enchantmentSkillScale;

class EnchantmentItem
{
public:
    static float ModifyPower(float power, float skill);
};
