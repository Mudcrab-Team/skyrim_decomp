// Source exposure: mixed. Based on local instruction listings of the
// pinned image, with the class layout from the header beside this file. Names are from
// CharmedBaryon/CommonLibSSE-NG b93280e (MIT); the powerof3 fork (GPL-3.0) uses the same ones.
// Code origin: original; the listing and community declarations only Stamped as a twin of matched 0x270960 (skyrim_shared/world/TESGrass): source copied, names replaced by placeholders.
// SPDX-License-Identifier: CC0-1.0
// 0x14e5410 Owner14e5410::GetMaxSlopeDegrees
#include "Owner14e5410.h"

// The constructor is not compared: it is defined so that this unit emits the vftables and with
// them the deleting destructor, as the original unit did. Its body is a minimal stand-in.
Owner14e5410::Owner14e5410()
{
}

// guess: same compiled code as matched 0x270960 apart from relocated fields; its role here is not established.
std::uint8_t Owner14e5410::GetMaxSlopeDegrees() const
{
    return data.maxSlopeDegrees;
}
