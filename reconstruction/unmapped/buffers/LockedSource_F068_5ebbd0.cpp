// Source exposure: mixed (binary-analysis, community-headers).
// Community source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT.
// Array storage, indexed search, append and removal reconstructed from the selected build.
// LockedSource_F068_5ebbd0, Sink, Event, ArrayFunctor, ArrayStorage, ArrayBase, Lock, Guard: GUESS(low) STANDIN
// Add, Remove, Push, Find, At, Erase, EraseExternal, Reserve, Move, Allocate, Reallocate, Deallocate, Unlock: GUESS(low)
// data, capacity, size, array, owner, count, sinks, pendingRegisters, pendingUnregisters, lock, notifying, ProcessEvent: GUESS(low)
// GetCurrentThreadId: OBSERVED
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x5ebbd0 p117_5ebbd0::LockedSource_F068_5ebbd0::Remove
#include "LockedSource_F068_5ebbd0.h"
namespace p117_5ebbd0 {
void LockedSource_F068_5ebbd0::Remove(Sink* sink) {
    if (!sink) return;
    Guard guard(lock);
    if (notifying) {
        if (pendingUnregisters.Find(sink) == ~0u) pendingUnregisters.Push(sink);
    } else {
        unsigned index = sinks.Find(sink);
        if (index != ~0u) sinks.EraseExternal(index, 1);
    }
    unsigned index = pendingRegisters.Find(sink);
    if (index != ~0u) pendingRegisters.Erase(index);
}
}
