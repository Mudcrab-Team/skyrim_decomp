// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementations from the pinned listings and partial declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x3aee10 BGSVoiceType::GetFormEditorID
// Adapted bodies: none
#include "BGSVoiceType_3aee10.h"

// kEmptyString: OBSERVED
extern const char kEmptyString[];

const char* BGSVoiceType::GetFormEditorID() const
{
    const char* name = editorID;
    return name ? name : kEmptyString;
}
