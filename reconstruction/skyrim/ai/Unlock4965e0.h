// Source exposure: binary-analysis
// Unlock4965e0: GUESS(low) STANDIN; original owner is unknown
// Function4965e0: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
struct Target4965e0 {
    std::uint64_t unk00;
    std::uint64_t unk08;
    std::uint64_t unk10;
    std::uint64_t unk18;
    bool flag;
};

class Unlock4965e0 {
public:
    Target4965e0* target;
    std::uint64_t unk08;
    bool found, visited, notify;
    void Function4965e0();
};
