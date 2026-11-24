// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x272950 TESLevSpell::GetLeveledSpell
// Adapted bodies: TESLevSpell::GetLeveledSpell follows fo4-private@1b765c70 src/Shared/TESForms/Objects/TESLevSpell.cpp:132
#include "TESLevSpell_272950.h"

SpellItem* TESLevSpell::GetLeveledSpell(MagicSystem::School aeSchool, short asLevel)
{
    TESForm* result = 0;
    unsigned short count;
    CalculateCurrentForm(aeSchool, asLevel, result, count, true);
    return result ? dynamic_cast<SpellItem*>(result) : 0;
}
