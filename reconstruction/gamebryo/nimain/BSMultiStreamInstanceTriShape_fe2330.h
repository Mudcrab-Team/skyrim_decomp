// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSMultiStreamInstanceTriShape: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionfe2330: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>


class BSMultiStreamInstanceTriShape
{
public:
    std::uint8_t unknown00[0x178];
    unsigned first;
    unsigned second;
    unsigned third;
    void CopyBase(BSMultiStreamInstanceTriShape*, void*);

    void Functionfe2330(BSMultiStreamInstanceTriShape* output, void* context);
};
