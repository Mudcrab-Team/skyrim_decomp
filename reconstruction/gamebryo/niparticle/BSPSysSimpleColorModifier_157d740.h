// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSPSysSimpleColorModifier: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// BSPSysSimpleColorModifier: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Base157d740: GUESS(low) STANDIN; base subobject with unobserved members
class Base157d740
{
public:
    Base157d740();
    virtual ~Base157d740();
    std::uint8_t unknown08[40];
};

class BSPSysSimpleColorModifier : public Base157d740
{
public:
    std::uint64_t unknown30;
    std::uint64_t unknown38;
    std::uint64_t unknown40;
    std::uint64_t unknown48;
    std::uint64_t unknown50;
    std::uint64_t unknown58;
    std::uint8_t unknown60[0x18];
    std::uint8_t unknown78;

     BSPSysSimpleColorModifier();
};
