// Source exposure: mixed (local pinned-image observations and community declarations).
// Code origin: original reconstruction; no external bodies used.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x156aab0 NiMemStream::Function156aab0
// Adapted bodies: none
#include "NiMemStream_156aab0.h"

void NiMemStream::Function156aab0(bool doSwap)
{
    if (doSwap) {
        readFn = ReadSwap;
        writeFn = WriteSwap;
    } else {
        readFn = ReadNoSwap;
        writeFn = WriteNoSwap;
    }
}
