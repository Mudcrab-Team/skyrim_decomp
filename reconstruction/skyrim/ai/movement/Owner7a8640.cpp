// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0x7ab5f0 (skyrim/ai/movement/MovementTweenerAgentNodeFollower_7ab5f0): source copied, names replaced by placeholders.
// SPDX-License-Identifier: CC0-1.0
// 0x7a8640 Owner7a8640::Function7a8640
#include "Owner7a8640.h"

// guess: same compiled code as matched 0x7ab5f0 apart from relocated fields; its role here is not established.
void Owner7a8640::Function7a8640()
{
    if (unk28) {
        unk28->Unregister(&g_followerKey);
        unk28 = nullptr;
    }
}
