// Source exposure: binary-analysis
// Unlock1489c0: GUESS(low) STANDIN; original owner is unknown
// Function1489c0: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
struct BaseEffect1489c0 {
    std::uint64_t unk00[13];
    std::uint32_t flags;
};

class Unlock1489c0 {
public:
    std::uint64_t unk00, unk08;
    BaseEffect1489c0* baseEffect;
    bool Function1489c0();
};
