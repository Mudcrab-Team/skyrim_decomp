// Source exposure: mixed (pinned image and cited community names).
// Code origin: original deleting destructor emitted from the measured allocation size.
// BSParticleShaderGeometry: GUESS(low)
// Class spelling follows the qualified Address Library names.
// BSParticleShaderGeometry::~BSParticleShaderGeometry: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
#pragma once

#include <cstdint>

class BSParticleShaderGeometry
{
public:
    BSParticleShaderGeometry();
    virtual ~BSParticleShaderGeometry();

private:
    std::uint8_t padding08[0x178];
};
static_assert(sizeof(BSParticleShaderGeometry) == 0x180, "measured allocation size");
