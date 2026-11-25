// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// NiAVObject: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function104cc30: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// State104cc30, Command104cc30, commandKey104cc30: GUESS(low) STANDIN; Havok property command
struct State104cc30 { std::uint8_t unknown00[0x18]; unsigned char flags; };
struct Command104cc30 { void* value; bool enabled; unsigned kind; std::uint8_t unknown10[0x20]; };
extern void* commandKey104cc30;

class NiAVObject
{
public:
    State104cc30* GetState();
    void Apply(Command104cc30*, void*);

    bool Function104cc30(bool enabled, bool force);
};
