// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ReferenceEffectControllers.cpp:512 (SkyEffectController::RemoveHitEffect)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ReferenceEffectControllers.cpp:524 (SkyEffectController::GetAttachRoot)
// SkyEffectController, RemoveHitEffect: GUESS(low)
// 0x5dd1d0 SkyEffectController::RemoveHitEffect
// 0x5dd1e0 SkyEffectController::GetAttachRoot
#include "SkyEffectController.h"

void SkyEffectController::RemoveHitEffect(ReferenceEffect* effect) { Sky::RemoveReferenceEffect(effect); }

NiAVObject* SkyEffectController::GetAttachRoot() const { return weatherRoot; }
