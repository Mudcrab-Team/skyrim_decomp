// Source exposure: mixed (pinned image and RTTI, project layouts, and CommonLib declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SPDX-License-Identifier: GPL-3.0-or-later (powerof3/CommonLibSSE names; full text: licenses/CommonLibSSE-GPL-3.0.txt)
// Code origin: partial declarations from the cited layouts and the pinned RTTI. Stamped as a twin of matched 0x6a51b0 (skyrim_shared/actors/Actor_674b70): source copied, names replaced by placeholders.
// TESForm, TESObjectREFR, BSTEventSink: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MagicTarget, ActorValueOwner, ActorState, ActiveEffect: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSTransformDeltaEvent, bhkCharacterMoveFinishEvent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// AIProcess, NiNode, NiPoint3, TESPackage, BSTSmartPointer, BSAnimationGraphManager: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActorMagicCaster, BGSDialogueBranch, TESShout, MovementControllerNPC: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MagicTarget::GetTargetStatsObject, MagicTarget::InvalidateCommandedActorEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// IMovementState::DoGetMovementSpeed: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// AttackDataPointer, VOICE_STATE, TESShoutVariation, unk1CC: STANDIN GUESS(low)
// Function159af20, Owner159af20: GUESS(low) STANDIN
// IPostAnimationChannelUpdateFunctor, GetBoundRadius, IsMovementAnimationDriven, GetAnimationGraphManagerImpl, boolBits, boolFlags, currentProcess, movementController, actionValue, timerOnAction, emotionType, emotionValue, exclusiveBranch, magicCasters, selectedPower, Function6a7910, Function693200, Function685a30, ApplySoundEvent, Function674b70, Function675310, Function675540, Function675560, Function687c00, Function687f30, Function692320, Function696a40, Function69f8c0, Function6a15c0, Function6af0d0, Function6b1160, Function6b5770, Function6b57d0, Function6b59f0, Function6bdd60, Function6bde50, Function6bde70, Function6bde80, Function6c1170, Function6c1180, Function6c2b90, Function6c2d00, Function6c2d10, Function6c8a40, Function6c9f00, Function6ca270, Function6cc8f0, Function6d4d20, Function6d7070, Function6d7090, Function6d9250, Function6d9270, Function6d92d0, Function6d92f0: GUESS(low) STANDIN
#pragma once
#include "Actor_674b70.h"

class Owner159af20 :
    public TESObjectREFR,
    public MagicTarget,
    public ActorValueOwner,
    public ActorState,
    public BSTEventSink<BSTransformDeltaEvent>,
    public BSTEventSink<bhkCharacterMoveFinishEvent>,
    public IPostAnimationChannelUpdateFunctor
{
public:
    Owner159af20();
    ~Owner159af20() override;
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
    friend void ApplySoundEvent(Owner159af20* actor, std::int32_t value);
    TESPackage* Function6a15c0() const;
    MovementControllerNPC* const& Function159af20() const;
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

