// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0x6a5310 (skyrim_shared/actors/Character_6a5310): source copied, names replaced by placeholders. Loose twin: member offsets differ from the exemplar and follow this function's code.
// SPDX-License-Identifier: CC0-1.0
// 0x121cff0 Owner121cff0::Function121cff0
#include "Owner121cff0.h"

// guess: same compiled code as matched 0x6a5310 apart from relocated fields; its role here is not established.
void Owner121cff0::Function121cff0()
{
    RefCounted* old = held;
    if (old) {
        held = nullptr;
        old->DecRef();
    }
}
