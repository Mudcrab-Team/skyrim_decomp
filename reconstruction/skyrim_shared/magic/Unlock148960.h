// Source exposure: binary-analysis
// Unlock148960: GUESS(low) STANDIN; original owner is unknown
// Function148960: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
struct BaseEffect148960 {
    std::uint64_t unk00[13];
    std::uint32_t flags;
};
inline bool TestFlag(std::uint32_t bits, std::uint32_t index) { return ((bits >> index) & 1) != 0; }

class Unlock148960 {
public:
    std::uint32_t magnitude, area, duration, unk0c;
    BaseEffect148960* baseEffect;
    std::uint32_t Function148960();
};
