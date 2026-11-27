// Near miss: 9.5 alignment distance | control-flow
// Exposure detail: (local binary analysis and permitted sibling source).
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: adapted RemovePerk pointer walk, checked against the local target.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Character/BGSPerk.cpp:317
// BGSPerk: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// RemovePerk: SIBLING(fo4-private@1b765c70, author-permission)
// Cookbook: 20
// 0x397810 BGSPerk::RemovePerk

#include "include/397810/BGSPerk_397810.h"

void BGSPerk::RemovePerk(Actor* actor)
{
    if (perkEntries._size) {
        BGSPerkEntry** it = perkEntries._data;
        BGSPerkEntry** end = it + perkEntries._size;
        while (it != end) {
            if (*it)
                (*it)->RemovePerkEntry(actor);
            ++it;
        }
    }
}
