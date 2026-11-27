// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESDataHandler: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function1badf0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Data1badf0: GUESS(low) STANDIN; data-handler table
struct Data1badf0 { std::uint64_t unknown00; void** items; void Prepare(); };

class TESDataHandler
{
public:
    std::uint8_t unknown00[0xd08];
    Data1badf0 data;

    void* Function1badf0(unsigned index);
};
