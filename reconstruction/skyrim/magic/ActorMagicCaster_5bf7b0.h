// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// ActorMagicCaster::FinishCastImpl: SIBLING(fo4-private@1b765c70, author-permission); adapted to observed target behavior.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ActorMagicCaster.cpp:451
// ActorMagicCaster: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/A/ActorMagicCaster.h, include/RE/M/MagicCaster.h, include/RE/R/RefAttachTechniqueInput.h, include/RE/A/AttachTechniqueInput.h and include/RE/S/SimpleAnimationGraphManagerHolder.h.
// names: GUESS(low); actor helper identities and signatures are inferred.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
class Actor { public: void SetWantCasting(unsigned, bool); void SetDualCasting(bool); };
class MagicItem; class NiNode; class TESRace; class bhkWorld; class BGSArtObjectCloneTask; class BSLight; class BGSArtObject; class ReferenceEffectController; class SimpleAnimationGraphManagerLoadingTask; class BSAnimationGraphManager;
struct ArrayStorage { void* data; unsigned capacity; }; struct ArrayCount { unsigned size; }; struct SoundArray : ArrayStorage, ArrayCount {};
class MagicCaster { public: virtual ~MagicCaster(); SoundArray sounds; unsigned desiredTarget; MagicItem* currentSpell; unsigned state; float castingTimer, currentSpellCost, magnitudeOverride, nextTargetUpdate, projectileTimer; };
class SimpleAnimationGraphManagerHolder { public: virtual ~SimpleAnimationGraphManagerHolder(); BSAnimationGraphManager* animationGraphManager; SimpleAnimationGraphManagerLoadingTask* loadingTask; };
class AnimationGraphEventSink { public: virtual ~AnimationGraphEventSink(); };
class AttachTechniqueInput { public: virtual ~AttachTechniqueInput(); NiNode* current3DRoot; NiNode* attachedArt; unsigned attachPoint; };
class RefAttachTechniqueInput : public AttachTechniqueInput { public: Actor* actor; TESRace* actorRace; bhkWorld* physicsWorld; unsigned collisionFilter; const char* nodeName; };
struct SaveLoadBuffer { char* buffer; }; struct LoadGameSubBuffer { SaveLoadBuffer buffer; };
class ActorMagicCaster : public MagicCaster, public SimpleAnimationGraphManagerHolder, public AnimationGraphEventSink { public: void FinishCastImpl(); RefAttachTechniqueInput castingArtData; BGSArtObjectCloneTask* cloneTask; Actor* actor; NiNode* magicNode; BSLight* light; void (*interruptHandler)(Actor*); LoadGameSubBuffer loadGameSubBuffer; BGSArtObject* castingArt; ReferenceEffectController* weaponEnchantmentController; float costCharged; unsigned castingSource, flags; };
static_assert(sizeof(MagicCaster)==0x48, "MagicCaster layout");
static_assert(sizeof(RefAttachTechniqueInput)==0x48, "RefAttachTechniqueInput layout");
