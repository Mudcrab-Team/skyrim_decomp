// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted from include/RE/R/ReanimateEffect.h, RE/C/CommandEffect.h, RE/A/ActiveEffect.h, ActiveEffectReferenceEffectController.h, RE/R/ReferenceEffectController.h and RE/B/BSSoundHandle.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// names: GUESS(low); read helper and boolean meaning are inferred.
#pragma once
class ActiveEffect; class MagicItem; class Effect; class MagicTarget; class TESBoundObject; class NiNode; class BGSLoadFormBuffer { public: void LoadDataEndian(void*, unsigned, unsigned); };
struct NiPoint3 { float x,y,z; }; class ReferenceEffectController { public: virtual ~ReferenceEffectController(); };
class ActiveEffectReferenceEffectController : public ReferenceEffectController { public: ActiveEffect* effect; unsigned target; NiPoint3 windPoint; };
struct BSSoundHandle { unsigned soundID; bool assumeSuccess; unsigned state; };
class ActiveEffect { public: virtual ~ActiveEffect(); ActiveEffectReferenceEffectController hitEffectController; BSSoundHandle persistentSound; unsigned caster; NiNode* sourceNode; MagicItem* spell; Effect* effect; MagicTarget* target; TESBoundObject* source; void* hitEffects; MagicItem* displacementSpell; float elapsedSeconds, duration, magnitude; unsigned flags, conditionStatus; unsigned short uniqueID, pad86; unsigned castingSource; };
class CommandEffect : public ActiveEffect { public: unsigned commandedActor; void LoadGame(BGSLoadFormBuffer*); };
class ReanimateEffect : public CommandEffect { public: bool gettingUp; void LoadGame(BGSLoadFormBuffer*); };
