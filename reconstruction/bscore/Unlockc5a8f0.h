// Source exposure: binary-analysis
// Unlockc5a8f0: GUESS(low) STANDIN; original owner is unknown
#pragma once
#include <cstdint>
#include <cstddef>
struct Refc5a8f0 { std::uint64_t unk00; std::uint16_t unk08; std::uint16_t references; std::uint32_t owners; };

class Unlockc5a8f0 {
public:
    Refc5a8f0* pointer;
    Unlockc5a8f0(Refc5a8f0* value);
};
