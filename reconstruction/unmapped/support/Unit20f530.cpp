// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x20f530 Unit20f530::Close20f530
// Adapted bodies: none
#include "Unit20f530.h"

#include <intrin.h>

// PDB: the CrashLogger PDB name is BSResource__CompressedArchiveStream::sub_140F46030; the stand-in name here is kept.
// Atomically clears bits 1-3 of flags and tail-calls ReleaseStream.
void Unit20f530::Close20f530()
{
    long oldFlags;
    do {
        oldFlags = flags;
        // Atomic compare-exchange clearing state bits 1-3 in flags.
    } while (_InterlockedCompareExchange(&flags, oldFlags & ~0xEL, oldFlags) != oldFlags);
    ReleaseStream();
}
