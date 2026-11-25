// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// Code origin: Stamped as a twin of matched 0x7ddf80 (skyrim_shared/refs/ArrowProjectile): source copied, names replaced by placeholders.
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// 0x15a8324 Owner15a8324::GetPowerSpeedMult
#include "Owner15a8324.h"

// guess: same compiled code as matched 0x7ddf80 apart from relocated fields; its role here is not established.
float Owner15a8324::GetPowerSpeedMult() const
{
    PrepareSpeedQuery();
    return ComputeSpeedMult();
}
