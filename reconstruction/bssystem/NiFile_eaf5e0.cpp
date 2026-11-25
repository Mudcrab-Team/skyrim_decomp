// Source exposure: mixed (community declarations and pinned-image observations).
// Code origin: original reconstruction from observed callback selection.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none.
// 0xeaf5e0 NiFile::Functioneaf5e0
#include "NiFile_eaf5e0.h"

// Select the stream callbacks for the requested byte order.
void NiFile::Functioneaf5e0(bool enabled)
{
    if (enabled) {
        _readFn = ReadSwap;
        _writeFn = WriteSwap;
    } else {
        _readFn = ReadNoSwap;
        _writeFn = WriteNoSwap;
    }
}
