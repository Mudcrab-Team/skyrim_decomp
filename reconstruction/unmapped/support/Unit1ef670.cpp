// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1ef670 Unit1ef670::CopyFrom1ef670
// Adapted bodies: none
#include "Unit1ef670.h"

// Copies the 32-bit value field when the source component dynamically casts to Unit1ef670.
void Unit1ef670::CopyFrom1ef670(BaseComponent1ef670* a_source)
{
    Unit1ef670* source = dynamic_cast<Unit1ef670*>(a_source);
    if (source) {
        value = source->value;
    }
}
