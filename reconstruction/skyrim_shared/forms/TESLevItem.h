// Source exposure: mixed (community headers and pinned-image analysis).
// Code origin: existing community and sibling declarations plus two helpers from pinned-image analysis.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/teslevcharacter.cpp:19
// TESLevItem: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESObject, TESBoundObject: STANDIN EXE_RTTI
// TESLevItem::LoadGame: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// g_levItem207ACE8, Function272110, Function272120: GUESS(low)
#pragma once

#include <cstdint>
#include "TESForm.h"

extern std::uint32_t g_levItem207ACE8;

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
    std::uint32_t Function272110() const;
    bool Function272120(std::uint8_t a_formType) const;

    // unknown20: GUESS(low)
    std::uint8_t unknown20[0x10];  // 20
    // leveledList: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
    TESLeveledList leveledList;  // 30
};
