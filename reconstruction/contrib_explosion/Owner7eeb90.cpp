// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0x7e9020 (contrib_explosion/Explosion_7e9020): source copied, names replaced by placeholders.
// SPDX-License-Identifier: CC0-1.0
// 0x7eeb90 Owner7eeb90::Function7eeb90
#include "Owner7eeb90.h"

// guess: same compiled code as matched 0x7e9020 apart from relocated fields; its role here is not established.
bool Owner7eeb90::Function7eeb90()
{
    if (!unkA0 || unk70()) {
        return true;
    }
    if (unkA0) {
        std::uint32_t type = unkA0->flags0C & 0x70000000;
        if (type == 0x30000000 || type == 0x40000000) {
            unk6A(nullptr);
            return true;
        }
    }
    return false;
}
