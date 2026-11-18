// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// BSMaterialObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSMaterialObject::EnsureLoaded, BSMaterialObject::~BSMaterialObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BSMaterialObject
{
public:
    BSMaterialObject();
    virtual void EnsureLoaded();  // compared: 0x1534210
    virtual ~BSMaterialObject();  // compared: 0x321da0 (scalar deleting destructor)

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown08[0x50];  // 08
};
static_assert(sizeof(BSMaterialObject) == 0x58, "BSMaterialObject size");
