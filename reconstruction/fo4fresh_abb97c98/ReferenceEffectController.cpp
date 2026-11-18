// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ReferenceEffectControllers.cpp:29 (ReferenceEffectController::GetElapsedTime)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ReferenceEffectControllers.cpp:56 (ReferenceEffectController::GetParticleAttachExtent)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ReferenceEffectControllers.cpp:32 (ReferenceEffectController::GetScale)
// ReferenceEffectController, GetElapsedTime, GetParticleAttachExtent, GetScale: GUESS(low)
// 0x5dbea0 ReferenceEffectController::GetElapsedTime
// 0x5dbf60 ReferenceEffectController::GetParticleAttachExtent
// 0x5dbeb0 ReferenceEffectController::GetScale
#include "ReferenceEffectController.h"

float ReferenceEffectController::GetElapsedTime() const
{
    return 0.0f;
}

float ReferenceEffectController::GetParticleAttachExtent()
{
    return 0.0f;
}

float ReferenceEffectController::GetScale() const
{
    return 1.0f;
}

