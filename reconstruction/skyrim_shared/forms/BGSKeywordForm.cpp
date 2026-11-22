// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x14c8b0 BGSKeywordForm::GetDefaultKeyword
// 0x1d8690 Leaf1d8690::Invoke
// 0x1d85e0 BGSKeywordForm::BGSKeywordForm
// BGSKeywordForm::BGSKeywordForm: GUESS(low); a constructor storing the vftable and zeroing both members
#include "BGSKeywordForm.h"

BGSKeywordForm::BGSKeywordForm()
{
    keywords = nullptr;
    numKeywords = 0;
}

// GetDefaultKeyword: the target returns a null pointer.
BGSKeyword* BGSKeywordForm::GetDefaultKeyword() const
{
    return nullptr;
}

// InitializeDataComponent: the target has no work to do.
void BGSKeywordForm::InitializeDataComponent()
{
}
