// Source exposure: binary-analysis
// Unlock4a3370: GUESS(low) STANDIN; original owner is unknown
#pragma once
#include <cstdint>
#include <cstddef>

class Unlock4a3370 {
public:
    virtual ~Unlock4a3370();
    std::uint8_t kind; std::uint8_t unk09; std::uint16_t unk0a;
    std::uint32_t index;
    void* data;
    Unlock4a3370();
};
