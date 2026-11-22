// Source exposure: mixed (pinned image and cited community names).
// 0xefd6e0 compared function
// Code origin: original deleting destructor emitted from the measured allocation size.
// BSParticleShaderGeometry: GUESS(low)
// Class spelling follows the qualified Address Library names.
// BSParticleShaderGeometry::~BSParticleShaderGeometry: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
#pragma once

#include <cstdint>

// BSSpinLock, value160, spinLock: GUESS(low); names invented, offsets read from the listing.
class BSSpinLock
{
public:
    void Lock(unsigned int a_flag);
    std::uint32_t value;
};

class BSParticleShaderGeometry
{
public:
    BSParticleShaderGeometry();
    virtual ~BSParticleShaderGeometry();
    void* Functionefd6e0();  // compared: 0xefd6e0

private:
    std::uint8_t padding08[0x158];  // 08
    void* value160;                 // 160
    BSSpinLock spinLock;            // 168
    std::uint8_t padding16C[0x14];  // 16C
};
static_assert(sizeof(BSParticleShaderGeometry) == 0x180, "measured allocation size");
