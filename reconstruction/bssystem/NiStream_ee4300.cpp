// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xee4300 NiStream::Load1
// Adapted bodies: none
#include "NiStream_ee4300.h"

bool NiStream::Load1(NiBinaryStream* source)
{
    bool ok = false;
    if (source->IsValid()) {
        binaryStream = source;
        ok = Load2();
    }
    binaryStream = nullptr;
    return ok;
}
