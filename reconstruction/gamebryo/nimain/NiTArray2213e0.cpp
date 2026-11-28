// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x2213e0 NiTArray2213e0::~NiTArray2213e0
// Adapted bodies: none
#include "NiTArray2213e0.h"

// Release the backing array buffer.
NiTArray2213e0::~NiTArray2213e0()
{
    NiFree2213e0(data);
}
