// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// GetAttached: Sibling source: fo4-private@1b765c70 src/Game/Magic/ModelReferenceEffect.cpp:291
// ModelReferenceEffect::GetAttached: SIBLING(fo4-private@1b765c70, author-permission)
// flags: STANDIN GUESS(low)
// Get3D: Sibling source: fo4-private@1b765c70 src/Game/Magic/ModelReferenceEffect.cpp:57
// ModelReferenceEffect, ModelReferenceEffect::Get3D: SIBLING(fo4-private@1b765c70, author-permission)
// unknown00, health, lookFor, inheritRotation, minRange, maxRange, score, artObject: STANDIN GUESS(low)
#pragma once
#include <cstdint>
class CombatController;
class EffectItem;
class NiAVObject;
class ModelReferenceEffect
{
public:
    NiAVObject* Get3D() const;
    bool GetAttached() const;
private:
    std::uint64_t unknown00[25];
    NiAVObject* artObject;
    std::uint32_t flags;
};
