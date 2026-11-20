// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none
// 0x7df690 BarrierProjectile::UpdateImpl
// 0x7df760 BarrierProjectile::Revert
#include "BarrierProjectile.h"

void BarrierProjectile::UpdateImpl(float a_delta)
{
    if (!(objectReference->unkF0 > transparency)) {
        Kill();
    }
}

void BarrierProjectile::Revert(BGSLoadFormBuffer* a_buf)
{
    Projectile::Revert(a_buf);
    unk1E0 = 0;
}

// Accepted leaf retained from the integrated version.
// Slot167: GUESS(low); method name inferred from vtable owner and slot
std::uint8_t BarrierProjectile::Slot167() const
{
    return 0x1;
}
