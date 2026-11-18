// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/teslevcharacter.cpp:19
// TESLevItem: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESObject, TESBoundObject: STANDIN EXE_RTTI
// TESLevItem::LoadGame: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
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

class TESLeveledList
{
public:
    // LoadGame: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
    void LoadGame(BGSLoadFormBuffer* a_buf);
};

class TESLevItem : public TESBoundObject
{
public:
    virtual void LoadGame(BGSLoadFormBuffer* a_buf);  // compared: 0x272170

    // unknown20: GUESS(low)
    std::uint8_t unknown20[0x10];  // 20
    // leveledList: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
    TESLeveledList leveledList;  // 30
};
