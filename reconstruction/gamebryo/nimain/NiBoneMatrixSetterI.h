// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// NiBoneMatrixSetterI: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// NiBoneMatrixSetterI::~NiBoneMatrixSetterI: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>

class NiBoneMatrixSetterI
{
public:
    NiBoneMatrixSetterI();
    virtual ~NiBoneMatrixSetterI() {}  // compared: 0x15797a0 (scalar deleting destructor)
};
static_assert(sizeof(NiBoneMatrixSetterI) == 0x8, "NiBoneMatrixSetterI size");
