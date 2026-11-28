// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using cited declarations and stand-in layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x1251df0 BSPathingSearchAreaRestrictions::Write
#include "BSPathingSearchAreaRestrictions_1251df0.h"

// Writes the search area center coordinates and radius to the stream.
// Parameter count or return type differs from the CrashLogger prototype: the signature here is
// inferred from the body and is a guess.
void BSPathingSearchAreaRestrictions::Write(BSPathingWriteStream1251df0* stream)
{
    stream->WriteFloat(center.x);
    stream->WriteFloat(center.y);
    stream->WriteFloat(center.z);
    stream->WriteFloat(radius);
}
