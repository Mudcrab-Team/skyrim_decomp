// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x1305a30 Holder1305a30::GetShared
// Adapted bodies: none
#include "Holder1305a30.h"

// Returns a copy of the stored std::shared_ptr, incrementing its reference count if non-null.
std::shared_ptr<Element1305a30> Holder1305a30::GetShared() const
{
    return ptr;
}
