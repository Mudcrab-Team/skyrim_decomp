// Source exposure: mixed (pinned image, RTTI, and CommonLibSSE-NG declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: the attributed methods follow the public headers, with flag polarity from the pinned image. Stamped as a twin of matched 0x1469a0 (skyrim_shared/forms/TESForm_1466a0): source copied, names replaced by placeholders.
// 0x15a0920 Owner15a0920::LoadEdit
#include "Owner15a0920.h"

// guess: same compiled code as matched 0x1469a0 apart from relocated fields; its role here is not established.
bool Owner15a0920::LoadEdit(TESFile* file)
{
    return Load(file);
}
