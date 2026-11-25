// Source exposure: binary-analysis
// Unlock148900: GUESS(low) STANDIN; original owner is unknown
// Function148900: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
struct BaseEffect148900 {
    std::uint64_t unk00[13];
    std::uint32_t flags;
};
inline bool TestFlag(std::uint32_t bits, std::uint32_t index) { return ((bits >> index) & 1) != 0; }

class Unlock148900 {
public:
    std::uint32_t magnitude, area, duration, unk0c;
    BaseEffect148900* baseEffect;
    std::uint32_t Function148900();
};
