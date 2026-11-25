// Source exposure: binary-analysis
// Unlock120690: GUESS(low) STANDIN; original owner is unknown
#pragma once
#include <cstdint>
#include <cstddef>
#include <intrin.h>
#include "HeapReleaseInterface.h"

// volatile: shared references are changed through atomic operations.
struct Data120690 { std::uint64_t unk00; volatile long references; };

class Unlock120690 { public: ~Unlock120690();
    std::uintptr_t tagged;
};
