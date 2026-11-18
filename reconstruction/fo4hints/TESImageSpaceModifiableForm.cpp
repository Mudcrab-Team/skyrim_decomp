// Source exposure: mixed (Skyrim binary analysis, community declarations, fo4-private reconstruction).
// Origin: adapted from the cited anonymous permitted sibling body; partial Skyrim class view.
// Licence: fo4-private reused with author permission conditional on anonymity (awarebayes, 2026-11-14).
// TESImageSpaceModifiableForm: SIBLING(fo4-private@1b765c70, author-permission)
// CopyComponent: SIBLING(fo4-private@1b765c70, author-permission)
// Padding and incomplete declarations: STANDIN GUESS(low); no complete-layout or behaviour claim.
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESImageSpaceModifiableForm.cpp:58
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1e8720 TESImageSpaceModifiableForm::CopyComponent
#include "TESImageSpaceModifiableForm.h"

void TESImageSpaceModifiableForm::CopyComponent(BaseFormComponent *apCopyFC)
{
    TESImageSpaceModifiableForm *pCopy = dynamic_cast<TESImageSpaceModifiableForm *>(apCopyFC);
    if (pCopy)
        pFormImageSpaceModifying = pCopy->pFormImageSpaceModifying;

}
