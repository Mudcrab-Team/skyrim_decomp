// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// NiTexture: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// NiTexture::Unk_28, NiTexture::~NiTexture: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// a_arg1, a_arg2, a_arg3, a_arg4: GUESS(low)
// unknown10: GUESS(low)
#pragma once

#include <cstdint>
#include "../netimmerse/NiObject.h"

class NiTexture : public NiObject
{
public:
    NiTexture();
    virtual void Unk_28(std::uint32_t& a_arg1, std::uint32_t& a_arg2, std::uint32_t& a_arg3, std::uint32_t& a_arg4);  // compared: 0xf05970
    // Keep the complete destructor as a separate call, matching the engine's out-of-line cleanup.
    __declspec(noinline) virtual ~NiTexture();  // compared: 0xef3ea0 (scalar deleting destructor)

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown10[0x30];  // 10
};
static_assert(sizeof(NiTexture) == 0x40, "NiTexture size");
