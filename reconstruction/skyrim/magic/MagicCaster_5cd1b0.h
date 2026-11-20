// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial caster and reference prefixes follow the cited class and virtual slot declarations.
// MagicCaster, TESObjectREFR, BSHandleRefObject, MagicItem, Actor, BSSoundHandle, currentSpell, desiredTarget, sounds, state, castingTimer, nextTargetUpdate, projectileTimer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// StartChargeImpl, StartCastImpl, SelectSpellImpl, PrepareSound, AdjustActiveEffect, GetMagicCaster, GetCastingType, GetSpellType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CastingType, SpellType, CastingSource, SoundID, kCharge, kConcentration, kVoicePower, State, kUnk02, kUnk04: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// refCount, FunctionSlot declarations, Function declarations, padding, ActorHandle, CastingSounds: STANDIN GUESS(low)
#pragma once

#include <cstdint>

class ActiveEffect;
class MagicCaster;
class TESObjectREFR;

namespace MagicSystem
{
    enum class CastingType : std::int32_t { kConcentration = 2 };
    enum class SpellType : std::int32_t { kVoicePower = 11 };
    enum class CastingSource : std::int32_t;
    enum class SoundID : std::int32_t { kCharge = 1 };
}

// TESForm, AsReference2: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class TESForm
{
public:
    virtual ~TESForm();
    virtual void FunctionSlot01();
    virtual void FunctionSlot02();
    virtual void FunctionSlot03();
    virtual void FunctionSlot04();
    virtual void FunctionSlot05();
    virtual void FunctionSlot06();
    virtual void FunctionSlot07();
    virtual void FunctionSlot08();
    virtual void FunctionSlot09();
    virtual void FunctionSlot0A();
    virtual void FunctionSlot0B();
    virtual void FunctionSlot0C();
    virtual void FunctionSlot0D();
    virtual void FunctionSlot0E();
    virtual void FunctionSlot0F();
    virtual void FunctionSlot10();
    virtual void FunctionSlot11();
    virtual void FunctionSlot12();
    virtual void FunctionSlot13();
    virtual void FunctionSlot14();
    virtual void FunctionSlot15();
    virtual void FunctionSlot16();
    virtual void FunctionSlot17();
    virtual void FunctionSlot18();
    virtual void FunctionSlot19();
    virtual void FunctionSlot1A();
    virtual void FunctionSlot1B();
    virtual void FunctionSlot1C();
    virtual void FunctionSlot1D();
    virtual void FunctionSlot1E();
    virtual void FunctionSlot1F();
    virtual void FunctionSlot20();
    virtual void FunctionSlot21();
    virtual void FunctionSlot22();
    virtual void FunctionSlot23();
    virtual void FunctionSlot24();
    virtual void FunctionSlot25();
    virtual void FunctionSlot26();
    virtual void FunctionSlot27();
    virtual void FunctionSlot28();
    virtual void FunctionSlot29();
    virtual void FunctionSlot2A();
    virtual void FunctionSlot2B();
    virtual const TESObjectREFR* AsReference2() const;
    virtual void FunctionSlot2D();
    virtual void FunctionSlot2E();
    virtual void FunctionSlot2F();
    virtual void FunctionSlot30();
    virtual void FunctionSlot31();
    virtual void FunctionSlot32();
    virtual void FunctionSlot33();
    virtual void FunctionSlot34();
    virtual void FunctionSlot35();
    virtual void FunctionSlot36();
    virtual void FunctionSlot37();
    virtual void FunctionSlot38();
    virtual void FunctionSlot39();
    virtual void FunctionSlot3A();

private:
    std::uint8_t padding08[0x18];
};
static_assert(sizeof(TESForm) == 0x20, "form prefix size");

class BSHandleRefObject
{
public:
    virtual ~BSHandleRefObject();
    std::uint32_t refCount;
    std::uint32_t padding0C;
};
static_assert(sizeof(BSHandleRefObject) == 0x10, "reference count prefix size");

class TESObjectREFR : public TESForm, public BSHandleRefObject
{
public:
    virtual void FunctionSlot3B();
    virtual void FunctionSlot3C();
    virtual void FunctionSlot3D();
    virtual void FunctionSlot3E();
    virtual void FunctionSlot3F();
    virtual void FunctionSlot40();
    virtual void FunctionSlot41();
    virtual void FunctionSlot42();
    virtual void FunctionSlot43();
    virtual void FunctionSlot44();
    virtual void FunctionSlot45();
    virtual void FunctionSlot46();
    virtual void FunctionSlot47();
    virtual void FunctionSlot48();
    virtual void FunctionSlot49();
    virtual void FunctionSlot4A();
    virtual void FunctionSlot4B();
    virtual void FunctionSlot4C();
    virtual void FunctionSlot4D();
    virtual void FunctionSlot4E();
    virtual void FunctionSlot4F();
    virtual void FunctionSlot50();
    virtual void FunctionSlot51();
    virtual void FunctionSlot52();
    virtual void FunctionSlot53();
    virtual void FunctionSlot54();
    virtual void FunctionSlot55();
    virtual void FunctionSlot56();
    virtual void FunctionSlot57();
    virtual void FunctionSlot58();
    virtual void FunctionSlot59();
    virtual void FunctionSlot5A();
    virtual void FunctionSlot5B();
    virtual MagicCaster* GetMagicCaster(MagicSystem::CastingSource source);
};
static_assert(sizeof(TESObjectREFR) == 0x30, "reference prefix size");

