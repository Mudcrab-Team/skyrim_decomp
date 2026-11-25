// Source exposure: binary-analysis
// Unlock15e7980: GUESS(low) STANDIN; original owner is unknown
// Function15e7980: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
#include <vector>

class Unlock15e7980 {
public:
    virtual ~Unlock15e7980();
    std::uint64_t unk00;
    std::uint64_t unk08;
    std::uint64_t unk10;
    std::uint64_t unk18;
    std::uint64_t unk20;
    std::uint64_t unk28;
    std::vector<Unlock15e7980*> children;
};
