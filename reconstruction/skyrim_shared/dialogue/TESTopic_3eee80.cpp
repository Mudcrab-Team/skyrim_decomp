// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementations from the pinned listings and partial declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x3eee80 TESTopic::IsParentForm
// 0x3efd00 TESTopic::GetFormEditorID
// Adapted bodies: none
#include "TESTopic_3eee80.h"

// kEmptyString: OBSERVED
extern const char kEmptyString[];

bool TESTopic::IsParentForm() const
{
    return true;
}

const char* TESTopic::GetFormEditorID() const
{
    const char* name = editorID;
    return name ? name : kEmptyString;
}
