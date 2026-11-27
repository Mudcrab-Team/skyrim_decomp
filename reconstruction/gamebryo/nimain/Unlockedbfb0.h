// Source exposure: mixed
// names: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); stream helper body adapted
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nimain/nipoint3_stream.h:1
// Unlockedbfb0: GUESS(low) STANDIN; original owner is unknown
// Functionedbfb0: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
struct Streamedbfb0 {
    void* unk00; std::uint32_t position; std::uint32_t unk0c;
    std::uint32_t (*transfer)(Streamedbfb0*, void*, std::uint32_t, std::uint32_t*, std::uint32_t);
    void Read(void* data) { std::uint32_t size = 4; position += transfer(this, data, 4, &size, 1); }
};
struct Contextedbfb0 {
    std::uint64_t unk00[83];
    Streamedbfb0* stream;
};

class Unlockedbfb0 {
public:
    float x,y,z;
    void Functionedbfb0(Contextedbfb0* context);
};
