// Source exposure: mixed
// Code origin: original declaration view from the pinned image and labelled community declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// LightEffect, LightEffect::Finish, ActiveEffect::target, ActiveEffect::GetTargetActor, MagicTarget::GetTargetAsActor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Actor, MagicTarget, MagicItem, PlayerCharacter: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// LightEffect::DetachLight: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
// ActiveEffect::spell, MagicItem::GetDelivery, MagicSystem::Delivery::kSelf: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// PlayerCharacter::SetLightTarget: CRASHLOGGER_PDB(59818@2026.10.24)
// unkActor, unkEffect, unkEffect48, magicTarget, singleton: GUESS(low)
// unkSpellSlot00, unkSpellSlot01, unkSpellSlot02, unkSpellSlot03, unkSpellSlot04, unkSpellSlot05, unkSpellSlot06, unkSpellSlot07, unkSpellSlot08, unkSpellSlot09, unkSpellSlot0A, unkSpellSlot0B, unkSpellSlot0C, unkSpellSlot0D, unkSpellSlot0E, unkSpellSlot0F, unkSpellSlot10, unkSpellSlot11, unkSpellSlot12, unkSpellSlot13, unkSpellSlot14, unkSpellSlot15, unkSpellSlot16, unkSpellSlot17, unkSpellSlot18, unkSpellSlot19, unkSpellSlot1A, unkSpellSlot1B, unkSpellSlot1C, unkSpellSlot1D, unkSpellSlot1E, unkSpellSlot1F, unkSpellSlot20, unkSpellSlot21, unkSpellSlot22, unkSpellSlot23, unkSpellSlot24, unkSpellSlot25, unkSpellSlot26, unkSpellSlot27, unkSpellSlot28, unkSpellSlot29, unkSpellSlot2A, unkSpellSlot2B, unkSpellSlot2C, unkSpellSlot2D, unkSpellSlot2E, unkSpellSlot2F, unkSpellSlot30, unkSpellSlot31, unkSpellSlot32, unkSpellSlot33, unkSpellSlot34, unkSpellSlot35, unkSpellSlot36, unkSpellSlot37, unkSpellSlot38, unkSpellSlot39, unkSpellSlot3A, unkSpellSlot3B, unkSpellSlot3C, unkSpellSlot3D, unkSpellSlot3E, unkSpellSlot3F, unkSpellSlot40, unkSpellSlot41, unkSpellSlot42, unkSpellSlot43, unkSpellSlot44, unkSpellSlot45, unkSpellSlot46, unkSpellSlot47, unkSpellSlot48, unkSpellSlot49, unkSpellSlot4A, unkSpellSlot4B, unkSpellSlot4C, unkSpellSlot4D, unkSpellSlot4E, unkSpellSlot4F, unkSpellSlot50, unkSpellSlot51, unkSpellSlot52, unkSpellSlot53, unkSpellSlot54, unkSpellSlot55, unkSpellSlot56: GUESS(low)
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

namespace MagicSystem
{
    enum class Delivery { kSelf = 0 };
}

class MagicItem
{
public:
    virtual void unkSpellSlot00();
    virtual void unkSpellSlot01();
    virtual void unkSpellSlot02();
    virtual void unkSpellSlot03();
    virtual void unkSpellSlot04();
    virtual void unkSpellSlot05();
    virtual void unkSpellSlot06();
    virtual void unkSpellSlot07();
    virtual void unkSpellSlot08();
    virtual void unkSpellSlot09();
    virtual void unkSpellSlot0A();
    virtual void unkSpellSlot0B();
    virtual void unkSpellSlot0C();
    virtual void unkSpellSlot0D();
    virtual void unkSpellSlot0E();
    virtual void unkSpellSlot0F();
    virtual void unkSpellSlot10();
    virtual void unkSpellSlot11();
    virtual void unkSpellSlot12();
    virtual void unkSpellSlot13();
    virtual void unkSpellSlot14();
    virtual void unkSpellSlot15();
    virtual void unkSpellSlot16();
    virtual void unkSpellSlot17();
    virtual void unkSpellSlot18();
    virtual void unkSpellSlot19();
    virtual void unkSpellSlot1A();
    virtual void unkSpellSlot1B();
    virtual void unkSpellSlot1C();
    virtual void unkSpellSlot1D();
    virtual void unkSpellSlot1E();
    virtual void unkSpellSlot1F();
    virtual void unkSpellSlot20();
    virtual void unkSpellSlot21();
    virtual void unkSpellSlot22();
    virtual void unkSpellSlot23();
    virtual void unkSpellSlot24();
    virtual void unkSpellSlot25();
    virtual void unkSpellSlot26();
    virtual void unkSpellSlot27();
    virtual void unkSpellSlot28();
    virtual void unkSpellSlot29();
    virtual void unkSpellSlot2A();
    virtual void unkSpellSlot2B();
    virtual void unkSpellSlot2C();
    virtual void unkSpellSlot2D();
    virtual void unkSpellSlot2E();
    virtual void unkSpellSlot2F();
    virtual void unkSpellSlot30();
    virtual void unkSpellSlot31();
    virtual void unkSpellSlot32();
    virtual void unkSpellSlot33();
    virtual void unkSpellSlot34();
    virtual void unkSpellSlot35();
    virtual void unkSpellSlot36();
    virtual void unkSpellSlot37();
    virtual void unkSpellSlot38();
    virtual void unkSpellSlot39();
    virtual void unkSpellSlot3A();
    virtual void unkSpellSlot3B();
    virtual void unkSpellSlot3C();
    virtual void unkSpellSlot3D();
    virtual void unkSpellSlot3E();
    virtual void unkSpellSlot3F();
    virtual void unkSpellSlot40();
    virtual void unkSpellSlot41();
    virtual void unkSpellSlot42();
    virtual void unkSpellSlot43();
    virtual void unkSpellSlot44();
    virtual void unkSpellSlot45();
    virtual void unkSpellSlot46();
    virtual void unkSpellSlot47();
    virtual void unkSpellSlot48();
    virtual void unkSpellSlot49();
    virtual void unkSpellSlot4A();
    virtual void unkSpellSlot4B();
    virtual void unkSpellSlot4C();
    virtual void unkSpellSlot4D();
    virtual void unkSpellSlot4E();
    virtual void unkSpellSlot4F();
    virtual void unkSpellSlot50();
    virtual void unkSpellSlot51();
    virtual void unkSpellSlot52();
    virtual void unkSpellSlot53();
    virtual void unkSpellSlot54();
    virtual void unkSpellSlot55();
    virtual void unkSpellSlot56();
    virtual MagicSystem::Delivery GetDelivery() const;
};

class LightEffect;

class PlayerCharacter
{
public:
    static PlayerCharacter* singleton;
    void SetLightTarget(LightEffect* a_target);
};

class LightEffect
{
public:
    void Finish();
    static void AttachBestLightEffect(MagicTarget* a_target);

    Actor* GetTargetActor()
    {
        return target ? target->GetTargetAsActor() : nullptr;
    }

    void DetachLight();

    unsigned char unkEffect[0x40];
    MagicItem* spell;
    unsigned char unkEffect48[8];
    MagicTarget* target;
};

static_assert(offsetof(LightEffect, target) == 0x50, "Active effect target offset");
