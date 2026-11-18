// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// ReferenceEffectController::GetIsRootActor: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ReferenceEffectControllers.cpp:5
// ReferenceEffectController, TESForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/R/ReferenceEffectController.h and include/RE/T/TESForm.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
class TESObjectREFR { public: virtual ~TESObjectREFR(); void* files; unsigned flags, id; unsigned short inGameFlags; unsigned char formType, pad; unsigned pad2; };
class ReferenceEffectController { public:
 virtual ~ReferenceEffectController();
 virtual void HandleEvent(const char*);
 virtual float GetElapsedTime();
 virtual float GetScale();
 virtual void SwitchAttachedRoot(void*, void*);
 virtual const void* GetSourcePosition();
 virtual bool GetUseSourcePosition();
 virtual bool GetNoInitialFlare();
 virtual bool GetEffectPersists();
 virtual bool GetGoryVisuals();
 virtual void RemoveHitEffect(void*);
 virtual TESObjectREFR* GetTargetReference();
 bool GetIsRootActor();
};
