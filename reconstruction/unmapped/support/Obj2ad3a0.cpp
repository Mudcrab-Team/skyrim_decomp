// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x2ad3a0 Obj2ad3a0::Function2ad3a0
// Adapted bodies: none
#include "Obj2ad3a0.h"

// Updates the float parameter at offset 0x108 on each land quadrant's first child shader property.
void Obj2ad3a0::Function2ad3a0(float a_value)
{
    if (!data40) {
        return;
    }
    for (int i = 0; i < 4; ++i) {
        QuadNode2ad3a0* quad = data40->quads[i];
        if (quad && quad->childCount > 0u) {
            Child2ad3a0* child = quad->children[0];
            if (child && child->prop128) {
                child->prop128->value108 = a_value;
            }
        }
    }
}
