// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementations from the pinned listings and partial declarations. Stamped as a twin of matched 0x3aee10 (skyrim_shared/audio/BGSVoiceType_3aee10): source copied, names replaced by placeholders. Loose twin: member offsets differ from the exemplar and follow this function's code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x532f30 Owner532f30::Function532f30
#include "Owner532f30.h"

// kEmptyString_532f30: GUESS(low) STANDIN
extern const char kEmptyString_532f30[];

// guess: same compiled code as matched 0x3aee10 apart from relocated fields; its role here is not established.
const char* Owner532f30::Function532f30() const
{
    const char* name = editorID;
    return name ? name : kEmptyString_532f30;
}
