// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function172f20: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Payload172f20: GUESS(low) STANDIN; searchable extra-data payload
struct Payload172f20 { int Find(void*); };

class ExtraDataList
{
public:
    void* GetByType(unsigned);

    int Function172f20(void* value);
};
