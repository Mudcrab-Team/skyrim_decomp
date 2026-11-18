// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// ReanimateEffect::SaveGame: SIBLING(fo4-private@1b765c70, author-permission); adapted to observed target behavior.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ReanimateEffect.cpp:69
// ReanimateEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/R/ReanimateEffect.h, include/RE/C/CommandEffect.h, and include/RE/A/ActiveEffect.h.
// names: GUESS(low); helper identity and argument names are inferred.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
class ActiveEffect; class MagicItem; class Effect; class MagicTarget; class TESBoundObject; class NiNode; class BGSSaveFormBuffer { public: void Write(const void*, unsigned, unsigned, unsigned); };
struct NiPoint3 { float x,y,z; }; class ReferenceEffectController { public: virtual ~ReferenceEffectController(); };
class ActiveEffectReferenceEffectController : public ReferenceEffectController { public: ActiveEffect* effect; unsigned target; NiPoint3 windPoint; };
struct BSSoundHandle { unsigned soundID; bool assumeSuccess; unsigned state; };
class ActiveEffect { public: virtual ~ActiveEffect(); ActiveEffectReferenceEffectController hitEffectController; BSSoundHandle persistentSound; unsigned caster; NiNode* sourceNode; MagicItem* spell; Effect* effect; MagicTarget* target; TESBoundObject* source; void* hitEffects; MagicItem* displacementSpell; float elapsedSeconds, duration, magnitude; unsigned flags, conditionStatus; unsigned short uniqueID, pad86; unsigned castingSource; };
class CommandEffect : public ActiveEffect { public: unsigned commandedActor; void SaveGame(BGSSaveFormBuffer*); };
class ReanimateEffect : public CommandEffect { public: bool gettingUp; void SaveGame(BGSSaveFormBuffer*); };
