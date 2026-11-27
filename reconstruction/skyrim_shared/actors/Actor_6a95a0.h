// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// Actor: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function6a95a0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// State6a95a0, Change6a95a0, Controller6a95a0: GUESS(low) STANDIN; controller state transition
struct State6a95a0 { std::uint8_t unknown00[0x40]; bool Check() const; };
struct Change6a95a0 { std::uint8_t unknown00[0x18]; State6a95a0 first; State6a95a0 second; };
struct Controller6a95a0 { void Update(bool); };

class Actor
{
public:
    std::uint8_t unknown00[0x150];
    Controller6a95a0* controller;

    int Function6a95a0(const Change6a95a0* change);
};
