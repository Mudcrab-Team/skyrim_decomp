// Source exposure: mixed
// Origin: authorized sibling and community declarations
// ModelReferenceEffect::GetAttachRoot: SIBLING(fo4-private@1b765c70, author-permission); adapted using target evidence
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ModelReferenceEffect.cpp:219
// ModelReferenceEffect, ReferenceEffect, RefAttachTechniqueInput: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/M/ModelReferenceEffect.h, include/RE/R/ReferenceEffect.h, include/RE/R/RefAttachTechniqueInput.h and related base headers
// names: GUESS(low); declarations and signatures remain provisional
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
class NiAVObject; class NiNode; class TESObjectCELL; class ReferenceEffectController; class TESObjectREFR; class TESRace; class bhkWorld; class BGSArtObject; class BGSArtObjectCloneTask; class BSAnimationGraphManager; class SimpleAnimationGraphManagerLoadingTask;
class NiRefObject { public: virtual ~NiRefObject(); virtual void DeleteThis(); std::uint32_t refCount; };
class NiObject : public NiRefObject {};
class BSTempEffect : public NiObject { public: float lifetime; TESObjectCELL* cell; float age; bool initialized; std::uint32_t effectID; };
class ReferenceEffect : public BSTempEffect {
public:
    virtual NiAVObject* GetAttachRoot();
    ReferenceEffectController* controller;
    std::uint32_t target;
    std::uint32_t aimAtTarget;
    bool finished;
    bool ownController;
};
class IAnimationGraphManagerHolder { public: virtual ~IAnimationGraphManagerHolder(); };
class SimpleAnimationGraphManagerHolder : public IAnimationGraphManagerHolder { public: BSAnimationGraphManager* animationGraphManager; SimpleAnimationGraphManagerLoadingTask* loadingTask; };
class AnimationGraphEventSink { public: virtual ~AnimationGraphEventSink(); };
class AttachTechniqueInput { public: virtual ~AttachTechniqueInput(); virtual void Clear(); NiNode* current3DRoot; NiAVObject* attachedArt; std::uint32_t attachPoint; };
class RefAttachTechniqueInput : public AttachTechniqueInput { public: TESObjectREFR* actor; TESRace* actorRace; bhkWorld* physicsWorld; std::uint32_t collisionFilter; const char* nodeName; };
class ModelReferenceEffect : public ReferenceEffect, public SimpleAnimationGraphManagerHolder, public AnimationGraphEventSink {
public:
    NiAVObject* GetAttachRoot() override;
    RefAttachTechniqueInput hitEffectArtData;
    char* loadGameSubBuffer;
    BGSArtObject* artObject;
    BGSArtObjectCloneTask* cloneTask;
    NiAVObject* artObject3D;
    std::uint32_t flags;
};
