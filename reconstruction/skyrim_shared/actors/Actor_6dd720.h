// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// TESForm, BGSEquipSlot, ActorProcess, Actor, Actor::currentProcess, Actor::GetItemEquipSlot: CRASHLOGGER_PDB(59818@2026.10.24)
// ActorProcess::GetEquippedRightHand, ActorProcess::GetEquippedLeftHand, Actor::GetEquippedVoice, GetRightHandSlot, GetLeftHandSlot, GetVoiceSlot, Actor::unk00: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class TESForm;
class BGSEquipSlot;

BGSEquipSlot* GetRightHandSlot();
BGSEquipSlot* GetLeftHandSlot();
BGSEquipSlot* GetVoiceSlot();

class ActorProcess
{
public:
    TESForm* GetEquippedRightHand() const;
    TESForm* GetEquippedLeftHand() const;
};

class Actor
{
public:
    TESForm* GetEquippedVoice() const;
    static BGSEquipSlot* GetItemEquipSlot(void* a_context, Actor* a_actor, TESForm* a_item);

    std::uint8_t  unk00[0xf8];
    ActorProcess* currentProcess;  // 0xf8
};
static_assert(offsetof(Actor, currentProcess) == 0xf8, "Actor::currentProcess offset");
