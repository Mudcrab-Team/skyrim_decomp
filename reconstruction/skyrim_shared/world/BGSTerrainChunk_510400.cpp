// Source exposure: mixed (the pinned image listing; names from the sibling).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x510400 BGSBtrDB::DBTraits::ArgsType::WaitForTextures
// Adapted bodies: BGSBtrDB::DBTraits::ArgsType::WaitForTextures from fo4-private@1b765c70 src/Shared/DistantTerrain/BGSTerrainChunk.cpp:69 (see the header)
#include "BGSTerrainChunk_510400.h"

void BGSBtrDB::DBTraits::ArgsType::WaitForTextures() const
{
    BSTextureDB::WaitFor(Diffuse, true);
    BSTextureDB::WaitFor(Normal, true);
    BSTextureDB::WaitFor(BGSTerrainChunk::NoiseTextureHandle, true);
}
