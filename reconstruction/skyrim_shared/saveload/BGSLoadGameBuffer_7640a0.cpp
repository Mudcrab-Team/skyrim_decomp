// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x7640a0 BGSLoadGameBuffer::sub_1406BB790
// Adapted bodies: none
#include "BGSLoadGameBuffer_7640a0.h"

// Loads version-gated global state values from the save buffer.
void BGSLoadGameBuffer::sub_1406BB790()
{
    if (GetVersion() >= 0x48) {
        LoadDataEndian(&g_saveState48, 4, 4);
    } else if (GetVersion() >= 0x44) {
        g_saveState48 = ReadByte() != 0;
    }

    if (GetVersion() >= 0x46) {
        g_saveFlag46 = ReadByte();
    }

    if (GetVersion() >= 0x47) {
        g_saveFlag47A = ReadByte();
        g_saveFlag47B = ReadByte();
        LoadDataEndian(&g_saveState47C, 4, 4);
    }
}
