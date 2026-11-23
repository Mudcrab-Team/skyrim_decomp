// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x180eb0 ExtraLock::~ExtraLock
// Adapted bodies: none
#include "ExtraLock_180eb0.h"

void operator delete(void*, unsigned __int64) noexcept;

ExtraLock::~ExtraLock()
{
    ::operator delete(lock, 0x20);
}
