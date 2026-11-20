// Code origin: original; the listing and community declarations only
// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSLight: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSLight::Unk_03, BSLight::~BSLight: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown10: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include "gamebryo/nimain/NiRefObject.h"

// RefCountedStandIn: GUESS(low); the pointee of the shared reference, only the vptr slots and count the code uses
class RefCountedStandIn
{
public:
    virtual ~RefCountedStandIn();
    virtual void DeleteThis();
    std::uint32_t refCount;
};

// sharedLightRef: GUESS(low); a global owning reference at RVA 0x3698bf0
extern RefCountedStandIn* sharedLightRef;

class BSLight : public NiRefObject
{
public:
    BSLight();
    virtual bool Unk_03();  // compared: 0x1578880
    virtual ~BSLight();  // compared: 0x1578840 (scalar deleting destructor)

    static void Function1576a90();  // compared: 0x1576a90

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown10[0x130];  // 10
};
static_assert(sizeof(BSLight) == 0x140, "BSLight size");
