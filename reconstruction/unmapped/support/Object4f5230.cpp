// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0x4f5230 Object4f5230::Object4f5230
// Adapted bodies: none
#include "Object4f5230.h"

// Constructs Base4f5230 and SubData4f5230, then sets flag bits 0x50 on flagsBA.
Object4f5230::Object4f5230() : Base4f5230(), subData()
{
    flagsBA |= 0x50u;
}
