// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BipedAnim: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function21aff0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// BipedState21aff0, disable21aff0: GUESS(low) STANDIN; biped state and mode switch
struct BipedState21aff0 { std::uint64_t unknown00; };
extern bool disable21aff0;

class BipedAnim
{
public:
    std::uint8_t unknown00[0x1348];
    BipedState21aff0 state;
    void Apply(BipedState21aff0*, bool, unsigned);

    void Function21aff0();
};
