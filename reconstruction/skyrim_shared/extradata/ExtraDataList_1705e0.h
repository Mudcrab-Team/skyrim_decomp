// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function1705e0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Payload1705e0: GUESS(low) STANDIN; lazily created extra-data value
struct Payload1705e0 { std::uint8_t unknown00[28]; unsigned value; };

class ExtraDataList
{
public:
    void* GetByType(unsigned);
    Payload1705e0* Create(void*);

    unsigned* Function1705e0(void* owner);
};
