// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x7e9020 Explosion::Function7e9020
// Adapted bodies: none
#include "Explosion_7e9020.h"

bool Explosion::Function7e9020()
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
