// Source exposure: mixed (pinned image listing and authorized sibling source).
// Code origin: existing sibling-adapted method plus original reconstruction of Function834190.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatMagicCaster.cpp:118
// CombatMagicCasterWard, GetObjectType: SIBLING(fo4-private@1b765c70, author-permission)
// CombatObjectBase, WardTarget, Function834190, unknown00, wardTarget, value38: STANDIN GUESS(low)
#pragma once
#include <cstdint>

class CombatObjectBase { public: static unsigned int GenerateClassType(const char*); };

struct WardTarget
{
    std::uint8_t unknown00[0x38];
    float value38;
};

class CombatMagicCasterWard
{
public:
    unsigned int GetObjectType() const;
    std::uint32_t Function834190() const;

    std::uint8_t unknown00[0x10];
    WardTarget* wardTarget;
};
