// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// CalcCastMagicChance: Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatMagicCaster.cpp:46
// CalcMagicHoldTime: Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatMagicCaster.cpp:52
// CombatMagicCaster, CombatMagicCaster::CalcCastMagicChance, CombatMagicCaster::CalcMagicHoldTime: SIBLING(fo4-private@1b765c70, author-permission)
// 0x8334f0 CombatMagicCaster::CalcCastMagicChance
// 0x833500 CombatMagicCaster::CalcMagicHoldTime
#include "CombatMagicCaster_8334f0.h"

float CombatMagicCaster::CalcCastMagicChance(const CombatController*) const { return 1.0f; }
float CombatMagicCaster::CalcMagicHoldTime(const CombatController*) const { return 0.01f; }
