// Code origin: original; the listing and community declarations only
// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectSTAT: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESObject, TESBoundObject: STANDIN EXE_RTTI
// TESObjectSTAT::IsHeadingMarker: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectSTAT::kIsSkyObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectSTAT::SetIsSkyObject: CRASHLOGGER_PDB(59818@2026.10.24)
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

// SetFormFlag: GUESS(low); the helper at address 0x1e6b60 that sets or clears a formFlags bit; declared, not defined here.
void SetFormFlag(TESForm* a_form, std::uint32_t a_flag, bool a_set);

class TESObjectSTAT : public TESBoundObject
{
public:
    enum : std::uint32_t { kIsSkyObject = 1u << 5 };

    virtual bool IsHeadingMarker() const;  // compared: 0x264510
    void SetIsSkyObject(bool a_set);
};
