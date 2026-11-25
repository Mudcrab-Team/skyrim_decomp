// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// Code origin: Stamped as a twin of matched 0x240230 (skyrim_shared/actors/BGSActionData): source copied, names replaced by placeholders.
// the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Function955bf0, Owner955bf0: GUESS(low) STANDIN
// ActionInput, unknown28, Owner955bf0::Function240230: GUESS(low) STANDIN
#pragma once
#include "BGSActionData.h"
#include <new>

class Owner955bf0 : public ActionInput
{
public:
    void Function955bf0();
    virtual bool Process();

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown28[0x30];  // 28
};
static_assert(sizeof(Owner955bf0) == 0x60, "Owner955bf0 size");
