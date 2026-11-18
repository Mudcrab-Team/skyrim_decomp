// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"low","kind":"guess","owner":"ConeProjectile","rationale":"vtable owner and slot; method spelling invented","slot":194},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// ConeProjectile: EXE_RTTI
// Slot194: GUESS(low)
// member, padding: GUESS(low); storage names invented for the measured member offset
// 0x7e1880 ConeProjectile::Slot194
#include "ConeProjectile.h"
// Slot194: GUESS(low); method name inferred from vtable owner and slot
std::uint8_t ConeProjectile::Slot194() const
{
    return 0x1;
}

bool ConeProjectile::GetKillOnCollision()
{
    return false;
}
