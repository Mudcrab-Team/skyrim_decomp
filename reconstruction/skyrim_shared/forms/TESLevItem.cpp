// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: TESLevItem::LoadGame ~ momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/teslevcharacter.cpp:19 (no-licence) (write "none" when attempt prints no "origin advice" line;
// otherwise name each adapted body, its upstream file, revision and licence).
// 0x272170 TESLevItem::LoadGame
#include "TESLevItem.h"

// TODO body: RVA 0x272170, 43 bytes, TESLevItem::LoadGame.
void TESLevItem::LoadGame(BGSLoadFormBuffer* a_buf)
{
    TESForm::LoadGame(a_buf);
    return leveledList.LoadGame(a_buf);
}
