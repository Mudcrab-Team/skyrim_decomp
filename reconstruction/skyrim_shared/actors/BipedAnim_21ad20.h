// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BipedAnim: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function21ad20: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Form21ad20, Value21ad20, State21ad20, disable21ad20: GUESS(low) STANDIN; selected biped form
struct Value21ad20 { std::uint64_t unknown00; };
struct Form21ad20 { std::uint8_t unknown00[0x1a]; unsigned char type; std::uint8_t unknown1b[0x25]; Value21ad20 value; };
struct State21ad20 { Form21ad20* form; std::uint64_t unknown08; Value21ad20* value; };
extern bool disable21ad20;

class BipedAnim
{
public:
    std::uint8_t unknown00[0x1348];
    State21ad20 state;
    void Apply(State21ad20*, bool, unsigned);

    void Function21ad20(Form21ad20* form);
};
