// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using cited declarations and stand-in layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x1251e50 BSPathingSearchAreaRestrictions::Read
#include "BSPathingSearchAreaRestrictions_1251e50.h"

// Reads the search area center coordinates and radius from the stream.
// Parameter count or return type differs from the CrashLogger prototype: the signature here is
// inferred from the body and is a guess.
void BSPathingSearchAreaRestrictions::Read(BSPathingReadStream1251e50* stream)
{
    stream->ReadFloat(&center.x);
    stream->ReadFloat(&center.y);
    stream->ReadFloat(&center.z);
    stream->ReadFloat(&radius);
}
