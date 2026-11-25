// Source exposure: mixed.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/DualValueModifierEffect.cpp:32
// Code origin: Function5c6ae0 and Function5c6b60 original, from the listing and community declarations only Stamped as a twin of matched 0x5c6900 (skyrim/magic/DualValueModifierEffect): source copied, names replaced by placeholders.
// 0x5e6c50 Owner5e6c50::Function5e6c50
#include "Owner5e6c50.h"

// guess: same compiled code as matched 0x5c6900 apart from relocated fields; its role here is not established.
void Owner5e6c50::Function5e6c50(BGSSaveFormBuffer* buffer) { ResearchLayouts::ActiveEffectLayout::SaveGame(buffer); buffer->Write(&secondaryAVWeight, 4, 4, 0); }
