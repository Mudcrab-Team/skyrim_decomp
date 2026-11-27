// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// BGSProcedureTreeBranch: EXE_RTTI
// BGSProcedureTreeBranch::Func12_140429280, BGSProcedureTreeBranch::conditions, BGSProcedureTreeConditionalItem: CRASHLOGGER_PDB(59818@2026.10.24)
// ProcedureTreeVisitor, ProcedureTreeVisitor::Visit, ProcedureTreeVisitor::Unk_01, ProcedureTreeVisitor::ShouldStop, BGSProcedureTreeConditionalItem::Unk_01, BGSProcedureTreeConditionalItem::Unk_02, BGSProcedureTreeConditionalItem::Unk_03, BGSProcedureTreeConditionalItem::Unk_04, BGSProcedureTreeConditionalItem::Unk_05, BGSProcedureTreeConditionalItem::Unk_06, BGSProcedureTreeConditionalItem::Unk_07, BGSProcedureTreeConditionalItem::Unk_08, BGSProcedureTreeConditionalItem::Unk_09, BGSProcedureTreeConditionalItem::Unk_0A, BGSProcedureTreeConditionalItem::Unk_0B, BGSProcedureTreeConditionalItem::Func12_140429280, BGSProcedureTreeConditionalItem::unk08, ConditionalItemArray, ConditionalItemArray::data, ConditionalItemArray::unk08, ConditionalItemArray::size: GUESS(low); offsets and virtual slots observed in listing
#pragma once

#include <cstddef>
#include <cstdint>

class BGSProcedureTreeConditionalItem;

class ProcedureTreeVisitor
{
public:
    virtual void Visit(BGSProcedureTreeConditionalItem* a_item);  // 00
    virtual void Unk_01();                                        // 01
    virtual bool ShouldStop();                                    // 02
};

class BGSProcedureTreeConditionalItem
{
public:
    virtual ~BGSProcedureTreeConditionalItem();                        // 00
    virtual void Unk_01();                                             // 01
    virtual void Unk_02();                                             // 02
    virtual void Unk_03();                                             // 03
    virtual void Unk_04();                                             // 04
    virtual void Unk_05();                                             // 05
    virtual void Unk_06();                                             // 06
    virtual void Unk_07();                                             // 07
    virtual void Unk_08();                                             // 08
    virtual void Unk_09();                                             // 09
    virtual void Unk_0A();                                             // 0A
    virtual void Unk_0B();                                             // 0B
    virtual void Func12_140429280(ProcedureTreeVisitor* a_visitor);    // 0C

    std::uint64_t unk08;  // 08
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
    void Func12_140429280(ProcedureTreeVisitor* a_visitor) override;

    ConditionalItemArray conditions;  // 10
};
static_assert(offsetof(BGSProcedureTreeBranch, conditions) == 0x10, "BGSProcedureTreeBranch::conditions offset");
