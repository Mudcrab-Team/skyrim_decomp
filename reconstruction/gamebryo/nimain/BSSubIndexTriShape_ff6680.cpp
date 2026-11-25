// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xff6680 BSSubIndexTriShape::Functionff6680
// Adapted bodies: none
#include "BSSubIndexTriShape_ff6680.h"

void BSSubIndexTriShape::Functionff6680(uint32_t a_index, uint32_t a_a, uint32_t a_b)
{
    subSegments[a_index].a = a_a;
    subSegments[a_index].b = a_b;
    subSegments[a_index].d = a_b;
    flag170 = true;
}
