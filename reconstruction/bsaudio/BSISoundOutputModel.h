// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSISoundOutputModel: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSISoundOutputModel::~BSISoundOutputModel: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>

class BSISoundOutputModel
{
public:
    BSISoundOutputModel();
    virtual ~BSISoundOutputModel();  // compared: 0x32baa0 (scalar deleting destructor)
};
static_assert(sizeof(BSISoundOutputModel) == 0x8, "BSISoundOutputModel size");
