// Source exposure: binary-analysis
// Unlock104fcc0: GUESS(low) STANDIN; original owner is unknown
// Function104fcc0: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
#include "WorldLockStorage.h"

class Unlock104fcc0 {
public:
    std::uint64_t unk00[6323];
    WorldLockStorage worldLock;
    void Function104fcc0();
};
