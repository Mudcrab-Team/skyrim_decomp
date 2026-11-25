// 0x421850 EnchantmentItem::ModifyPower
// Source exposure: binary-analysis
// Code origin: reconstruction using the labelled sources and pinned-image observations.
// EnchantmentItem, ModifyPower: CRASHLOGGER_PDB(59818@2026.10.24)
// enchantmentPowerScale, enchantmentSkillOffset, enchantmentSkillScale: GUESS(low); arithmetic roles only
#include "EnchantmentItem_421850.h"

float EnchantmentItem::ModifyPower(float power, float skill)
{
    const float scale = enchantmentPowerScale - 1.0f;
    const float skillFactor = skill * 0.01f;
    const float adjustedSkill = (skill - enchantmentSkillOffset) * enchantmentSkillScale;
    const float limitedSkill = adjustedSkill > 0.01f ? adjustedSkill : 0.01f;
    return (skillFactor * scale * limitedSkill + 1.0f) * power;
}
