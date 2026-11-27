// Source exposure: binary-analysis
// Unlockce48c0: GUESS(low) STANDIN; original owner is unknown
// Functionce48c0: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
#include <intrin.h>
// volatile: lock and reference words are shared with other threads.
struct Refce48c0 { std::uint64_t unk00; volatile long references; };

class Unlockce48c0 {
public:
    Refce48c0* pointer;
    void Functionce48c0();
};
