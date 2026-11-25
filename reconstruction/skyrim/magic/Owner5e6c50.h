// Source exposure: mixed.
// Code origin: Stamped as a twin of matched 0x5c6900 (skyrim/magic/DualValueModifierEffect): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/DualValueModifierEffect.cpp:32
// Function5e6c50, Owner5e6c50: GUESS(low) STANDIN
#pragma once
#include "DualValueModifierEffect.h"

class Owner5e6c50 : public ResearchLayouts::ValueModifierEffectLayout
{
public:
    float secondaryAVWeight;
    void Function5e6c50(BGSSaveFormBuffer* buffer);
    Function5bb090Result* Function5bb090();  // 0x5bb090
    unsigned int Function5c6ae0();
    float Function5c6b60() const;
};
