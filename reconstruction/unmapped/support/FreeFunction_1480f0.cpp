// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x1480f0 Function1480f0
// Adapted bodies: none
#include "FreeFunction_1480f0.h"

// Loads the three 32-bit fields of record from the buffer in first, third, second order.
void Function1480f0(Triplet1480f0* record, LoadBuffer1480f0* buffer)
{
    buffer->LoadDataEndian(&record->first, 4, 4);
    buffer->LoadDataEndian(&record->third, 4, 4);
    buffer->LoadDataEndian(&record->second, 4, 4);
}
