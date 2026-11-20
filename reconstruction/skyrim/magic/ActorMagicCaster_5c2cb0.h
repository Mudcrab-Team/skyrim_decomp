// Source exposure: mixed
// Origin: independently decoded target and anonymous sibling; declarations adapted from community headers.
// names: GUESS(low); names and signatures are hypotheses.
// ActorMagicCaster::GetCasterAsActor: SIBLING(fo4-private@1b765c70, author-permission); adapted behavior.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ActorMagicCaster.cpp:463
// ActorMagicCaster, MagicCaster, SimpleAnimationGraphManagerHolder, RefAttachTechniqueInput: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/A/ActorMagicCaster.h, include/RE/M/MagicCaster.h, include/RE/S/SimpleAnimationGraphManagerHolder.h and include/RE/R/RefAttachTechniqueInput.h.
// BSTArrayHeapAllocator, BSTArrayBase: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/B/BSTArray.h.
// TESForm: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/T/TESForm.h and include/RE/B/BaseFormComponent.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
class Actor; class MagicItem;
struct BSTArrayHeapAllocator { void* data; unsigned int capacity; }; struct BSTArrayBase { unsigned int size; }; struct SoundArray : public BSTArrayHeapAllocator, public BSTArrayBase {};
class MagicCaster { public: virtual ~MagicCaster(); SoundArray sounds; unsigned int desiredTarget; MagicItem* currentSpell; unsigned int state; float castingTimer, currentSpellCost, magnitudeOverride, nextTargetUpdate, projectileTimer; };
class SimpleAnimationGraphManagerHolder { public: virtual ~SimpleAnimationGraphManagerHolder(); void* animationGraphManager; void* loadingTask; };
class AnimationEventSink { public: virtual ~AnimationEventSink(); };
class AttachTechniqueInput { public: virtual ~AttachTechniqueInput(); void* current3DRoot; void* attachedArt; unsigned int attachPoint; };
class RefAttachTechniqueInput : public AttachTechniqueInput { public: void* actor; void* actorRace; void* physicsWorld; unsigned int collisionFilter; const char* nodeName; };
class ActorMagicCaster : public MagicCaster, public SimpleAnimationGraphManagerHolder, public AnimationEventSink { public: Actor* GetCasterAsActor() const; RefAttachTechniqueInput castingArtData; void* cloneTask; Actor* actor; };
