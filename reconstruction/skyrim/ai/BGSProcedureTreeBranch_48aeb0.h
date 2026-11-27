// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// BGSProcedureTreeBranch: EXE_RTTI
// BGSProcedureTreeBranch::Func2_140429090, BGSProcedureTreeBranch::conditions, BGSProcedureTreeConditionalItem, TESCondition, TESFile: CRASHLOGGER_PDB(59818@2026.10.24)
// TESCondition::ResolveForms, TESCondition::first, BGSProcedureTreeConditionalItem::Unk_01, BGSProcedureTreeConditionalItem::Func2_140429090, BGSProcedureTreeConditionalItem::condition, ConditionalItemArray, ConditionalItemArray::data, ConditionalItemArray::unk08, ConditionalItemArray::size: GUESS(low); offsets, virtual slot, and call observed in listing
#pragma once

#include <cstddef>
#include <cstdint>

class TESFile;

struct TESCondition
{
    void ResolveForms(TESFile* a_mod);

    void* first;  // 00
};
static_assert(sizeof(TESCondition) == 0x8, "TESCondition size");

class BGSProcedureTreeConditionalItem
{
public:
    virtual ~BGSProcedureTreeConditionalItem();      // 00
    virtual void Unk_01();                           // 01
    virtual void Func2_140429090(TESFile* a_mod);    // 02

    TESCondition condition;  // 08
};
static_assert(sizeof(BGSProcedureTreeConditionalItem) == 0x10, "BGSProcedureTreeConditionalItem size");

struct ConditionalItemArray
{
    BGSProcedureTreeConditionalItem** data;   // 00
    std::uint64_t                     unk08;  // 08
    std::uint32_t                     size;   // 10
};
static_assert(offsetof(ConditionalItemArray, size) == 0x10, "ConditionalItemArray::size offset");

class BGSProcedureTreeBranch : public BGSProcedureTreeConditionalItem
{
public:
    void Func2_140429090(TESFile* a_mod) override;

    ConditionalItemArray conditions;  // 10
};
static_assert(offsetof(BGSProcedureTreeBranch, conditions) == 0x10, "BGSProcedureTreeBranch::conditions offset");
