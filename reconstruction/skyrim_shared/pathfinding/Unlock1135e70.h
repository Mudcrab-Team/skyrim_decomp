// Source exposure: binary-analysis
// Unlock1135e70: GUESS(low) STANDIN; original owner is unknown
// Function1135e70: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
struct Element1135e70 {
    std::uint64_t unk00;
    std::uint64_t unk08;
    std::uint64_t unk10;
    std::uint64_t unk18;
    std::uint64_t unk20;
    std::uint64_t unk28;
};

class Unlock1135e70 {
public:
    Element1135e70* data;
    Element1135e70* Function1135e70(std::uint16_t index);
};
