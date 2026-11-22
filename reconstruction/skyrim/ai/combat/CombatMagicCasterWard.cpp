// Source exposure: mixed (pinned image listing and authorized sibling source).
// Code origin: existing sibling-adapted method plus original reconstruction of Function834190.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatMagicCaster.cpp:118
// Adapted bodies: GetObjectType from fo4-private@1b765c70; Function834190 original.
// 0x850ef0 CombatMagicCasterWard::GetObjectType
// 0x834190 CombatMagicCasterWard::Function834190
#include "CombatMagicCasterWard.h"

unsigned int CombatMagicCasterWard::GetObjectType() const
{
    static unsigned int classType = CombatObjectBase::GenerateClassType("CombatMagicCasterWard");
    return classType;
}

std::uint32_t CombatMagicCasterWard::Function834190() const
{
    return (wardTarget->value38 < 30.0f) ? 3u : 2u;
}
