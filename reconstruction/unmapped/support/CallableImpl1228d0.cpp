// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x1228d0 CallableImpl1228d0::Move
// Adapted bodies: none
#include "CallableImpl1228d0.h"

// Placement-moves the callable implementation into caller-supplied storage.
CallableBase1228d0* CallableImpl1228d0::Move(void* a_where)
{
    return new (a_where) CallableImpl1228d0(*this);
}
