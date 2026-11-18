// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// EffectRotatesWithCamera: Sibling source: fo4-private@1b765c70 src/Game/Magic/ReferenceEffectControllers.cpp:155
// OwnedCameraEffectController, OwnedCameraEffectController::EffectRotatesWithCamera: SIBLING(fo4-private@1b765c70, author-permission)
// unknown00, health, lookFor, inheritRotation, minRange, maxRange, score, artObject: STANDIN GUESS(low)
#pragma once
#include <cstdint>
class CombatController;
class EffectItem;
class NiAVObject;
class OwnedCameraEffectController
{
public:
    bool EffectRotatesWithCamera() const;
private:
    std::uint64_t unknown00[6];
    bool inheritRotation;
};
