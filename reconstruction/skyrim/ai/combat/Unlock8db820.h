// Source exposure: binary-analysis
// Unlock8db820: GUESS(low) STANDIN; original owner is unknown
// Function8db820: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
struct Value8db820 {
    std::uint64_t unk00[16];
    std::uint8_t unk80;
    std::uint8_t unk81;
    std::uint8_t flags82; std::uint8_t unk83;
    std::uint32_t unk84[32];
    std::uint8_t flags104;
};
class Context8db820 { public: virtual void Slot0(); virtual void Slot1(); virtual void Slot2(); virtual void Slot3(); virtual void Slot4(); virtual Value8db820* Get(); };

class Unlock8db820 {
public:
    static void Function8db820(void*, Context8db820* context);
};
