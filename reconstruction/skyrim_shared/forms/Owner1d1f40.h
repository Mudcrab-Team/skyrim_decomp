// Source exposure: mixed (Skyrim binary analysis, community declarations, fo4-private reconstruction).
// Code origin: Stamped as a twin of matched 0x1db8f0 (skyrim_shared/forms/BGSSkinForm_1db8f0): source copied, names replaced by placeholders.
// Origin: adapted from the cited anonymous permitted sibling body; partial Skyrim class view.
// Licence: fo4-private reused with author permission conditional on anonymity (awarebayes, 2026-11-14).
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/BGSSkinForm.cpp:25
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Owner1d1f40: GUESS(low) STANDIN
// CopyComponent: GUESS(low) STANDIN
#pragma once
#include "BGSSkinForm_1db8f0.h"

class Owner1d1f40: public BaseFormComponent { public:
virtual void CopyComponent(BaseFormComponent *apCopyFC);
class TESObjectARMO* pFormSkin;
};
