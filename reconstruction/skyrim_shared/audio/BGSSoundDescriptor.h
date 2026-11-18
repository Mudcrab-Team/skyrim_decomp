// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSSoundDescriptor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSISoundDescriptor: STANDIN EXE_RTTI
// BGSSoundDescriptor::~BGSSoundDescriptor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSISoundDescriptor::~BSISoundDescriptor, unknown08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BSISoundDescriptor
{
public:
    virtual ~BSISoundDescriptor() = default;
};
static_assert(sizeof(BSISoundDescriptor) == 0x8, "BSISoundDescriptor size");

class BGSSoundDescriptor : public BSISoundDescriptor
{
public:
    BGSSoundDescriptor();
    virtual ~BGSSoundDescriptor();  // compared: 0x32c8a0 (scalar deleting destructor)

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown08[0x10];  // 08
};
static_assert(sizeof(BGSSoundDescriptor) == 0x18, "BGSSoundDescriptor size");
