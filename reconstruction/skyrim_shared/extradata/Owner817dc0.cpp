// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0x1869c0 (skyrim_shared/extradata/ExtraGuardedRefData_1869c0): source copied, names replaced by placeholders. Loose twin: constants differ from the exemplar and follow this function's code.
// SPDX-License-Identifier: CC0-1.0
// 0x817dc0 Owner817dc0::Function817dc0
#include "Owner817dc0.h"

// guess: same compiled code as matched 0x1869c0 apart from relocated fields; its role here is not established.
void Owner817dc0::Function817dc0(BGSLoadGameBuffer* buffer)
{
    buffer->ReadFormID(&refId);
    buffer->LoadDataEndian(&value, 4, 4);
    buffer->LoadDataEndian(&flag, 4, 4);
}
