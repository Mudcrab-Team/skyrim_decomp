// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xee45a0 NiStream::Functionee45a0
// Adapted bodies: none
#include "NiStream_ee45a0.h"

void NiStream::Functionee45a0()
{
    if (state == 4) {
        worker->Forward();
        state = 1;
    }
}
