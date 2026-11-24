// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0xeeb4f0 (gamebryo/nimain/BSDynamicTriShape_eeb4f0): source copied, names replaced by placeholders. Loose twin: member offsets differ from the exemplar and follow this function's code.
// SPDX-License-Identifier: CC0-1.0
// 0x8141b0 Owner8141b0::Function8141b0
#include "Owner8141b0.h"

// guess: same compiled code as matched 0xeeb4f0 apart from relocated fields; its role here is not established.
void Owner8141b0::Function8141b0()
{
    RefCounted* held = object;
    if (held) {
        object = nullptr;
        // atomic release of a shared reference; the last holder deletes the object
        if (_InterlockedDecrement(&held->refCount) == 0) {
            held->DeleteThis();
        }
    }
}
