// Source exposure: mixed (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled in the header
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// CI hash: 0x812bd0 ??__G@YAXPEAX0_K1P6APEAX00@Z@Z
// 0x812bd0 vector copy ctor iterator
// Adapted bodies: none
#include "ArrayElement_812bd0.h"

// The implicit copy of the array member goes through the compiler's vector copy constructor iterator helper.
ArrayHolder CopyHolder(const ArrayHolder& other)
{
    return other;
}
