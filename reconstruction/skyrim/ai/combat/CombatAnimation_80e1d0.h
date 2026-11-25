// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// CombatAnimation: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function80e1d0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Description80e1d0, Binding80e1d0, Object80e1d0: GUESS(low) STANDIN; cached animation binding
struct Description80e1d0 { std::uint8_t unknown00[0x38]; };
struct Binding80e1d0 { std::uint8_t unknown00[0x20]; bool Apply(void*,void*); };
struct Object80e1d0 { bool Find(Description80e1d0*,Binding80e1d0*); };

class CombatAnimation
{
public:
    std::uint64_t unknown00;
    Object80e1d0* object;
    std::uint8_t unknown10[0x18];
    Description80e1d0 description;
    Binding80e1d0 binding;
    unsigned state;

    bool Function80e1d0(void* first,void* second);
};
