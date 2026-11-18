// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/C/CloakEffect.h, RE/A/ActiveEffect.h, ActiveEffectReferenceEffectController.h, RE/R/ReferenceEffectController.h and RE/B/BSSoundHandle.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// names: GUESS(low); tick import and helper identities inferred from target.
#pragma once
class ActiveEffect; class MagicItem; class Effect; class MagicTarget; class TESBoundObject; class NiNode; class ReferenceEffect;
struct NiPoint3 { float x,y,z; }; class ReferenceEffectController { public: virtual ~ReferenceEffectController(); };
class ActiveEffectReferenceEffectController : public ReferenceEffectController { public: ActiveEffect* effect; unsigned target; NiPoint3 windPoint; };
struct BSSoundHandle { unsigned soundID; bool assumeSuccess; unsigned state; };
class ActiveEffect { public: virtual ~ActiveEffect(); ActiveEffectReferenceEffectController hitEffectController; BSSoundHandle persistentSound; unsigned caster; NiNode* sourceNode; MagicItem* spell; Effect* effect; MagicTarget* target; TESBoundObject* source; void* hitEffects; MagicItem* displacementSpell; float elapsedSeconds, duration, magnitude; unsigned flags, conditionStatus; unsigned short uniqueID, pad86; unsigned castingSource; };
extern "C" __declspec(dllimport) unsigned long long __stdcall GetTickCount64();
class CloakEffect : public ActiveEffect { public: unsigned long long nextTargetCheck; void FindTargets(float); void Update(float); };
