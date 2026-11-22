// Source exposure: mixed (community headers and pinned image).
// Code origin: existing sibling-adapted LoadGame plus original reconstruction of SaveGame, Revert, and helpers.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/teslevcharacter.cpp:19
// TESLevItem, TESLevItem::SaveGame, TESLevItem::LoadGame, TESLevItem::Revert: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESObject, TESBoundObject: STANDIN EXE_RTTI
// TESLeveledList, leveledList: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
// g_levItem207ACE8, unknown20, Function272110, Function272120: GUESS(low)
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
    void SaveGame(BGSSaveFormBuffer* a_buf);
    void LoadGame(BGSLoadFormBuffer* a_buf);
    void Revert(BGSLoadFormBuffer* a_buf);
};

class TESLevItem : public TESBoundObject
{
public:
    void SaveGame(BGSSaveFormBuffer* a_buf) override;  // compared: 0x272130
    void LoadGame(BGSLoadFormBuffer* a_buf) override;  // compared: 0x272170
    void Revert(BGSLoadFormBuffer* a_buf) override;  // compared: 0x2721b0
    std::uint32_t Function272110() const;
    bool Function272120(std::uint8_t a_formType) const;

    std::uint8_t unknown20[0x10];  // 20
    TESLeveledList leveledList;  // 30
};
