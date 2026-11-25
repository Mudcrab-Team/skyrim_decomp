// Source exposure: binary-analysis
// Unlock5fc090: GUESS(low) STANDIN; original owner is unknown
// Function5fc090: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
class Callable5fc090 { public: virtual void Slot0(); virtual void Slot1(); virtual void Slot2(); virtual void Slot3(); virtual void Destroy(bool); };

class Unlock5fc090 {
public:
    std::uint64_t unk00;
    std::uint64_t unk08;
    std::uint64_t unk10;
    std::uint64_t unk18;
    std::uint64_t unk20;
    std::uint64_t unk28;
    std::uint64_t unk30;
    Callable5fc090* callable;
    void Function5fc090();
};
