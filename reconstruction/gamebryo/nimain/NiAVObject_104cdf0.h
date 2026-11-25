// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// NiAVObject: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function104cdf0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// State104cdf0, Command104cdf0, commandKey104cdf0: GUESS(low) STANDIN; Havok property command
struct State104cdf0 { std::uint8_t unknown00[0x18]; unsigned char flags; };
struct Command104cdf0 { void* value; bool enabled; unsigned kind; std::uint8_t unknown10[0x20]; };
extern void* commandKey104cdf0;

class NiAVObject
{
public:
    State104cdf0* GetState();
    void Apply(Command104cdf0*, void*);

    bool Function104cdf0(bool enabled, bool force);
};
