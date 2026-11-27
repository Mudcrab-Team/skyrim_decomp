// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSLODTriShape: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionf1b2d0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>


class BSLODTriShape
{
public:
    std::uint8_t unknown00[0x108];
    std::uint8_t flag;
    std::uint8_t unknown109[0x2f];
    unsigned first;
    unsigned second;
    unsigned third;
    void CopyBase(BSLODTriShape*, void*);

    void Functionf1b2d0(BSLODTriShape* output, void* context);
};
