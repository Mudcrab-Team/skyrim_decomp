// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function1658a0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Payload1658a0: GUESS(low) STANDIN; extra-data flags
struct Payload1658a0 { std::uint8_t unknown00[0x10]; unsigned char flags; };

class ExtraDataList
{
public:
    void* GetByType(unsigned);

    void Function1658a0(bool enabled);
};
