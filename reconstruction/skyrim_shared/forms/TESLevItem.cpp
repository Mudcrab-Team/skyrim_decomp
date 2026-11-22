// Source exposure: mixed (community headers and pinned-image analysis).
// Code origin: existing sibling-adapted LoadGame and original reconstruction of two helpers.
// Adapted bodies: TESLevItem::LoadGame ~ momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/teslevcharacter.cpp:19 (no-licence).
// IsLeveledItemFormType: GUESS(low)
// 0x272110 TESLevItem::Function272110
// 0x272120 TESLevItem::Function272120
// 0x272170 TESLevItem::LoadGame
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

void TESLevItem::LoadGame(BGSLoadFormBuffer* a_buf)
{
    TESForm::LoadGame(a_buf);
    return leveledList.LoadGame(a_buf);
}
