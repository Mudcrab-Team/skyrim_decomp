// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; written from the pinned image listing
// Cookbook: 0x2c9900 16
// SPDX-License-Identifier: CC0-1.0
// 0x2c9900 TESObjectCELL2c9900::DecQueuedDistantRefCount
// Adapted bodies: none
#include "TESObjectCELL2c9900.h"

namespace
{
    // TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value (cookbook rule 16).
    bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
    {
        return ((a_flags >> a_bit) & 0x1u) != 0;
    }
}

// Decrements the loaded cell's queued distant reference counter and schedules unload when it reaches zero.
// NOTE: ws is null for an interior cell; the compared code calls through it without a test.
void TESObjectCELL2c9900::DecQueuedDistantRefCount(const Ref2c9900* a_ref)
{
    TESObjectCELL2c9900* cell = this;
    while (cell->runtimeData) {
        if (!TestBit(cell->formFlags, 13u)) {
            // thread-safe queued distant reference counter decrement
            _InterlockedDecrement(&cell->runtimeData->queuedRefCount);
            if (cell->runtimeData->queuedRefCount < 0) {
                cell->runtimeData->queuedRefCount = 0;
            }
            if (cell->runtimeData->queuedRefCount == 0) {
                cell->runtimeData->expireTimeMs =
                    static_cast<std::uint32_t>(g_unloadDelaySec2c9900 * 1000.0f) + g_currentTimeMs2c9900;
            }
            return;
        }
        WorldSpace2c9900* ws = (cell->cellFlags & 0x1u) ? nullptr : cell->worldSpace;
        cell = ws->GetCellAt(a_ref->pos54);
        if (!cell || cell->cellState != 7u) {
            return;
        }
    }
}
