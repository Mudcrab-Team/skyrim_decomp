// Source exposure: binary-analysis
// Unlock1082fb0: GUESS(low) STANDIN; original owner is unknown
// Function1082fb0: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
struct Shape1082fb0 {
    std::uint64_t unk00;
    std::uint64_t unk08;
    std::uint32_t value;
};

class Unlock1082fb0 {
public:
    std::uint64_t unk00;
    std::uint64_t unk08;
    Shape1082fb0* shape;
    void Function1082fb0(std::uint32_t* out);
};
