// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none (write "none" when attempt prints no "origin advice" line;
// otherwise name each adapted body, its upstream file, revision and licence).
// 0x2a0b60 BSParticleShaderCubeEmitter::~BSParticleShaderCubeEmitter
#include "BSParticleShaderCubeEmitter.h"

bool BSParticleShaderCubeEmitter::Generate(bool, NiPoint3&, NiPoint3&)
{
    return false;
}

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BSParticleShaderCubeEmitter::BSParticleShaderCubeEmitter()
{
}

