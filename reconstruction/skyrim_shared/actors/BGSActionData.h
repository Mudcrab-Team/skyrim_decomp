// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSActionData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// ActionInput: STANDIN EXE_RTTI
// BGSActionData::Process: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActionInput::~ActionInput, unknown08, unknown28: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class ActionInput
{
public:
    virtual ~ActionInput() = default;
    std::uint8_t unknown08[0x20];  // 08
};
static_assert(sizeof(ActionInput) == 0x28, "ActionInput size");

class BGSActionData : public ActionInput
{
public:
    virtual bool Process();  // compared: 0x240f40

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown28[0x38];  // 28
};
static_assert(sizeof(BGSActionData) == 0x60, "BGSActionData size");
