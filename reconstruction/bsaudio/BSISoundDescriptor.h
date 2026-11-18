// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSISoundDescriptor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSISoundDescriptor::~BSISoundDescriptor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>

class BSISoundDescriptor
{
public:
    BSISoundDescriptor();
    virtual ~BSISoundDescriptor() {}  // compared: 0x32ac50 (scalar deleting destructor)
};
static_assert(sizeof(BSISoundDescriptor) == 0x8, "BSISoundDescriptor size");
