// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementations from the pinned listings and partial declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x272030 TESLevItem::InitItemImpl
// 0x272130 TESLevItem::SaveGame
// 0x2721b0 TESLevItem::Revert
// Adapted bodies: none
#include "TESLevItem_272030.h"

// ApplyFormFlag: GUESS(low)
void ApplyFormFlag(TESForm* form, bool value);

// TestBit: GUESS(low)
static bool TestBit(std::uint32_t flags, std::uint32_t bit)
{
    return ((flags >> bit) & 1) != 0;
}

void TESLevItem::InitItemImpl()
{
    if (!TestBit(formFlags, 3)) {
        leveledList.Init(this);
        return ApplyFormFlag(this, true);
    }
}

void TESLevItem::SaveGame(BGSSaveFormBuffer* buffer)
{
    TESForm::SaveGame(buffer);
    return leveledList.SaveGame(buffer);
}

void TESLevItem::Revert(BGSLoadFormBuffer* buffer)
{
    TESForm::Revert(buffer);
    return leveledList.Revert(buffer);
}
