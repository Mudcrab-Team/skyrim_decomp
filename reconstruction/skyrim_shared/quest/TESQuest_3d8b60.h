// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESQuest: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function3d8b60: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Condition3d8b60, Link3d8b60: GUESS(low) STANDIN; quest condition chain
struct Condition3d8b60 { bool Check(); };
struct Link3d8b60 { Condition3d8b60* value; Link3d8b60* next; };

class TESQuest
{
public:
    std::uint8_t unknown00[0xe8];
    Link3d8b60 conditions;

    bool Function3d8b60();
};
