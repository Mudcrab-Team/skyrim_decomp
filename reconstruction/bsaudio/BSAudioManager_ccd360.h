// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSAudioManager: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionccd360: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Scopeccd360, allocationTagccd360: GUESS(low); audio allocation context
extern __declspec(thread) unsigned allocationTagccd360;
struct Scopeccd360 { unsigned saved; Scopeccd360(unsigned value):saved(allocationTagccd360) { allocationTagccd360=value; } ~Scopeccd360() { allocationTagccd360=saved; } };

class BSAudioManager
{
public:
    std::uint8_t unknown00[376];
    bool (*resolve)(unsigned, void**);
    void Apply(void*, unsigned);

    void Functionccd360(unsigned identity, unsigned flags);
};
