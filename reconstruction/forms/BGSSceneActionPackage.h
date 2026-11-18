// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// BGSSceneActionPackage: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BGSSceneActionPackage::Unk_0B, BGSSceneActionPackage::Unk_11: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// RawAt: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include "../forms/BGSSceneAction.h"

template <class T>
T& RawAt(const void* a_base, std::ptrdiff_t a_offset)
{
    return *reinterpret_cast<T*>(const_cast<std::uint8_t*>(reinterpret_cast<const std::uint8_t*>(a_base)) + a_offset);
}

class BGSSceneActionPackage : public BGSSceneAction
{
public:
    virtual void Unk_0B();  // compared: 0x3ac610
    virtual void Unk_11();  // compared: 0x3ac2b0
};
