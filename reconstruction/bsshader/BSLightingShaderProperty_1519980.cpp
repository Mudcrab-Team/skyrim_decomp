// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x1519980 BSLightingShaderProperty::OnLoadTextureSet
// Adapted bodies: none
#include "BSLightingShaderProperty_1519980.h"

void BSLightingShaderProperty::OnLoadTextureSet(std::uint64_t a_arg1)
{
    // kModelSpaceNormals: GUESS(low); bit 12 of the shader property flags
    const std::int64_t kModelSpaceNormals = 0x1000;
    material->OnLoadTextureSet(a_arg1, nullptr, (flags & kModelSpaceNormals) <= 0);
}
