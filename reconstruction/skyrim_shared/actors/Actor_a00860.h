// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Actor: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); a view of the selected-spell slots only
// Actor::GetEquippedSpell: CRASHLOGGER_PDB(59818@2026.10.24); Papyrus native, recorded in the papyrus Actor namespace, the address suffix of the recorded name is dropped
// Actor::selectedSpells: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG places it at 0x1c0, this build reads 0x1c8
// Actor::Function6d7090: GUESS(low); callee at RVA 0x6d7090, used for the empty third slot
// IVirtualMachine IVirtualMachine::TraceStack TESForm MagicItem SpellItem: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// g_msga00860: GUESS(low); message string at RVA 0x19953d8 for an out-of-range slot
#pragma once

#include <cstdint>

class IVirtualMachine
{
public:
    virtual ~IVirtualMachine();
    virtual void Unk_01();
    virtual void TraceStack(const char* a_str, std::uint32_t a_stackID, std::uint32_t a_severity);
};

class TESForm
{
public:
    std::uint8_t pad00[0x1A];
    std::uint8_t formType;  // 0x1a
};

class MagicItem : public TESForm
{
};

class SpellItem : public MagicItem
{
};

extern const char g_msga00860[];

class Actor
{
public:
    SpellItem* Function6d7090();
    static SpellItem* GetEquippedSpell(IVirtualMachine* a_vm, std::uint32_t a_stackID, Actor* a_actor, std::int32_t a_slot);

    std::uint8_t pad00[0x1C8];
    MagicItem* selectedSpells[4];  // 0x1c8
};
