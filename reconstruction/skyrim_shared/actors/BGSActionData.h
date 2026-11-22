// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// 0x240230 compared function
// the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSActionData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// ActionInput: STANDIN EXE_RTTI
// BGSActionData::Process: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActionInput::~ActionInput, unknown08, unknown28: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

// ActionPart: GUESS(low); subobject constructed by Function240230's inline constructor.
class ActionPart
{
public:
    ActionPart();
    std::uint64_t dummy;  // 00
};

class ActionInput
{
public:
    ActionInput() : part() {}
    ~ActionInput() = default;
    std::uint8_t pad00[0x8];  // 00
    ActionPart part;  // 08
    std::uint8_t unknown10[0x18];  // 10
};
static_assert(sizeof(ActionInput) == 0x28, "ActionInput size");

class BGSActionData : public ActionInput
{
public:
    // BGSActionData::Function240230: GUESS(low); placement-new factory, compared at RVA 0x240230
    void Function240230();
    virtual bool Process();  // compared: 0x240f40

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown28[0x30];  // 28
};
static_assert(sizeof(BGSActionData) == 0x60, "BGSActionData size");
