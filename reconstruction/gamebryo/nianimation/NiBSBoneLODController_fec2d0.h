// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// NiBSBoneLODController: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionfec2d0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Entryfec2d0, Freefec2d0: GUESS(low) STANDIN; bone-level storage
void Freefec2d0(void*);
struct Entryfec2d0 { void* data; std::uint64_t unknown08; ~Entryfec2d0() { Freefec2d0(data); } };

class NiBSBoneLODController
{
public:
    std::uint8_t unknown00[0x58];
    Entryfec2d0** entries;
    unsigned short capacity;
    unsigned short count;
    unsigned short used;

    void Functionfec2d0();
};
