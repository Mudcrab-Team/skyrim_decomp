// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x132180 FuncAllocator132180::Destroy
// Adapted bodies: none
#include "FuncAllocator132180.h"

// Destroys a single std::function instance.
// guess: a stateless allocator member; the call does not read this.
void FuncAllocator132180::Destroy(Func132180* a_ptr)
{
    a_ptr->~Func132180();
}
