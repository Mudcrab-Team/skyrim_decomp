// Source exposure: mixed. Drafted from local instruction listings of the
// pinned image, with the class layout from the header beside this file. Names are from
// CharmedBaryon/CommonLibSSE-NG b93280e (MIT); the powerof3 fork (GPL-3.0) uses the same ones.
// Code origin: original; the listing and community declarations only Stamped as a twin of matched 0x2709b0 (skyrim_shared/world/TESGrass): source copied, names replaced by placeholders.
// SPDX-License-Identifier: CC0-1.0
// 0xc3b390 Ownerc3b390::GetUnderwaterState
#include "Ownerc3b390.h"

// The constructor is not compared: it is defined so that this unit emits the vftables and with
// them the deleting destructor, as the original unit did. Its body is a minimal stand-in.
Ownerc3b390::Ownerc3b390()
{
}

// guess: same compiled code as matched 0x2709b0 apart from relocated fields; its role here is not established.
Ownerc3b390::GRASS_WATER_STATE Ownerc3b390::GetUnderwaterState() const
{
    return data.underwater;
}
