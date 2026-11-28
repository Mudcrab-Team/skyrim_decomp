// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x192840 Obj192840::FormatDescription
// Adapted bodies: none.
#include "Obj192840.h"

// PDB: the CrashLogger PDB name is QueuedHelmet::sub_140144DE0; the stand-in name here is kept.
// Formats the string at offset 0x308 into a_buf using the global format string and returns true.
// guess: the CrashLogger PDB marks the called address FID_conflict:sprintf_s; the declaration here is a stand-in.
bool Obj192840::FormatDescription(char* a_buf, std::uint32_t a_size) const
{
    FormatBuffer192840(a_buf, a_size, gFormat192840, unk308);
    return true;
}
