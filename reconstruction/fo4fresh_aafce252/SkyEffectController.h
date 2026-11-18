// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ReferenceEffectControllers.cpp:512 (SkyEffectController::RemoveHitEffect)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ReferenceEffectControllers.cpp:524 (SkyEffectController::GetAttachRoot)
// NiAVObject, weatherRoot, GetAttachRoot: GUESS(low)
// SkyEffectController, RemoveHitEffect: GUESS(low)
#pragma once

// ReferenceEffect, Sky, RemoveReferenceEffect, effect: GUESS(low)
class ReferenceEffect;
class Sky { public: static void RemoveReferenceEffect(ReferenceEffect* effect); };
class NiAVObject;
extern NiAVObject* weatherRoot;
class SkyEffectController { public: NiAVObject* GetAttachRoot() const; void RemoveHitEffect(ReferenceEffect* effect); };
