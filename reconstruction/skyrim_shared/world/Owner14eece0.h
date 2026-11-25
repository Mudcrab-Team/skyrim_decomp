// Code origin: names, bases, virtual slots and member offsets from CharmedBaryon/CommonLibSSE-NG b93280e (MIT); the bodies are written from the listing of the pinned image Stamped as a twin of matched 0x26da90 (skyrim_shared/world/TESFlora): source copied, names replaced by placeholders.
// Source exposure: mixed (community declarations and the contributor-owned pack;
// bases, sizes and slots are community hypotheses).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ::InitItemImpl, ::Load, ::GetActivateText, ::CalculateDoFavor, TESBoundObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESProduceForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NG derives TESFlora from TESProduceForm at C8, here it is a member at C8 so that its address is the subobject address
// TESObjectACTI::InitItemImpl: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); address 0x279d20, called by qualified name
// BSString, TESFile, TESObjectREFR, Actor: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); forward declarations or a pointer-sized reduction
// Owner14eece0: GUESS(low) STANDIN
#pragma once
#include "TESFlora.h"

class Owner14eece0 : public TESObjectACTI
{
public:
    ~Owner14eece0() override;  // 00
    bool Load(TESFile* a_mod) override;  // 06
    void InitItemImpl() override;  // 13 - compared: 0x26da40
    bool Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, std::uint8_t a_arg3, TESBoundObject* a_object, std::int32_t a_targetCount) override;  // 37 - compared: 0x26da90
    bool GetActivateText(TESObjectREFR* a_activator, BSString& a_dst) override;  // 4C
    bool CalculateDoFavor(Actor* a_activator, bool a_arg2, TESObjectREFR* a_toActivate, float a_arg3) override;  // 4D

    TESProduceForm produceForm;  // C8 - NG's second base
};
static_assert(sizeof(Owner14eece0) == 0xE8, "Owner14eece0 size");
static_assert(offsetof(Owner14eece0, produceForm) == 0xC8, "Owner14eece0::produceForm offset");
