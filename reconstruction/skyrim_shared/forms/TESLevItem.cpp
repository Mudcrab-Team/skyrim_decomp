// Source exposure: mixed (community headers and pinned image).
// Code origin: existing sibling-adapted LoadGame plus original reconstruction of SaveGame, Revert, and helpers.
// Adapted bodies: TESLevItem::LoadGame ~ momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/teslevcharacter.cpp:19 (no-licence); SaveGame, Revert, Function272110, Function272120 original.
// IsLeveledItemFormType: GUESS(low)
// 0x272110 TESLevItem::Function272110
// 0x272120 TESLevItem::Function272120
// 0x272130 TESLevItem::SaveGame
// 0x272170 TESLevItem::LoadGame
// 0x2721b0 TESLevItem::Revert
#include "TESLevItem.h"

bool IsLeveledItemFormType(std::uint8_t a_formType);

std::uint32_t TESLevItem::Function272110() const
{
    return g_levItem207ACE8;
}

bool TESLevItem::Function272120(std::uint8_t a_formType) const
{
    return IsLeveledItemFormType(a_formType);
}

void TESLevItem::SaveGame(BGSSaveFormBuffer* a_buf)
{
    TESForm::SaveGame(a_buf);
    leveledList.SaveGame(a_buf);
}

void TESLevItem::LoadGame(BGSLoadFormBuffer* a_buf)
{
    TESForm::LoadGame(a_buf);
    return leveledList.LoadGame(a_buf);
}

void TESLevItem::Revert(BGSLoadFormBuffer* a_buf)
{
    TESForm::Revert(a_buf);
    leveledList.Revert(a_buf);
}
