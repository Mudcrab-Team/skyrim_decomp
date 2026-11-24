// Source exposure: mixed
// Code origin: original declaration view from the pinned image and labelled community declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// LightEffect, LightEffect::Update, ActiveEffect::target, ActiveEffect::GetTargetActor, MagicTarget::GetTargetAsActor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Actor, MagicTarget, NiPointLight, ShadowSceneNode, NiPointer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ShadowSceneNode::FindActiveLight, ShadowSceneNode::AddLight: CRASHLOGGER_PDB(59818@2026.10.24)
// LightEffect::light, NiPointer::_ptr: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unkActor, unkEffect, magicTarget, unkEffect58, defaultShadowScene: GUESS(low)
// LightEffect::AttachBestLightEffect: SIBLING(fo4-private@1b765c70, author-permission)
#pragma once

#include <cstddef>

class MagicTarget
{
public:
    class Actor* GetTargetAsActor();
};

class Actor
{
public:
    unsigned char unkActor[0xA0];
    MagicTarget magicTarget;
};

class NiPointLight;

class ShadowSceneNode
{
public:
    void* FindActiveLight(NiPointLight* a_light);
    void AddLight(NiPointLight* a_light, bool a_active);
};

template <class T>
class NiPointer
{
public:
    explicit operator bool() const { return _ptr != nullptr; }
    T* get() const { return _ptr; }

    T* _ptr;
};

extern ShadowSceneNode* defaultShadowScene;

class LightEffect
{
public:
    void Update(float a_delta);
    static void AttachBestLightEffect(MagicTarget* a_target);

    Actor* GetTargetActor()
    {
        return target ? target->GetTargetAsActor() : nullptr;
    }

    unsigned char unkEffect[0x50];
    MagicTarget* target;
    unsigned char unkEffect58[0x38];
    NiPointer<NiPointLight> light;
};

static_assert(offsetof(LightEffect, target) == 0x50, "Active effect target offset");
static_assert(offsetof(LightEffect, light) == 0x90, "Point light offset");
