// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// BGSEntryPointPerkEntry: EXE_RTTI
// BGSEntryPointPerkEntry::ResolveForms_1403378F0, BGSEntryPointPerkEntry::numArgs, BGSEntryPointPerkEntry::functionData, BGSEntryPointPerkEntry::conditions: CRASHLOGGER_PDB(59818@2026.10.24)
// BGSEntryPointFunctionData, TESCondition, TESFile: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BGSEntryPointFunctionData::Unk_01, BGSEntryPointFunctionData::Unk_02, BGSEntryPointFunctionData::ResolveForms, TESCondition::ResolveForms: GUESS(low); virtual slot and member call observed in listing
// BGSEntryPointPerkEntry::unk08: GUESS(low); untouched storage before numArgs
#pragma once

#include <cstddef>
#include <cstdint>

class TESFile;

struct TESCondition
{
    void ResolveForms(TESFile* a_mod);

    void* first;
};
static_assert(sizeof(TESCondition) == 0x8, "TESCondition size");

class BGSEntryPointFunctionData
{
public:
    virtual ~BGSEntryPointFunctionData();          // 00
    virtual void Unk_01();                         // 01
    virtual void Unk_02();                         // 02
    virtual void ResolveForms(TESFile* a_mod);     // 03
};

class BGSEntryPointPerkEntry
{
public:
    virtual void ResolveForms_1403378F0(TESFile* a_mod);

    std::uint8_t               unk08[0xA];    // 08
    std::uint8_t               numArgs;       // 12
    BGSEntryPointFunctionData* functionData;  // 18
    TESCondition*              conditions;    // 20
};
static_assert(offsetof(BGSEntryPointPerkEntry, numArgs) == 0x12, "numArgs offset");
static_assert(offsetof(BGSEntryPointPerkEntry, functionData) == 0x18, "functionData offset");
static_assert(offsetof(BGSEntryPointPerkEntry, conditions) == 0x20, "conditions offset");
