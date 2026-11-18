// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ReferenceEffectControllers.cpp:29 (ReferenceEffectController::GetElapsedTime)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ReferenceEffectControllers.cpp:56 (ReferenceEffectController::GetParticleAttachExtent)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ReferenceEffectControllers.cpp:32 (ReferenceEffectController::GetScale)
// ReferenceEffectController, GetElapsedTime, GetParticleAttachExtent, GetScale: GUESS(low)
#pragma once

class ReferenceEffectController
{
public:
    float GetElapsedTime() const;
    float GetParticleAttachExtent();
    float GetScale() const;
};
