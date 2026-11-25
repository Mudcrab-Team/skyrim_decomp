// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSAudioManager: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionccd2c0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Scopeccd2c0, allocationTagccd2c0: GUESS(low); audio allocation context
extern __declspec(thread) unsigned allocationTagccd2c0;
struct Scopeccd2c0 { unsigned saved; Scopeccd2c0(unsigned value):saved(allocationTagccd2c0) { allocationTagccd2c0=value; } ~Scopeccd2c0() { allocationTagccd2c0=saved; } };

class BSAudioManager
{
public:
    std::uint8_t unknown00[384];
    bool (*resolve)(const char*, void**);
    void Apply(void*, unsigned);

    void Functionccd2c0(const char* identity, unsigned flags);
};
