// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/AI/TESConditionItem.cpp:161
// CONDITION_ITEM_DATA, CONDITION_ITEM_DATA::Copy, TESParameters::Copy: SIBLING(fo4-private@1b765c70, author-permission)
// CONDITION_ITEM_DATA::pGlobal, CONDITION_ITEM_DATA::hRunOnRef, CONDITION_ITEM_DATA::uiDataID, CONDITION_ITEM_DATA::FunctionData, CONDITION_ITEM_DATA::iFlags, CONDITION_ITEM_DATA::eObject: GUESS(medium); member names from the sibling body, declared outside the permitted folders
// FUNCTION_DATA: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// RunOnRefHandle, RunOnRefHandle::iBits: GUESS(low); stand-in for the handle type
// unknown00: GUESS(low)
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
    void Copy(const FUNCTION_DATA& a_from, FUNCTION_DATA& a_to);
}

struct RunOnRefHandle
{
    std::uint32_t iBits;  // 00
};

struct CONDITION_ITEM_DATA
{
    void Copy(const CONDITION_ITEM_DATA& a_copyFrom);

    void* pGlobal;               // 00
    RunOnRefHandle hRunOnRef;    // 08
    std::uint32_t uiDataID;      // 0C
    FUNCTION_DATA FunctionData;  // 10
    std::uint8_t iFlags;         // 28
    std::uint8_t eObject;        // 29
    std::uint8_t unknown2a[6];   // 2A
};
static_assert(sizeof(CONDITION_ITEM_DATA) == 0x30, "CONDITION_ITEM_DATA size");
