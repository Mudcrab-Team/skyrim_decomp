// Source exposure: binary-analysis
// Unlock872ff0: GUESS(low) STANDIN; original owner is unknown
// Function872ff0: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
struct Node872ff0 { std::uint64_t unk00, unk08, unk10; Node872ff0** children; };

class Unlock872ff0 {
public:
    std::uint64_t unk00[39];
    Node872ff0* currentNode;
    std::uint64_t unk140;
    std::uint32_t status;
    std::uint32_t state;
    void Function872ff0(std::uint32_t index);
};
