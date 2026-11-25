// Source exposure: binary-analysis
// Unlock725300: GUESS(low) STANDIN; original owner is unknown
// Function725300: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
struct Middle725300 {
    std::uint64_t unk00[65];
    std::uint32_t value;
};
extern std::uint32_t defaultValue;

class Unlock725300 {
public:
    std::uint64_t unk00;
    Middle725300* middleHigh;
    std::uint32_t* Function725300(std::uint32_t* out);
};
