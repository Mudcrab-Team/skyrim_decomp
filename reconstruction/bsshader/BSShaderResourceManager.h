// Source exposure: mixed (published inventory and listings from the pinned image).
// 0x1582890 compared function
// 0x1582760 compared function
// 0x1582730 compared function
// Code origin: original stand-in declarations. The method signatures are inferred.
// BSShaderResourceManager, Function1582070, Function1582100, Function1582120: GUESS(low)
// Function1582140, Function1582160, Function1582180, Function15821a0: GUESS(low)
// Function1582250, Function1582270, Function1582290, Function1582550: GUESS(low)
// Function1582600, Function1582620, Function1582640, Function1582660: GUESS(low)
// Function15826f0, Function1582710, Function15827a0, Function1582870: GUESS(low)
// Function15829a0, Function15829c0: GUESS(low)
// Function15828b0, Function15828c0: GUESS(low)
#pragma once

#include <cstdint>

struct LookupSource;

class BSShaderResourceManager
{
public:
    std::uint32_t Function15828b0();
    float Function15828c0();
    void Function1582070();
    void Function1582100();
    void Function1582120();
    void Function1582140();
    void Function1582160();
    void Function1582180();
    void Function15821a0();
    void Function1582250();
    void Function1582270();
    void Function1582290(void* a_resource, std::uint8_t a_value);
    void Function1582550();
    void Function1582600();
    void Function1582620();
    void Function1582640();
    void Function1582660();
    void Function15826f0();
    void Function1582710();
    void Function15827a0();
    void Function1582870();
    void Function15829a0();
    void Function15829c0();
    void Function1582730(LookupSource* a_source, unsigned* a_out1, unsigned* a_out2);
    void Function1582760(void* a_arg1, void* a_arg2, std::uint64_t a_arg3);
    void Function1582890(void* a1, void* a2, void* a3, void* a4);
};

// LookupSource, gLookupGlobal, and the forwarded calls: GUESS(low)
struct LookupSource { std::uint8_t pad00[0x48]; void* data48; };
extern std::uint8_t gLookupGlobal[];
void Function100d6f0(void* a0, void* a1, void* a2, unsigned a3, std::uint64_t a4, bool a5);
void Function100f230(void* a0, void* a1);
void Function1019c00(void* a0, void* a1, void* a2, void* a3);
