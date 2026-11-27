// Source exposure: mixed (pinned image and RTTI, project receiver layouts, and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial declarations from the cited layouts and the pinned RTTI base list. Stamped as a twin of matched 0x74a4e0 (skyrim_shared/actors/PlayerCharacter_69f950): source copied, names replaced by placeholders.
// BSSystemEvent: EXE_RTTI
// Character, Actor: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSTEventSink: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MenuOpenCloseEvent, MenuModeChangeEvent, UserEventEnabledEvent, TESTrackedStatsEvent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BipedAnim, NiNode, BSTSmartPointer, TintMask, CombatGroup, PlayerSkills, TESBoundObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// firstPersonBiped, trackedItems, runtimeData, unk8A0, unk8F4, unk90C, unk924, unk948, unkB10: STANDIN GUESS(low)
// Function104df40, Owner104df40, globalFlagB_104df40: GUESS(low) STANDIN
// firstPerson3D, tintMasks, skills, combatGroup, playerFlags, GetNumTints, Function7415a0, Function1544f0, Function741350, Function741580, Function747b70, Function7481c0, Function748cd0, Function748cf0, Function749170, Function749a20, Function749e90, Function749eb0, Function74a4d0, Function74a4f0, Function74c2f0, Function74c4e0, Function7517a0, Function7517d0, Function756b80, Function756bf0, Function756c90, Function757410, Function757420, Function757da0, Function75a640, Function75bc20, Function75bd50, Function75e140, Function75e150, Function761470, Function76acd0, Function76b0b0, Function76b0c0, Function76e8c0, Function76f6f0, Function772b10, Function772b20, Function7731a0, Function776890, Function776fa0, Function778cb0, Function778d60: GUESS(low) STANDIN
#pragma once
#include "PlayerCharacter_69f950.h"

class Owner104df40 :
    public Character,
    public BSTEventSink<MenuOpenCloseEvent>,
    public BSTEventSink<MenuModeChangeEvent>,
    public BSTEventSink<UserEventEnabledEvent>,
    public BSTEventSink<TESTrackedStatsEvent>,
    public BSTEventSink<BSSystemEvent>
{
public:
    Owner104df40();
    ~Owner104df40() override;
    static Owner104df40* singleton;
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
    static void Function104df40(std::uint8_t value);
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
    static Owner104df40* Function1544f0();
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

