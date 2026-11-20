// Source exposure: mixed.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// DualValueModifierEffect::SaveGame: SIBLING(fo4-private@1b765c70, author-permission); adapted to observed target behavior.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/DualValueModifierEffect.cpp:32
// DualValueModifierEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/D/DualValueModifierEffect.h.
// names: GUESS(low); method signatures and local names are inferred.
// 0x5c6900 DualValueModifierEffect::SaveGame
#include "DualValueModifierEffect.h"
void DualValueModifierEffect::SaveGame(BGSSaveFormBuffer* buffer) { ResearchLayouts::ActiveEffectLayout::SaveGame(buffer); buffer->Write(&secondaryAVWeight, 4, 4, 0); }
