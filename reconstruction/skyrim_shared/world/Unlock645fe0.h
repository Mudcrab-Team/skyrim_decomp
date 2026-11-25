// Source exposure: binary-analysis
// Unlock645fe0: GUESS(low) STANDIN; original owner is unknown
// Function645fe0: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
struct Global645fe0 {
    std::uint64_t unk00;
    std::uint64_t unk08;
    std::uint64_t unk10;
    std::uint64_t unk18;
    std::uint64_t unk20;
    std::uint64_t unk28;
    std::uint8_t unk30;
    std::uint8_t unk31;
    std::uint8_t unk32;
    std::uint8_t unk33;
    float value;
};
extern const float missingHour;

class Unlock645fe0 {
public:
    std::uint64_t unk00;
    std::uint64_t unk08;
    std::uint64_t unk10;
    std::uint64_t unk18;
    Global645fe0* gameHour;
    float Function645fe0();
};
