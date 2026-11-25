// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESFaction: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function3b49f0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Name3b49f0, Entry3b49f0, Node3b49f0, Scope3b49f0, allocationTag3b49f0: GUESS(low) STANDIN; tagged rank naming
struct Name3b49f0 { void Assign(const char*); };
struct Entry3b49f0 { std::uint8_t unknown00[0x18]; Name3b49f0 name; };
struct Node3b49f0 { Entry3b49f0* value; Node3b49f0* next; };
extern __declspec(thread) unsigned allocationTag3b49f0;
struct Scope3b49f0 { unsigned saved; Scope3b49f0(unsigned value):saved(allocationTag3b49f0) { allocationTag3b49f0=value; } ~Scope3b49f0() { allocationTag3b49f0=saved; } };

class TESFaction
{
public:
    std::uint8_t unknown00[0xe0];
    Node3b49f0 head;

    void Function3b49f0(unsigned index, const char* name);
};
