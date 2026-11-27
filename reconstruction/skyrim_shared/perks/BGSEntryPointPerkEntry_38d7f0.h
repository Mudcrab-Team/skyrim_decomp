// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSEntryPointPerkEntry: EXE_RTTI
// BGSEntryPointPerkEntry::MultiplyOnePlusActorValueMult: CRASHLOGGER_PDB(59818@2026.10.24)
// BGSEntryPointFunctionData, BGSEntryPointFunctionData::FunctionType, BGSEntryPointFunctionData::GetType, kTwoValue: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSEntryPointFunctionDataTwoValue, ActorValueOwner, ActorValueOwner::GetActorValue, TESObjectREFR, Actor: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSEntryPointFunctionDataTwoValue::data1, BGSEntryPointFunctionDataTwoValue::data2, TESObjectREFR::unk08, TESObjectREFR::formType, TESObjectREFR::unk1B, g_entryPointOneArgCount: GUESS(low); offsets and global observed in listing
#pragma once

#include <cstddef>
#include <cstdint>

class TESObjectREFR
{
public:
    virtual ~TESObjectREFR();  // 00

    std::uint8_t unk08[0x12];  // 08
    std::uint8_t formType;     // 1A
    std::uint8_t unk1B[0x9D];  // 1B
};
static_assert(offsetof(TESObjectREFR, formType) == 0x1A, "TESObjectREFR::formType offset");
static_assert(sizeof(TESObjectREFR) == 0xB8, "TESObjectREFR size");

class ActorValueOwner
{
public:
    virtual ~ActorValueOwner();                              // 00
    virtual float GetActorValue(std::uint32_t a_av) const;   // 01
};

class Actor : public TESObjectREFR, public ActorValueOwner
{
};

class BGSEntryPointFunctionData
{
public:
    enum class FunctionType
    {
        kTwoValue = 2
    };

    virtual ~BGSEntryPointFunctionData();      // 00
    virtual FunctionType GetType() const = 0;  // 01
};

class BGSEntryPointFunctionDataTwoValue : public BGSEntryPointFunctionData
{
public:
    float data1;  // 08
    float data2;  // 0C
};

extern std::uint32_t g_entryPointOneArgCount;

class BGSEntryPointPerkEntry
{
public:
    static void MultiplyOnePlusActorValueMult(TESObjectREFR* a_refr, std::uint32_t a_functionType, std::uint8_t a_numArgs, void** a_args, BGSEntryPointFunctionData* a_data);
};
