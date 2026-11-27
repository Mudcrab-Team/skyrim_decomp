// Source exposure: mixed
// names: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); stream helper body adapted
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nimain/nipoint3_stream.h:1
// Unlockedc070: GUESS(low) STANDIN; original owner is unknown
// Functionedc070: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
struct Streamedc070 {
    void* unk00; std::uint32_t position; std::uint32_t unk0c;
    void* unk10;
    std::uint32_t (*transfer)(Streamedc070*, void*, std::uint32_t, std::uint32_t*, std::uint32_t);
    void Write(void* data) { std::uint32_t size = 4; position += transfer(this, data, 4, &size, 1); }
};
struct Contextedc070 {
    std::uint64_t unk00[84];
    Streamedc070* stream;
};

class Unlockedc070 {
public:
    float x,y,z;
    void Functionedc070(Contextedc070* context);
};
