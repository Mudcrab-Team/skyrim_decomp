// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementations from the pinned listings and partial declarations. Stamped as a twin of matched 0x3aee10 (skyrim_shared/audio/BGSVoiceType_3aee10): source copied, names replaced by placeholders. Loose twin: member offsets differ from the exemplar and follow this function's code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x533d70 Owner533d70::Function533d70
#include "Owner533d70.h"

// kEmptyString_533d70: GUESS(low) STANDIN
extern const char kEmptyString_533d70[];

// guess: same compiled code as matched 0x3aee10 apart from relocated fields; its role here is not established.
const char* Owner533d70::Function533d70() const
{
    const char* name = editorID;
    return name ? name : kEmptyString_533d70;
}
