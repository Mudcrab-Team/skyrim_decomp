// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// TESRegionData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESRegionData::LoadDataHeader: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown08, unk08, unknown09, unk0A, unknown0B: GUESS(low)
#pragma once

#include <cstdint>

class TESRegionData
{
public:
    virtual bool LoadDataHeader(void* a_arg1);  // compared: 0x24fee0
    // TESRegionData::TESRegionData: GUESS(low); defined so the vftable and the deleting destructor are emitted
    TESRegionData();
    // TESRegionData::~TESRegionData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the listing inlines the teardown, so the body is empty
    virtual ~TESRegionData() {}
    // TESRegionData::LoadData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    virtual void LoadData(void* a_arg1);  // compared: 0x24ff50

    std::uint8_t unk08;      // 08
    std::uint8_t unknown09;  // 09
    std::uint8_t unk0A;      // 0A
    std::uint8_t unknown0B[0x5];  // 0B
};
static_assert(sizeof(TESRegionData) == 0x10, "TESRegionData size");
