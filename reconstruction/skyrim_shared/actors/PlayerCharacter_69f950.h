// Source exposure: mixed (pinned image and RTTI, project receiver layouts, and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial declarations from the cited layouts and the pinned RTTI base list.
// PlayerCharacter, BSSystemEvent: EXE_RTTI
// Character, Actor, TESObjectREFR, MagicTarget, ActorValueOwner, ActorState: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESForm, BSHandleRefObject, BSAnimationGraphEvent, IAnimationGraphManagerHolder: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSTEventSink, BSTransformDeltaEvent, bhkCharacterMoveFinishEvent, IPostAnimationChannelUpdateFunctor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MenuOpenCloseEvent, MenuModeChangeEvent, UserEventEnabledEvent, TESTrackedStatsEvent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// AIProcess, BipedAnim, NiNode, BSTSmartPointer, TintMask, CombatGroup, PlayerSkills, TESBoundObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// currentProcess, boolFlags, actorState1, firstPerson3D, tintMasks, skills, combatGroup, playerFlags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetNumTints, Character::GetBiped2: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// firstPersonBiped, trackedItems, runtimeData, padding, unk8A0, unk8F4, unk90C, unk924, unk948, unkB10: STANDIN GUESS(low)
// Function2ebce0, Function6d3d30, Function7415a0, Function1544f0: GUESS(low)
// Function69f950, Function6af230, Function6cba10: GUESS(low)
// Function741350, Function741580, Function747b70, Function7481c0, Function748cd0, Function748cf0: GUESS(low)
// Function749170, Function749a20, Function749e90, Function749eb0, Function74a4d0, Function74a4e0: GUESS(low)
// Function74a4f0, Function74c2f0, Function74c4e0, Function7517a0, Function7517d0: GUESS(low)
// Function756b80, Function756bf0, Function756c90, Function757410, Function757420, Function757da0: GUESS(low)
// Function75a640, Function75bc20, Function75bd50, Function75e140, Function75e150, Function761470: GUESS(low)
// Function76acd0, Function76b0b0, Function76b0c0, Function76e8c0, Function76f6f0, Function772b10: GUESS(low)
// Function772b20, Function7731a0, Function776890, Function776fa0, Function778cb0, Function778d60: GUESS(low)

#pragma once

#include <cstdint>

class AIProcess;
class BipedAnim;
class BSAnimationGraphEvent;
class BSSystemEvent;
class BSTransformDeltaEvent;
class bhkCharacterMoveFinishEvent;
class CombatGroup;
class MenuModeChangeEvent;
class MenuOpenCloseEvent;
class NiNode;
class PlayerSkills;
class TESBoundObject;
struct TESTrackedStatsEvent;
class TintMask;
class UserEventEnabledEvent;

template <class T>
class BSTSmartPointer
{
public:
    T* pointer;
};

template <class T>
struct BSTArray
{
    T* data;
    std::uint32_t capacity;
    std::uint32_t padding0C;
    std::uint32_t size;
    std::uint32_t padding14;
};

template <class Event>
class BSTEventSink
{
public:
    virtual ~BSTEventSink();
};

class TESForm
{
public:
    virtual ~TESForm();

private:
    std::uint8_t padding[0x18];
};

class BSHandleRefObject
{
public:
    virtual ~BSHandleRefObject();

private:
    std::uint8_t padding[0x8];
};

class IAnimationGraphManagerHolder
{
public:
    virtual ~IAnimationGraphManagerHolder();
};

class TESObjectREFR :
    public TESForm,
    public BSHandleRefObject,
    public BSTEventSink<BSAnimationGraphEvent>,
    public IAnimationGraphManagerHolder
{
public:
    ~TESObjectREFR() override;
    NiNode* Function2ebce0() const;

private:
    std::uint8_t padding[0x60];
};
static_assert(sizeof(TESObjectREFR) == 0xA0, "reference prefix size");

class MagicTarget
{
public:
    virtual ~MagicTarget();

private:
    std::uint8_t padding[0x10];
};

class ActorValueOwner
{
public:
    virtual ~ActorValueOwner();
};

class ActorState
{
public:
    virtual ~ActorState();

protected:
    std::uint32_t actorState1;
    std::uint32_t padding;
};

class IPostAnimationChannelUpdateFunctor
{
public:
    virtual ~IPostAnimationChannelUpdateFunctor();
};

