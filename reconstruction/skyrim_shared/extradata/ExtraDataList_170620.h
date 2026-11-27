// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function170620: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Payload170620: GUESS(low) STANDIN; lazily created extra-data value
struct Payload170620 { std::uint8_t unknown00[16]; void* value; };

class ExtraDataList
{
public:
    void* GetByType(unsigned);
    Payload170620* Create(void*);

    void** Function170620(void* owner);
};
