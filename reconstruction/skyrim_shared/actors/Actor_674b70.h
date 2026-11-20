// Source exposure: mixed (pinned image and RTTI, project layouts, and CommonLib declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SPDX-License-Identifier: GPL-3.0-or-later (powerof3/CommonLibSSE names; full text: licenses/CommonLibSSE-GPL-3.0.txt)
// Code origin: partial declarations from the cited layouts and the pinned RTTI.
// Actor: EXE_RTTI
// TESForm, TESObjectREFR, BSHandleRefObject, BSAnimationGraphEvent, BSTEventSink: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// IAnimationGraphManagerHolder, MagicTarget, ActorValueOwner, ActorState, ActiveEffect: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSTransformDeltaEvent, bhkCharacterMoveFinishEvent, IPostAnimationChannelUpdateFunctor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSPerkRankArray, AIProcess, NiNode, NiPoint3, TESNPC, TESPackage, BSTSmartPointer, BSAnimationGraphManager: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActorMagicCaster, FormType, BGSDialogueBranch, TESShout, MovementControllerNPC: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetBoundRadius, IsMovementAnimationDriven: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// MagicTarget::GetTargetStatsObject, MagicTarget::InvalidateCommandedActorEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// IMovementState::DoGetMovementSpeed, GetAnimationGraphManagerImpl, GetActorValue, ActorValue::kDamageResist: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// boolBits, boolFlags, currentProcess, formID, formType, movementController: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// OBJ_REFR, objectReference, angle, location, TESObjectREFR::data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// actionValue, timerOnAction, emotionType, emotionValue, exclusiveBranch, magicCasters, selectedPower: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// AttackDataPointer, VOICE_STATE, TESShoutVariation, padding, unk1CC, perkRanks: STANDIN GUESS(low)
// Function2e6a90, Function6a7910, Function693200, Function685a30, ApplySoundEvent: GUESS(low)
// Function674b70, Function675310, Function675540, Function675560, Function687c00, Function687f30: GUESS(low)
// Function692320, Function696a40, Function69f8c0, Function6a15c0, Function6a51b0, Function6af0d0: GUESS(low)
// Function6b1160, Function6b5770, Function6b57d0, Function6b59f0, Function6bdd60, Function6bde50: GUESS(low)
// Function6bde70, Function6bde80, Function6c1170, Function6c1180, Function6c2b90, Function6c2d00: GUESS(low)
// Function6c2d10, Function6c8a40, Function6c9f00, Function6ca270, Function6cc8f0, Function6d4d20: GUESS(low)
// Function6d7070, Function6d7090, Function6d9250, Function6d9270, Function6d92d0, Function6d92f0: GUESS(low)

#pragma once

#include <cstdint>

class ActiveEffect;
class ActorMagicCaster;
class AIProcess;
class BGSDialogueBranch;
class BSAnimationGraphEvent;
class BSAnimationGraphManager;
class BSTransformDeltaEvent;
class bhkCharacterMoveFinishEvent;
class MovementControllerNPC;
class NiNode;
class TESNPC;
class TESPackage;
class TESShout;
class BGSAttackData;

struct NiPoint3
{
    float x;
    float y;
    float z;
};

enum class ActorValue : std::int32_t { kDamageResist = 39 };
enum class FormType : std::uint8_t { Spell = 0x16, Shout = 0x77 };
enum class VOICE_STATE : std::uint32_t;
enum class TESShoutVariation : std::uint32_t;
struct AttackDataPointer { BGSAttackData* pointer; };
template <class T> class BSTSmartPointer;

class TESForm
{
public:
    virtual ~TESForm();

    std::uint8_t padding008[0xC];
    std::uint32_t formID;
    std::uint8_t padding018[0x2];
    FormType formType;
    std::uint8_t padding01B[0x5];
};
static_assert(sizeof(TESForm) == 0x20, "form prefix size");

class BSHandleRefObject
{
public:
    virtual ~BSHandleRefObject();

private:
    std::uint8_t padding[0x8];
};

template <class Event>
class BSTEventSink
{
public:
    virtual ~BSTEventSink();
};

class IAnimationGraphManagerHolder
{
public:
    virtual ~IAnimationGraphManagerHolder();
    virtual void FunctionSlot01();
    virtual bool GetAnimationGraphManagerImpl(BSTSmartPointer<BSAnimationGraphManager>& output) const;
};

