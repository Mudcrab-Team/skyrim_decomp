// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none
// 0x7ddfe0 ArrowProjectile::ShouldBeLimited
// 0x7ddf80 ArrowProjectile::GetPowerSpeedMult
// 0x7de0f0 ArrowProjectile::Update3D
// 0x7ddfa0 ArrowProjectile::GetWeaponSpeedMult
// 0x7ddf40 ArrowProjectile::GetGravity
#include "ArrowProjectile.h"

bool ArrowProjectile::ShouldBeLimited()
{
    return TestBit(flags, 22);
}

float ArrowProjectile::GetPowerSpeedMult() const
{
    PrepareSpeedQuery();
    return ComputeSpeedMult();
}

void ArrowProjectile::Update3D()
{
    if (!TestBit(flags, 22)) {
        ResolveAttachedNodes();
    }
}

float ArrowProjectile::GetWeaponSpeedMult() const
{
    if (ammoSource) {
        return ScaleAmmoSpeed(ammoSource->unk170);
    }
    return 1.0f;
}

float ArrowProjectile::GetGravity()
{
    const float base = GetBaseGravity();
    const float one = g_gravityOne;
    return one - (one - base) * range;
}

// Accepted leaf retained from the integrated version.
// Slot195: GUESS(low); method name inferred from vtable owner and slot
std::uint8_t ArrowProjectile::Slot195() const
{
    return 0x1;
}
