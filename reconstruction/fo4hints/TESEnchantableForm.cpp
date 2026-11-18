// Source exposure: mixed (Skyrim binary analysis, community declarations, fo4-private reconstruction).
// Origin: adapted from the cited anonymous permitted sibling body; partial Skyrim class view.
// Licence: fo4-private reused with author permission conditional on anonymity (awarebayes, 2026-11-14).
// TESEnchantableForm: SIBLING(fo4-private@1b765c70, author-permission)
// CopyComponent: SIBLING(fo4-private@1b765c70, author-permission)
// Padding and incomplete declarations: STANDIN GUESS(low); no complete-layout or behaviour claim.
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESEnchantableForm.cpp:76
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1e1f70 TESEnchantableForm::CopyComponent
#include "TESEnchantableForm.h"

void TESEnchantableForm::CopyComponent(BaseFormComponent *apCopyFC)
{
    TESEnchantableForm *pCopy = dynamic_cast<TESEnchantableForm *>(apCopyFC);
    if (pCopy)
    {
        this->pFormEnchanting = pCopy->pFormEnchanting;
        this->iAmountofEnchantment = pCopy->iAmountofEnchantment;
        this->eCastingType = pCopy->GetCastingType();
    }

}
