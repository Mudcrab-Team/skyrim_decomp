// Source exposure: binary-analysis
// Unlock561300: GUESS(low) STANDIN; original owner is unknown
// Function561300: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
struct Entry561300 { std::uint32_t unk00; std::uint8_t value; };

class Unlock561300 {
public:
    std::uint64_t unk00;
    Entry561300* entry;
    std::uint8_t Function561300();
};
