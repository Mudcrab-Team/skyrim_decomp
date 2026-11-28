// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj1c9750::SetSize, treated as adapted: shaped like NiTArray::SetSize in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00c60000_od_ob1_variant.cpp:2566
// SPDX-License-Identifier: CC0-1.0
// 0x1c9750 Obj1c9750::SetSize
#include "Obj1c9750.h"

// Resizes the pointer array to a_newSize, truncating trailing entries or zero-filling new slots.
void Obj1c9750::SetSize(std::uint32_t a_newSize)
{
    if (a_newSize == cap10) {
        return;
    }
    if (a_newSize < size12) {
        for (std::uint16_t i = static_cast<std::uint16_t>(a_newSize); i < size12; ++i) {
            if (data08[i]) {
                data08[i] = 0;
                --count14;
            }
        }
        size12 = static_cast<std::uint16_t>(a_newSize);
    }
    void** old = data08;
    cap10 = static_cast<std::uint16_t>(a_newSize);
    if (a_newSize) {
        data08 = static_cast<void**>(NiMalloc1c9750(static_cast<std::size_t>(cap10) * sizeof(void*)));
        for (std::uint16_t i = 0; i < size12; ++i) {
            data08[i] = old[i];
        }
        for (std::uint16_t i = size12; i < cap10; ++i) {
            data08[i] = 0;
        }
    } else {
        data08 = 0;
    }
    NiFree1c9750(old);
}
