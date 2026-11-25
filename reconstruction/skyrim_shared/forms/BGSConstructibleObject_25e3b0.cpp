// Source exposure: mixed (permitted sibling naming and local binary analysis).
// Code origin: reconstruction using the labelled sources and pinned-image observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSConstructibleObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CanBeCreatedOnWorkbench: SIBLING(fo4-private@1b765c70, author-permission)
// Adapted body: CanBeCreatedOnWorkbench, independently expressed with the permitted sibling control-flow lead.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/BGSConstructibleObject.cpp:82
// 0x25e3b0 BGSConstructibleObject::CanBeCreatedOnWorkbench
#include "BGSConstructibleObject_25e3b0.h"

bool BGSConstructibleObject::CanBeCreatedOnWorkbench(TESFurniture* bench, bool checkConditions) const
{
    bool eligible;
    if (bench)
        eligible = bench->keywordForm.HasKeyword(benchKeyword);
    else
        eligible = false;
    if (eligible && conditions.head && checkConditions)
        return conditions.IsTrue(PlayerCharacter::singleton, PlayerCharacter::singleton);
    return eligible;
}
