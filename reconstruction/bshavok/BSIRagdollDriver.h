// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
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
