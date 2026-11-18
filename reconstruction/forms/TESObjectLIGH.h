// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// TESObjectLIGH: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESObject, TESBoundObject, TESBoundAnimObject: STANDIN EXE_RTTI
// TESObjectLIGH::Activate, TESObjectLIGH::SaveGame: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESBoundObject::Activate: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the Activate body tail-calls it (0x278e50)
// TESForm::SaveGame: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the SaveGame body calls it first (0x1e5700)
// TestBit: GUESS(low); flag bit tested as a load, read through a by-value helper
// SaveValueState: GUESS(low); callee at 0x1f3660 that takes the sub-object at +0xB0 (NG: TESValueForm there)
// unknownEC: GUESS(low); NG nests the light flags as data.flags at 0xE0 + 0x0C
// unknown20, unknownB0: GUESS(low); padding around the members the bodies read
#pragma once

#include <cstdint>
#include "../forms/TESForm.h"

class BGSSaveFormBuffer;
class TESObjectLIGH;

// Callee of SaveGame (RVA 0x1f3660); declared, not defined here.
void SaveValueState(void* a_value, BGSSaveFormBuffer* a_buf);

// TestBit: GUESS(low); flag bit tested as a load, read through a by-value helper.
inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

class TESObject : public TESForm
{
public:
};

class TESBoundObject : public TESObject
{
public:
    virtual bool Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, std::uint8_t a_arg3, TESBoundObject* a_object, std::int32_t a_targetCount);  // 37
};

class TESBoundAnimObject : public TESBoundObject
{
public:
};

class TESObjectLIGH : public TESBoundAnimObject
{
public:
    virtual bool Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, std::uint8_t a_arg3, TESBoundObject* a_object, std::int32_t a_targetCount);  // compared: 0x275080
    virtual void SaveGame(BGSSaveFormBuffer* a_buf);  // compared: 0x275210

    std::uint8_t unknown20[0x90];  // 20
    std::uint8_t unknownB0[0x3C];  // B0
    std::uint32_t unknownEC;  // EC
};
