// Source exposure: mixed
// Origin: authorized sibling and community declarations
// MagicCaster::FinishLoadGame: SIBLING(fo4-private@1b765c70, author-permission); adapted using target evidence
// Sibling source: fo4-private@1b765c70 src/Game/Magic/MagicCaster.cpp:379
// MagicCaster, MagicCaster::PrepareSound, MagicCaster::currentSpell: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/M/MagicCaster.h
// names: GUESS(low); signature and local iteration are provisional
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x5cd660 MagicCaster::FinishLoadGame
#include "MagicCaster.h"
void MagicCaster::FinishLoadGame(BGSLoadGameBuffer*) {
    MagicItem* spell = currentSpell;
    if (spell) {
        for (int i = 0; i <= 4; ++i) {
            PrepareSound(static_cast<MagicSystem::SoundID>(i), spell);
        }
    }
}
