// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// AIProcess: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function6f1280: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// High6f1280: GUESS(low) STANDIN; high-process storage
struct High6f1280 { std::uint8_t unknown00[0x455]; std::uint8_t unknown455; std::uint8_t unknown456; };

class AIProcess
{
public:
    std::uint64_t unknown00;
    std::uint64_t unknown08;
    High6f1280* high;

    void Function6f1280(std::uint8_t value);
};
