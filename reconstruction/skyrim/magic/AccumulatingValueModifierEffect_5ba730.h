// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// AccumulatingValueModifierEffect::ModifyOnFinish: SIBLING(fo4-private@1b765c70, author-permission); adapted to observed target behavior.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/AccumulatingValueModifierEffect.cpp:123
// AccumulatingValueModifierEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/A/AccumulatingValueModifierEffect.h, include/RE/V/ValueModifierEffect.h and include/RE/A/ActiveEffect.h.
// names: GUESS(low); method signature and argument names are inferred.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
class ActiveEffect; class MagicItem; class Effect; class MagicTarget; class TESBoundObject; class NiNode; class Actor;
struct NiPoint3 { float x,y,z; }; class ReferenceEffectController { public: virtual ~ReferenceEffectController(); };
class ActiveEffectReferenceEffectController : public ReferenceEffectController { public: ActiveEffect* effect; unsigned target; NiPoint3 windPoint; };
struct BSSoundHandle { unsigned soundID; bool assumeSuccess; unsigned state; };
class ActiveEffect { public: virtual ~ActiveEffect(); float GetMagnitude(); ActiveEffectReferenceEffectController hitEffectController; BSSoundHandle persistentSound; unsigned caster; NiNode* sourceNode; MagicItem* spell; Effect* effect; MagicTarget* target; TESBoundObject* source; void* hitEffects; MagicItem* displacementSpell; float elapsedSeconds, duration, magnitude; unsigned flags, conditionStatus; unsigned short uniqueID, pad86; unsigned castingSource; };
class ValueModifierEffect : public ActiveEffect { public: void ModifyOnFinish(Actor*, Actor*, float); unsigned actorValue; float value; };
class AccumulatingValueModifierEffect : public ValueModifierEffect { public: void ModifyOnFinish(Actor*, Actor*, float); float accumulatedMagnitude, maximumMagnitude, holdTimer; };
