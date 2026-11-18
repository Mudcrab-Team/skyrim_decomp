// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// BGSSaveGameBuffer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BGSSaveGameBuffer::GetActor, BGSSaveGameBuffer::GetForm, BGSSaveGameBuffer::GetReference: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Actor, TESForm, TESObjectREFR: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Actor;
class TESForm;
class TESObjectREFR;

class BGSSaveGameBuffer
{
public:
    virtual Actor* GetActor();  // compared: 0x63a2e0
    virtual TESForm* GetForm();  // compared: 0x63a2f0
    virtual TESObjectREFR* GetReference();  // compared: 0x63a300

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown08[0x10];  // 08
};
static_assert(sizeof(BGSSaveGameBuffer) == 0x18, "BGSSaveGameBuffer size");
