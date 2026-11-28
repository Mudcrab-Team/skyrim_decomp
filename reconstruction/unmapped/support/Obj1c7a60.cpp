// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj1c7a60::Compact, treated as adapted: shaped like NiTArray::Compact in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00c60000_od_ob1_variant.cpp:1415
// SPDX-License-Identifier: CC0-1.0
// 0x1c7a60 Obj1c7a60::Compact
#include "Obj1c7a60.h"

// Compacts non-null entries to the front of the array and reallocates storage to fit count14.
void Obj1c7a60::Compact()
{
    if (count14 == size12) {
        return;
    }
    if (count14) {
        std::uint16_t i = 0;
        std::uint16_t dst = 0;
        for (; i < size12; ++i) {
            if (data08[i]) {
                if (data08[dst] != data08[i]) {
                    data08[dst] = data08[i];
                }
                ++dst;
            }
        }
    }
    void** old = data08;
    size12 = count14;
    cap10 = count14;
    if (cap10) {
        data08 = static_cast<void**>(NiMalloc1c7a60(static_cast<std::size_t>(cap10) * sizeof(void*)));
        for (std::uint16_t i = 0; i < size12; ++i) {
            data08[i] = old[i];
        }
    } else {
        data08 = 0;
    }
    NiFree1c7a60(old);
}
