// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1c6ab0 Obj1c6ab0::Assign
// Adapted bodies: none.
#include "Obj1c6ab0.h"

#include <intrin.h>

// Copies the intrusive smart pointer from a_rhs, updating packed 12-bit-shifted reference counts.
Obj1c6ab0& Obj1c6ab0::Assign(const Obj1c6ab0& a_rhs)
{
    RefTarget1c6ab0* rhs = a_rhs.ptr;
    RefTarget1c6ab0* old = ptr;
    if (rhs != old) {
        if (rhs) {
            long cur = rhs->refCount10;
            long prev;
            do {
                prev = cur;
                // atomic packed upper-bit reference count increment
                cur = _InterlockedCompareExchange(&rhs->refCount10, cur + 0x1000, prev);
            } while (cur != prev);
        }
        ptr = rhs;
        if (old) {
            long cur = old->refCount10;
            long prev;
            long next;
            do {
                prev = cur;
                next = cur - 0x1000;
                // atomic packed upper-bit reference count decrement
                cur = _InterlockedCompareExchange(&old->refCount10, next, prev);
            } while (cur != prev);
            if ((static_cast<std::uint32_t>(next) & 0xFFFFF000u) == 0) {
                delete old;
            }
        }
    }
    return *this;
}
