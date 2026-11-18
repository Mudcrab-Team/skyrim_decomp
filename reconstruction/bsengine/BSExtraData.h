// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSExtraData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSExtraData::IsNotEqual, BSExtraData::~BSExtraData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BSExtraData
{
public:
    BSExtraData();
    virtual bool IsNotEqual(const BSExtraData* a_rhs) const;  // compared: 0x1565d0
    virtual ~BSExtraData() {}  // compared: 0x156400 (scalar deleting destructor)

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown08[0x8];  // 08
};
static_assert(sizeof(BSExtraData) == 0x10, "BSExtraData size");
