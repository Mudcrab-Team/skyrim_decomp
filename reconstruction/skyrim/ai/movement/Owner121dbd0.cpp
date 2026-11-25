// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0x7ab5f0 (skyrim/ai/movement/MovementTweenerAgentNodeFollower_7ab5f0): source copied, names replaced by placeholders. Loose twin: member offsets differ from the exemplar and follow this function's code.
// SPDX-License-Identifier: CC0-1.0
// 0x121dbd0 Owner121dbd0::Function121dbd0
#include "Owner121dbd0.h"

// guess: same compiled code as matched 0x7ab5f0 apart from relocated fields; its role here is not established.
void Owner121dbd0::Function121dbd0()
{
    if (unk28) {
        unk28->Unregister(&g_followerKey);
        unk28 = nullptr;
    }
}
