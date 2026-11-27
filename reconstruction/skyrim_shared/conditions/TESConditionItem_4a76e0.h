// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/AI/TESConditionItem.cpp:101
// TESConditionItem, TESConditionItem::Compare, TESParameters::Compare: SIBLING(fo4-private@1b765c70, author-permission)
// TESConditionItem::next, FUNCTION_DATA, CONDITION_ITEM_DATA: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESConditionItem::Data: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0); the same name stands in the sibling body
// CONDITION_ITEM_DATA::pGlobal, CONDITION_ITEM_DATA::hRunOnRef, CONDITION_ITEM_DATA::uiDataID, CONDITION_ITEM_DATA::FunctionData, CONDITION_ITEM_DATA::iFlags, CONDITION_ITEM_DATA::eObject, RunOnRefHandle, RunOnRefHandle::iBits: GUESS(medium); names from the sibling body, declared outside the permitted folders
// unknown00, unknown2a: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct FUNCTION_DATA
{
    std::uint8_t unknown00[0x18];  // 00
};
static_assert(sizeof(FUNCTION_DATA) == 0x18, "FUNCTION_DATA size");

namespace TESParameters
{
    bool Compare(const FUNCTION_DATA& a_first, const FUNCTION_DATA& a_second);
}

struct RunOnRefHandle
{
    std::uint32_t iBits;  // 00
};

struct CONDITION_ITEM_DATA
{
    void* pGlobal;               // 00
    RunOnRefHandle hRunOnRef;    // 08
    std::uint32_t uiDataID;      // 0C
    FUNCTION_DATA FunctionData;  // 10
    std::uint8_t iFlags;         // 28
    std::uint8_t eObject;        // 29
    std::uint8_t unknown2a[6];   // 2A
};
static_assert(sizeof(CONDITION_ITEM_DATA) == 0x30, "CONDITION_ITEM_DATA size");

struct TESConditionItem
{
    bool Compare(const TESConditionItem* a_other) const;

    TESConditionItem* next;  // 00
    CONDITION_ITEM_DATA Data;  // 08
};
static_assert(sizeof(TESConditionItem) == 0x38, "TESConditionItem size");
