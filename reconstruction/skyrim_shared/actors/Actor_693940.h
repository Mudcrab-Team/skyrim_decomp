// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// Actor: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function693940: GUESS(low); provisional member name
// Recipe: reconstruction/recipes/o2-fpfast.json
#pragma once
#include <cstdint>
#include <cstddef>

// Manager693940, manager693940: GUESS(low) STANDIN; loading-state query
struct Manager693940 { bool Busy(); };
extern Manager693940* manager693940;

class Actor
{
public:
    std::uint8_t unknown00[0xc8];
    unsigned flags;
    std::uint8_t unknowncc[0x138];
    unsigned state;
    void SetState(bool);
    void SetMode(unsigned);
    float ReadValue(unsigned, unsigned);
    void SetValue(unsigned, float);

    void Function693940(bool enabled);
};
