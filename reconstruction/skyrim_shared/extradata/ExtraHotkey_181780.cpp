// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction using the observed comparison and public declarations.
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// Adapted bodies: none
// 0x181780 ExtraHotkey::IsNotEqual
#include "ExtraHotkey_181780.h"

bool ExtraHotkey::IsNotEqual(const BSExtraData* other) const
{
    return static_cast<const ExtraHotkey*>(other)->hotkey != hotkey;
}
