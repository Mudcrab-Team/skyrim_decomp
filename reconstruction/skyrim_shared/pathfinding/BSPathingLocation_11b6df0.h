// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSPathingLocation: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function11b6df0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Path11b6df0, Fallback11b6df0: GUESS(low) STANDIN; path output and alternate builder
struct Path11b6df0 { std::uint64_t unknown00; void* storage; std::uint64_t unknown10; unsigned count; void Build(void**); };
struct Fallback11b6df0 { void Build(Path11b6df0*); };

class BSPathingLocation
{
public:
    std::uint8_t unknown00[0x10];
    void* location;
    Fallback11b6df0* fallback;

    bool Function11b6df0(Path11b6df0* output);
};
