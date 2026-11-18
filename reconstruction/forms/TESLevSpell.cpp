// Code origin: hand-written from the local listings; names and declarations from the community header named in TESLevSpell.h.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none
// 0x272ee0 TESLevSpell::SaveGame
// 0x272f20 TESLevSpell::LoadGame
// 0x272f60 TESLevSpell::Revert
#include "TESLevSpell.h"

// TESLeveledList is a secondary base at offset 0x30, so the base calls take this + 0x30.
void TESLevSpell::SaveGame(BGSSaveFormBuffer* a_buf)
{
    TESForm::SaveGame(a_buf);
    TESLeveledList::SaveGame(a_buf);
}

void TESLevSpell::LoadGame(BGSLoadFormBuffer* a_buf)
{
    TESForm::LoadGame(a_buf);
    TESLeveledList::LoadGame(a_buf);
}

void TESLevSpell::Revert(BGSLoadFormBuffer* a_buf)
{
    TESForm::Revert(a_buf);
    TESLeveledList::Revert(a_buf);
}
