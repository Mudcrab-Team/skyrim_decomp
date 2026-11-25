// Source exposure: mixed (community declarations and the pinned image listing).
// Code origin: original reconstruction; community names and declarations as labelled below.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x9a2980 BGSLoadGameBuffer::ReadVersion6Byte
// Adapted bodies: none. Target sse-steam-1-7-104; identity is RVA, names remain evidence labels.
#include "BGSLoadGameBuffer_9a2980.h"

void BGSLoadGameBuffer::ReadVersion6Byte()
{
    if (GetVersion() >= 6) {
        LoadDataEndian(&gVersion6Byte, 1, 1);
    }
}
