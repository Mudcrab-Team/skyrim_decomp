// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// BSIRagdollDriver: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSIRagdollDriver::~BSIRagdollDriver: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>

class BSIRagdollDriver
{
public:
    BSIRagdollDriver();
    virtual ~BSIRagdollDriver();  // compared: 0xbd9940 (scalar deleting destructor)
};
static_assert(sizeof(BSIRagdollDriver) == 0x8, "BSIRagdollDriver size");
