// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x12ea8a0 Holder12ea8a0::Reset
// Adapted bodies: none
#include "Holder12ea8a0.h"

// Clears three 64-bit fields and resets the trailing std::shared_ptr member.
void Holder12ea8a0::Reset()
{
    unk08 = 0;
    unk10 = 0;
    unk18 = 0;
    ptr.reset();
}
