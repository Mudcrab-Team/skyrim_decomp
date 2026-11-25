// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BGSSaveLoadGame: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function616e00: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Form616e00, SaveTable616e00: GUESS(low) STANDIN; save identity table
struct Form616e00 { std::uint8_t unknown00[0x14]; unsigned formID; };
struct SaveTable616e00 { void Find(void*, unsigned); };

class BGSSaveLoadGame
{
public:
    std::uint8_t unknown00[0x330];
    SaveTable616e00* table;

    void* Function616e00(void* output, const Form616e00* form);
};