class Actor :
    public TESObjectREFR,
    public MagicTarget,
    public ActorValueOwner,
    public ActorState,
    public BSTEventSink<BSTransformDeltaEvent>,
    public BSTEventSink<bhkCharacterMoveFinishEvent>,
    public IPostAnimationChannelUpdateFunctor
{
public:
    ~Actor() override;
    void Function69f950();
    bool Function6af230() const;
    bool Function6cba10() const;
    void Function6d3d30();

protected:
    std::uint8_t padding0E8[0x10];
    AIProcess* currentProcess;
    std::uint8_t padding100[0x104];
    std::uint32_t boolFlags;
    std::uint8_t padding208[0xB0];
};
static_assert(sizeof(Actor) == 0x2B8, "actor base size");

class Character : public Actor
{
public:
    ~Character() override;
    virtual const BSTSmartPointer<BipedAnim>& GetBiped2() const;
};

class PlayerCharacter :
    public Character,
    public BSTEventSink<MenuOpenCloseEvent>,
    public BSTEventSink<MenuModeChangeEvent>,
    public BSTEventSink<UserEventEnabledEvent>,
    public BSTEventSink<TESTrackedStatsEvent>,
    public BSTEventSink<BSSystemEvent>
{
public:
    PlayerCharacter();
    ~PlayerCharacter() override;
    static PlayerCharacter* singleton;
    bool Function741350() const;
    void Function741580();
    NiNode* Function747b70(bool firstPerson) const;
    void Function7481c0();
    const BSTSmartPointer<BipedAnim>& Function748cd0(bool firstPerson) const;
    bool Function748cf0(const BSTSmartPointer<BipedAnim>& biped) const;
    void Function749170();
    void Function749a20(std::uint32_t skill, std::uint32_t count);
    void Function749e90();
    void Function749eb0();
    static std::uint8_t Function74a4d0();
    static void Function74a4e0(std::uint8_t value);
    static std::uint8_t Function74a4f0();
    void Function74c2f0();
    bool Function74c4e0() const;
    void* Function7517a0() const;
    bool Function7517d0() const;
    bool Function756b80() const;
    bool Function756bf0() const;
    std::int32_t Function756c90() const;
    static void Function757410();
    static void Function757420();
    static void Function757da0();
    bool Function75a640() const;
    void Function75bc20(Actor* actor);
    void Function75bd50(Actor* actor);
    std::uint32_t GetNumTints(std::uint32_t tintType);
    static std::uint8_t Function75e140();
    bool Function75e150() const;
    static std::uint8_t* Function761470();
    CombatGroup* Function76acd0() const;
    bool Function76b0b0() const;
    bool Function76b0c0() const;
    bool Function76e8c0() const;
    std::uint32_t& Function76f6f0(std::uint32_t& value) const;
    void Function772b10(CombatGroup* group);
    void Function772b20(const std::uint32_t& value);
    bool Function7731a0() const;
    void Function776890();
    std::uint32_t Function776fa0() const;
    void Function778cb0();
    TESBoundObject* Function778d60(std::int32_t index) const;

private:
    void Function7415a0(bool enabled);
    static PlayerCharacter* Function1544f0();
    std::uint8_t padding2E0[0x108];
    std::uint8_t runtimeData;
    std::uint8_t padding3E9[0x4B7];
    std::int32_t unk8A0;
    std::uint8_t padding8A4[0x50];
    std::uint32_t unk8F4;
    BSTSmartPointer<BipedAnim> firstPersonBiped;
    NiNode* firstPerson3D;
    std::uint8_t padding908[0x4];
    std::uint32_t unk90C;
    std::uint8_t padding910[0x14];
    std::uint32_t unk924;
    std::uint8_t padding928[0x20];
    void* unk948;
    std::uint8_t padding950[0x70];
    PlayerSkills* skills;
    std::uint8_t padding9C8[0x18];
    CombatGroup* combatGroup;
    std::uint8_t padding9E8[0x20];
    TESBoundObject* trackedItems[2];
    std::uint8_t paddingA18[0xF8];
    std::uint8_t unkB10;
    std::uint8_t paddingB11[0xF];
    BSTArray<TintMask*> tintMasks;
    std::uint8_t paddingB38[0xB0];
    std::uint8_t playerFlags[6];
};
