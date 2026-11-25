// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// AIProcess: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function6f2230: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// High6f2230: GUESS(low) STANDIN; high-process storage
struct High6f2230 { std::uint8_t unknown00[0x28]; void* unknown28; };

class AIProcess
{
public:
    std::uint64_t unknown00;
    std::uint64_t unknown08;
    High6f2230* high;

    void Function6f2230(void* value);
};
