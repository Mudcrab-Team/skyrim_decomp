// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSPathingLocation: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function11b6e50: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>
#include <intrin.h>

// Ref11b6e50, Location11b6e50: GUESS(low) STANDIN; resolved pathing reference
struct Ref11b6e50 { virtual ~Ref11b6e50(); long references; };
struct Location11b6e50 { void Resolve(Ref11b6e50**); };

class BSPathingLocation
{
public:
    std::uint8_t unknown00[0x10];
    Location11b6e50* location;

    bool Function11b6e50(Ref11b6e50** output);
};
