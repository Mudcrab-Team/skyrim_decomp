// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function164740: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Payload164740: GUESS(low) STANDIN; optional extra-data flag
struct Payload164740 { std::uint8_t unknown00[0x10]; std::uint8_t value; };

class ExtraDataList
{
public:
    void* GetByType(unsigned);

    bool Function164740(bool* output);
};
