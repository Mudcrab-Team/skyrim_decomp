// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x122890 CallableImpl122890::Copy
// Adapted bodies: none
#include "CallableImpl122890.h"

// Placement-copies the callable implementation into caller-supplied storage.
CallableBase122890* CallableImpl122890::Copy(void* a_where) const
{
    return new (a_where) CallableImpl122890(*this);
}
