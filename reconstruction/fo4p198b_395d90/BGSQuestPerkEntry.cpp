// Source exposure: mixed
// Origin: authorized sibling and community declarations
// BGSQuestPerkEntry::ApplyPerkEntry: SIBLING(fo4-private@1b765c70, author-permission); adapted using target evidence
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Character/BGSPerk.cpp:260
// BGSPerkEntry: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/B/BGSPerkEntry.h
// names: GUESS(low); derived declarations and signatures remain provisional
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x395d90 BGSQuestPerkEntry::ApplyPerkEntry
#include "BGSQuestPerkEntry.h"
void BGSQuestPerkEntry::ApplyPerkEntry(Actor*) {
    if (data.quest) {
        bool delayed = false;
        if (data.quest->EnsureQuestStarted(delayed, true))
            data.quest->SetStage(data.stage);
    }
}
