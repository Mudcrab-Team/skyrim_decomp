// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1c7b40 Obj1c7b40::Init
// Adapted bodies: none.
#include "Obj1c7b40.h"

// Initializes the base, attaches and retains the intrusive target pointer, and stores arg10.
void Obj1c7b40::Init(void* a_arg1, void* a_arg2, RefTarget1c7b40* const& a_target)
{
    InitBase(a_arg2);
    target08 = a_target;
    if (a_target) {
        a_target->IncRef();
    }
    arg10 = a_arg1;
}
