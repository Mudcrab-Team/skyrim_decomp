// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1f0a00 Unit1f0a00::CopyName1f0a00
// Adapted bodies: none
#include "Unit1f0a00.h"

// Copies the name string from a dynamically cast Unit1f0a00 source via SetName.
void Unit1f0a00::CopyName1f0a00(BaseComponent1f0a00* a_source)
{
    Unit1f0a00* source = dynamic_cast<Unit1f0a00*>(a_source);
    if (source) {
        SetName(source->name ? source->name : "");
    }
}
