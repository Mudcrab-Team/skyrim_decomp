// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0x1305bc0 Function1305bc0
// Adapted bodies: none
#include "FreeFunction_1305bc0.h"

// Reports whether the passed shared_ptr is non-null before releasing it.
bool Function1305bc0(std::shared_ptr<void> ptr)
{
    return ptr != nullptr;
}
