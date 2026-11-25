// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function164a40: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Value164a40, Payload164a40: GUESS(low) STANDIN; extra-data value record
struct Value164a40 { unsigned first; unsigned char flag; unsigned second; };
struct Payload164a40 { std::uint8_t unknown00[0x10]; Value164a40 value; };

class ExtraDataList
{
public:
    void* GetByType(unsigned);

    void Function164a40(Value164a40* output);
};
