// Source exposure: mixed (community declarations and pinned-image observations).
// Code origin: original reconstruction; compact community declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectCELL, TESForm, BGSListForm, ExtraDataList, extraList, formType: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetCount: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// Function2be7c0, QueryLockList: GUESS(low); unidentified predicate and lock-list query role
// unk00, unk08: OBSERVED
#pragma once
#include <cstdint>
#include <cstddef>

class TESForm
{
public:
    std::uintptr_t unk00;             // 00
    std::uint8_t unk08[0x12];         // 08
    std::uint8_t formType;            // 1A
};
class BGSListForm : public TESForm
{
public:
    std::uint32_t GetCount() const;
};
class ExtraDataList
{
public:
    TESForm* QueryLockList();
};
class TESObjectCELL
{
public:
    bool Function2be7c0();
    std::uint8_t unk00[0x48];         // 00
    ExtraDataList extraList;          // 48
};
static_assert(offsetof(TESForm, formType) == 0x1A, "form type offset");
static_assert(offsetof(TESObjectCELL, extraList) == 0x48, "extra list offset");
