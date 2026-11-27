// Source exposure: binary-analysis
// Unlock104fce0: GUESS(low) STANDIN; original owner is unknown
// Function104fce0: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
#include "WorldLockStorage.h"

class Unlock104fce0 {
public:
    std::uint64_t unk00[6323];
    WorldLockStorage worldLock;
    void Function104fce0();
};
