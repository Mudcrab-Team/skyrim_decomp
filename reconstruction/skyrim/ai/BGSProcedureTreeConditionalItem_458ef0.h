// Source exposure: mixed (community headers; the pinned image listing).
// BGSProcedureTreeConditionalItem: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// IProcedureTreeItem: STANDIN EXE_RTTI
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESCondition: STANDIN COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// TESCondition::head: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; kept as a plain 8-byte value, only its size matters here
// TESCondition::~TESCondition, BGSProcedureTreeConditionalItem::condition: GUESS(low)
#pragma once

#include <cstdint>

class TESCondition
{
public:
    ~TESCondition();

    std::uint64_t head;  // 00
};
static_assert(sizeof(TESCondition) == 0x8, "TESCondition size");

class IProcedureTreeItem
{
public:
    virtual ~IProcedureTreeItem() {}
};

class BGSProcedureTreeConditionalItem : public IProcedureTreeItem
{
public:
    ~BGSProcedureTreeConditionalItem() override;

    TESCondition condition;  // 08
};
static_assert(sizeof(BGSProcedureTreeConditionalItem) == 0x10, "BGSProcedureTreeConditionalItem size");
