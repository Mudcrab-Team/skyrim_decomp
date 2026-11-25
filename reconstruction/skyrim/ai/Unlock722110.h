// Source exposure: binary-analysis
// Unlock722110: GUESS(low) STANDIN; original owner is unknown
// Function722110: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
struct Middle722110 {
    std::uint64_t unk00[74];
    void* controller;
};

class Unlock722110 {
public:
    std::uint64_t unk00;
    Middle722110* middleHigh;
    void* Function722110();
};
