// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Actor: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); a view of the process pointer only
// Actor::GetCurrentAmmo: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) CRASHLOGGER_PDB(59818@2026.10.24); NG declares it as a virtual override, declared non-virtual here as only the body is compared
// Actor::currentProcess: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG places it at 0xf0, this build reads 0xf8
// TESForm TESForm::formType TESForm::IsAmmo TESAmmo: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); form type byte at 0x1a, ammo type 0x2a
// InventoryEntryData InventoryEntryData::object InventoryEntryData::GetObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NG types the object as TESBoundObject
// AIProcess: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// AIProcess::GetCurrentAmmoEntry: GUESS(low); callee at RVA 0x7206a0 returning the ammo inventory entry
// Actor::GetCurrentAmmoEntry: GUESS(low); inline accessor over the process
#pragma once

#include <cstdint>
#include <cstddef>

struct TESForm
{
    std::uint8_t pad00[0x1A];
    std::uint8_t formType;  // 0x1a

    bool IsAmmo() const { return formType == 0x2A; }
};

struct TESAmmo : TESForm
{
};

struct InventoryEntryData
{
    TESForm* object;  // 0x00

    TESForm* GetObject() const { return object; }
};

class AIProcess
{
public:
    InventoryEntryData* GetCurrentAmmoEntry();
};

class Actor
{
public:
    TESAmmo* GetCurrentAmmo() const;  // compared: 0x6cc700

    InventoryEntryData* GetCurrentAmmoEntry() const
    {
        if (!currentProcess) {
            return nullptr;
        }
        return currentProcess->GetCurrentAmmoEntry();
    }

    std::uint8_t pad00[0xF8];
    AIProcess* currentProcess;  // 0xf8
};
static_assert(offsetof(Actor, currentProcess) == 0xF8, "currentProcess");
