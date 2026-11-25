// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ParticleArrayFfc200: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionffc200: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>


class ParticleArrayFfc200
{
public:
    void** entries;
    std::uint64_t unknown08;
    unsigned count;
    unsigned Partition(void*, unsigned, unsigned);

    void Functionffc200(void* key, unsigned first, unsigned last);
};
