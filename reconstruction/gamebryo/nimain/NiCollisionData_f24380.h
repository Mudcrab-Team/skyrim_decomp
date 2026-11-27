// Source exposure: mixed
// body: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); adapted body provenance only
// Code origin: adapted from the cited sibling body; local names remain provisional
// Adapted bodies: none
// NiCollisionData: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionf24380: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Nodef24380: GUESS(low) STANDIN; parent and collision-bearing node
struct Nodef24380 { std::uint8_t unknown00[0x30]; Nodef24380* parent; std::uint64_t unknown38; void* collisionData; };

class NiCollisionData
{
public:

    Nodef24380* Functionf24380(Nodef24380* node);
};
