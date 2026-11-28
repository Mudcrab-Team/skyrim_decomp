// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; written from the pinned image listing
// Cookbook: 0x2c9880 16
// SPDX-License-Identifier: CC0-1.0
// 0x2c9880 TESObjectCELL2c9880::IncQueuedDistantRefCount
// Adapted bodies: none
#include "TESObjectCELL2c9880.h"

namespace
{
    // TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value (cookbook rule 16).
    bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
    {
        return ((a_flags >> a_bit) & 0x1u) != 0;
    }
}

// Resolves a persistent cell to the reference's loaded exterior cell and increments its queued count.
// NOTE: ws is null for an interior cell; the compared code calls through it without a test.
void TESObjectCELL2c9880::IncQueuedDistantRefCount(const Ref2c9880* a_ref)
{
    TESObjectCELL2c9880* cell = this;
    while (TestBit(cell->formFlags, 13u)) {
        WorldSpace2c9880* ws = (cell->cellFlags & 0x1u) ? nullptr : cell->worldSpace;
        cell = ws->GetCellAt(a_ref->pos54);
        if (!cell || cell->cellState != 7u) {
            return;
        }
    }
    // thread-safe queued distant reference counter increment
    _InterlockedIncrement(&cell->runtimeData->queuedRefCount);
    cell->runtimeData->field178 = -1;
}
