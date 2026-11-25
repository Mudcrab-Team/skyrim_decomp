// Source exposure: binary-analysis
// Unlock1135e30: GUESS(low) STANDIN; original owner is unknown
// Function1135e30: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
struct Element1135e30 {
    std::uint64_t unk00;
    std::uint64_t unk08;
    std::uint64_t unk10;
    std::uint64_t unk18;
};

class Unlock1135e30 {
public:
    Element1135e30* data;
    Element1135e30* Function1135e30(std::uint16_t index);
};
