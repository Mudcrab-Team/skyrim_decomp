// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// AIProcess: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function6f21f0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// High6f21f0, defaultValue6f21f0: GUESS(low) STANDIN; high-process state and default
struct High6f21f0 { std::uint8_t unknown00[0x36c]; int value; };
extern int defaultValue6f21f0;

class AIProcess
{
public:
    std::uint64_t unknown00;
    std::uint64_t unknown08;
    High6f21f0* high;

    void Function6f21f0();
};
