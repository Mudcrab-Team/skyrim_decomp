// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectSTAT: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESObject, TESBoundObject: STANDIN EXE_RTTI
// TESObjectSTAT::IsHeadingMarker: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include "TESForm.h"

class TESObject : public TESForm
{
public:
};

class TESBoundObject : public TESObject
{
public:
};

// TestBit: GUESS(low)
inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit) { return ((a_flags >> a_bit) & 1) != 0; }

class TESObjectSTAT : public TESBoundObject
{
public:
    virtual bool IsHeadingMarker() const;  // compared: 0x264510
};
