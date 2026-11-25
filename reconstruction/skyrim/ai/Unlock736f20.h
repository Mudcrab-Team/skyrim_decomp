// Source exposure: binary-analysis
// Unlock736f20: GUESS(low) STANDIN; original owner is unknown
// Function736f20: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
extern void ReadField(void*, void*, std::uint32_t, std::uint32_t);
extern const float upperBound, lowerBound;
extern float timeDelta;

class Unlock736f20 {
public:
    float start, duration;
    void Function736f20(void* buffer);
};
