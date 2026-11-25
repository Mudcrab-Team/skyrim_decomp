// Source exposure: mixed
// Code origin: original reconstruction from the pinned image listing, shaped after the sibling.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x7ec3a0 GrenadeProjectile::ReportHavokDeactivation
// Adapted bodies: GrenadeProjectile::ReportHavokDeactivation follows momusdigital/fnv_decomp@91e1b6e8 src/fallout/ai/combat/grenadeprojectile.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout/ai/combat/grenadeprojectile.cpp:41
#include "GrenadeProjectile_7ec3a0.h"

static bool TestFlagByIndex(std::uint32_t a_word, unsigned a_bit)
{
    return ((a_word >> a_bit) & 1) != 0;
}

inline bool BGSProjectile::GetHasExplosionAltTrigger() const
{
    return TestFlagByIndex(data.flags, 2);
}

inline float BGSProjectile::GetExplosionProximity() const
{
    return data.explosionProximity;
}

void GrenadeProjectile::ReportHavokDeactivation()
{
    if (GetProjectileBase()->GetHasExplosionAltTrigger() &&
        !(0.0f >= GetProjectileBase()->GetExplosionProximity())) {
        Get3D2()->SetMotionType(5, true, false, true);
    }
}