class Actor : public TESObjectREFR
{
public:
    std::uint32_t Function6d9250() const;
    void Function6d7770(MagicSystem::CastingSource source, bool first, bool second);

    // actorState2: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); flags in the ActorState prefix.
    std::uint8_t padding030[0xCC - 0x30];
    std::uint32_t actorState2;
};

class MagicItem : public TESForm
{
public:
    virtual void FunctionSlot3B();
    virtual void FunctionSlot3C();
    virtual void FunctionSlot3D();
    virtual void FunctionSlot3E();
    virtual void FunctionSlot3F();
    virtual void FunctionSlot40();
    virtual void FunctionSlot41();
    virtual void FunctionSlot42();
    virtual void FunctionSlot43();
    virtual void FunctionSlot44();
    virtual void FunctionSlot45();
    virtual void FunctionSlot46();
    virtual void FunctionSlot47();
    virtual void FunctionSlot48();
    virtual void FunctionSlot49();
    virtual void FunctionSlot4A();
    virtual void FunctionSlot4B();
    virtual void FunctionSlot4C();
    virtual void FunctionSlot4D();
    virtual void FunctionSlot4E();
    virtual void FunctionSlot4F();
    virtual void FunctionSlot50();
    virtual void FunctionSlot51();
    virtual void FunctionSlot52();
    virtual MagicSystem::SpellType GetSpellType() const;
    virtual void FunctionSlot54();
    virtual MagicSystem::CastingType GetCastingType() const;
};

class ActiveEffect
{
public:
    void Function5bada0(float power, bool option);
};

class BSSoundHandle
{
public:
    bool Functioncc9730() const;
    void Functioncc9dd0();

private:
    std::uint8_t padding00[0xC];
};
static_assert(sizeof(BSSoundHandle) == 0xC, "sound handle size");

struct CastingSounds
{
    BSSoundHandle* data;
    std::uint8_t padding08[0x10];
};

template<class T> struct BSPointerHandle
{
    std::uint32_t value;
};

class MagicCaster
{
public:
    enum class State : std::uint32_t { kUnk02 = 2, kUnk04 = 4 };
    virtual ~MagicCaster();
    virtual void FunctionSlot01();
    virtual void FunctionSlot02();
    virtual void FunctionSlot03();
    virtual bool StartChargeImpl();
    virtual void FunctionSlot05();
    virtual void StartCastImpl();
    virtual void FunctionSlot07();
    virtual void FunctionSlot08();
    virtual void FunctionSlot09();
    virtual void FunctionSlot0A();
    virtual void FunctionSlot0B();
    virtual void FunctionSlot0C();
    virtual void FunctionSlot0D();
    virtual void FunctionSlot0E();
    virtual void FunctionSlot0F();
    virtual void FunctionSlot10();
    virtual void SelectSpellImpl();
    virtual void FunctionSlot12();
    virtual void FunctionSlot13();
    virtual void FunctionSlot14();
    virtual void FunctionSlot15();
    virtual void FunctionSlot16();
    virtual void FunctionSlot17();
    virtual void FunctionSlot18();
    virtual void FunctionSlot19();
    virtual void FunctionSlot1A();
    virtual void PrepareSound(MagicSystem::SoundID sound, MagicItem* spell);
    static MagicCaster* Function5cd1b0(std::uint32_t formID);
    void Function5cd2d0();
    virtual void AdjustActiveEffect(ActiveEffect* effect, float power, bool option);
    void Function5d06a0();
    bool Function5d07a0();
    void Function5d07f0();

protected:
    void Function5cda50(MagicSystem::SoundID sound);
    bool Function5ca880(TESObjectREFR* target, bool option);
    void Function5cd380();

    CastingSounds sounds;
    BSPointerHandle<Actor> desiredTarget;
    std::uint32_t padding24;
    MagicItem* currentSpell;
    State state;
    float castingTimer;
    std::uint8_t padding38[8];
    float nextTargetUpdate;
    float projectileTimer;
};
static_assert(sizeof(MagicCaster) == 0x48, "magic caster prefix size");
