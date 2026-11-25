// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSPathingRequest: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function11cbe20: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>
#include <intrin.h>

// Ref11cbe20: GUESS(low) STANDIN; intrusive reference-counted pathing object
struct Ref11cbe20 { virtual ~Ref11cbe20(); long references; };

class BSPathingRequest
{
public:
    std::uint8_t unknown00[0xc8];
    Ref11cbe20* reference;
    unsigned flags;

    void Function11cbe20(Ref11cbe20* const& value);
};
