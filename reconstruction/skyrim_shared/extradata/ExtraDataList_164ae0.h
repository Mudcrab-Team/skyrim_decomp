// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function164ae0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Value164ae0, Payload164ae0: GUESS(low) STANDIN; extra-data value record
struct Value164ae0 { unsigned first; unsigned char flag; unsigned second; };
struct Payload164ae0 { std::uint8_t unknown00[0x10]; Value164ae0 value; };

class ExtraDataList
{
public:
    void* GetByType(unsigned);

    void Function164ae0(Value164ae0* output);
};
