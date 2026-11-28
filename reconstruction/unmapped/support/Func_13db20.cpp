// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x13db20 Func_13db20::DestroyRange
// Adapted bodies: none
#include "Func_13db20.h"

// Destroys each 0x58-byte entry in [first, last), freeing its pointer vector.
void Func_13db20::DestroyRange(Entry13db20* first, Entry13db20* last)
{
    for (; first != last; ++first)
    {
        first->~Entry13db20();
    }
}
