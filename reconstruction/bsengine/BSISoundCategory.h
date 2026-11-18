// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSISoundCategory: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSISoundCategory::~BSISoundCategory: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>

class BSISoundCategory
{
public:
    BSISoundCategory();
    virtual ~BSISoundCategory();  // compared: 0x329dc0 (scalar deleting destructor)
};
static_assert(sizeof(BSISoundCategory) == 0x8, "BSISoundCategory size");
