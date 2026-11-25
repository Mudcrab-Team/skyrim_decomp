// Source exposure: mixed (Skyrim binary analysis, community declarations, fo4-private reconstruction).
// Code origin: Stamped as a twin of matched 0x1db8f0 (skyrim_shared/forms/BGSSkinForm_1db8f0): source copied, names replaced by placeholders.
// Origin: adapted from the cited anonymous permitted sibling body; partial Skyrim class view.
// Licence: fo4-private reused with author permission conditional on anonymity (awarebayes, 2026-11-14).
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/BGSSkinForm.cpp:25
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1d1f40 Owner1d1f40::CopyComponent
// CopyComponent: GUESS(low) STANDIN
#include "Owner1d1f40.h"

// guess: same compiled code as matched 0x1db8f0 apart from relocated fields; its role here is not established.
void Owner1d1f40::CopyComponent(BaseFormComponent *apCopyFC)
{
    Owner1d1f40 *pSkinForm = dynamic_cast<Owner1d1f40 *>(apCopyFC);
    if (pSkinForm)
    {
        pFormSkin = pSkinForm->pFormSkin;
    }

}