struct OBJ_REFR
{
    TESNPC* objectReference;
    NiPoint3 angle;
    NiPoint3 location;
};
static_assert(sizeof(OBJ_REFR) == 0x20, "object reference data size");

class TESObjectREFR :
    public TESForm,
    public BSHandleRefObject,
    public BSTEventSink<BSAnimationGraphEvent>,
    public IAnimationGraphManagerHolder
{
public:
    ~TESObjectREFR() override;
    void* Function2e6a90() const;

protected:
    OBJ_REFR data;
    std::uint8_t padding060[0x40];
};
static_assert(sizeof(TESObjectREFR) == 0xA0, "reference prefix size");

class MagicTarget
{
public:
    virtual ~MagicTarget();
    virtual TESObjectREFR* GetTargetStatsObject();
    virtual void InvalidateCommandedActorEffect(ActiveEffect* effect);

private:
    std::uint8_t padding[0x10];
};

class ActorValueOwner
{
public:
    virtual ~ActorValueOwner();
    virtual float GetActorValue(ActorValue value);
};

class ActorState
{
public:
    virtual ~ActorState();
    virtual std::uint32_t Function6b5770() const;
    virtual void Function6b57d0(NiPoint3& output) const;
    virtual float DoGetMovementSpeed();
    virtual std::uint32_t Function6b59f0() const;

private:
    std::uint8_t padding[0x8];
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
    Actor();
    ~Actor() override;
    void* Function674b70() const;
    std::uint32_t Function675310() const;
    void Function675540(bool value);
    bool Function675560() const;
    float GetBoundRadius() const;
    bool IsMovementAnimationDriven() const;
    void Function687c00(bool value);
    bool Function687f30() const;
    void Function692320(NiNode* value);
    std::uint32_t Function696a40() const;
    void* Function69f8c0() const;
    friend void ApplySoundEvent(Actor* actor, std::int32_t value);
    TESPackage* Function6a15c0() const;
    MovementControllerNPC* const& Function6a51b0() const;
    float Function6af0d0() const;
    bool Function6b1160() const;
    std::uint32_t Function6b5770() const override;
    void Function6b57d0(NiPoint3& output) const override;
    float DoGetMovementSpeed() override;
    std::uint32_t Function6b59f0() const override;
    bool GetAnimationGraphManagerImpl(BSTSmartPointer<BSAnimationGraphManager>& output) const override;
    float Function6bdd60();
    BGSDialogueBranch* Function6bde50() const;
    std::uint32_t Function6bde70() const;
    std::uint32_t Function6bde80() const;
    TESObjectREFR* GetTargetStatsObject() override;
    std::uint32_t& Function6c1170(std::uint32_t& output) const;
    bool Function6c1180() const;
    void Function6c2b90(BGSDialogueBranch* value);
    void Function6c2d00(std::uint32_t value);
    void Function6c2d10(std::uint32_t value);
    bool Function6c8a40(const void* value) const;
    float Function6c9f00();
    const AttackDataPointer& Function6ca270() const;
    bool Function6cc8f0() const;
    ActorMagicCaster* Function6d4d20(std::int32_t index) const;
    TESForm* Function6d7070() const;
    TESForm* Function6d7090() const;
    void InvalidateCommandedActorEffect(ActiveEffect* effect) override;
    VOICE_STATE Function6d9250() const;
    TESShout* Function6d9270() const;
    void Function6d92d0(TESShoutVariation value);
    TESShoutVariation Function6d92f0() const;

private:
    float Function6a7910() const;
    void Function693200(std::uint32_t value);
    std::uint32_t Function685a30() const;

    std::uint32_t boolBits;
    std::uint8_t padding0EC[0xC];
    AIProcess* currentProcess;
    std::uint8_t padding100[0x1C];
    std::int32_t actionValue;
    float timerOnAction;
    std::uint8_t padding124[0x2C];
    MovementControllerNPC* movementController;
    std::uint8_t padding158[0x1C];
    std::uint32_t emotionType;
    std::uint32_t emotionValue;
    std::uint8_t padding17C[0x2C];
    ActorMagicCaster* magicCasters[4];
    std::uint8_t padding1C8[0x4];
    std::uint32_t unk1CC;
    std::uint8_t padding1D0[0x18];
    TESForm* selectedPower;
    std::uint8_t padding1F0[0x14];
    std::uint32_t boolFlags;
    std::uint8_t padding208[0x20];
    BGSDialogueBranch* exclusiveBranch;
};
