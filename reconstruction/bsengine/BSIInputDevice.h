// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSIInputDevice: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSIInputDevice::~BSIInputDevice: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>

class BSIInputDevice
{
public:
    BSIInputDevice();
    virtual ~BSIInputDevice() {}  // compared: 0xcfc0b0 (scalar deleting destructor)
};
static_assert(sizeof(BSIInputDevice) == 0x8, "BSIInputDevice size");
