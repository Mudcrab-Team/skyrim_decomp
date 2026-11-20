// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSUIScaleformData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// IUIMessageData: STANDIN EXE_RTTI
// BSUIScaleformData::~BSUIScaleformData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// IUIMessageData::~IUIMessageData, unknown08, unknown10: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class IUIMessageData
{
public:
    virtual ~IUIMessageData() = default;
    std::uint8_t unknown08[0x8];  // 08
};
static_assert(sizeof(IUIMessageData) == 0x10, "IUIMessageData size");

class BSUIScaleformData : public IUIMessageData
{
public:
    BSUIScaleformData();
    virtual ~BSUIScaleformData();  // compared: 0x1169040 (scalar deleting destructor)

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown10[0x8];  // 10
};
static_assert(sizeof(BSUIScaleformData) == 0x18, "BSUIScaleformData size");
