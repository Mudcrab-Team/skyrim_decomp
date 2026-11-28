// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// CI hash: 0xfc8460 ?Func1_v5@BeamProjectile@@QEAA_NPEADI@Z
// 0xfc8460 BeamProjectile::Func1_v5
#include "BeamProjectile_fc8460.h"
// Parameter count or return type differs from the CrashLogger prototype: the signature here is
// inferred from the body and is a guess.
bool BeamProjectile::Func1_v5(char* a_buffer, std::uint32_t a_maxCount)
{
    strncpy_s(a_buffer, static_cast<std::size_t>(a_maxCount) + 1, gDescriptionLabel, a_maxCount);
    return false;
}
