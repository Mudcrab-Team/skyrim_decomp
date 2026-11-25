// Source exposure: mixed (pinned image, RTTI, and CommonLibSSE-NG declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: the attributed methods follow the public headers, with flag polarity from the pinned image. Stamped as a twin of matched 0x1e6900 (skyrim_shared/forms/TESForm_1466a0): source copied, names replaced by placeholders.
// 0xaa5e30 Owneraa5e30::Functionaa5e30
#include "Owneraa5e30.h"

// guess: same compiled code as matched 0x1e6900 apart from relocated fields; its role here is not established.
bool Owneraa5e30::Functionaa5e30(TESFile& file)
{
    return file.Function1ce0d0(reinterpret_cast<TESForm*>(this));
}
