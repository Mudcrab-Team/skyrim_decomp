// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0x1082b90 Object1082b90::Unk_30
// Adapted bodies: none
#include "Object1082b90.h"

// Invokes Slot37(false) when unk10 is non-null, then invokes Slot43(true).
// The community name table calls this PathingRequestFlee::Func3 (a hint, not proof); the names in this unit are stand-ins.
void Object1082b90::Unk_30()
{
    if (unk10 != nullptr) {
        Slot37(false);
    }
    Slot43(true);
}
