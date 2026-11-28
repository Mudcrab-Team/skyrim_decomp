// Source exposure: binary-analysis (pinned image listing).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: UIManagercefd60::UpdateCounter, treated as adapted: shaped like ControlMap::AllowTextInput (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/C/ControlMap.cpp:13, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xcefd60 UIManagercefd60::UpdateCounter
#include "UIManagercefd60.h"

// Increments counter when increment is true, or decrements it if non-zero otherwise.
// The community name table calls this UIManager::AllowTextInput1 (a hint, not proof); the names in this unit are stand-ins.
void UIManagercefd60::UpdateCounter(bool increment)
{
    if (increment) {
        ++counter;
    } else if (counter != 0) {
        --counter;
    }
}
