// Source exposure: binary-analysis
// Unlock104fd00: GUESS(low) STANDIN; original owner is unknown
// Function104fd00: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
#include "WorldLockStorage.h"

class Unlock104fd00 {
public:
    std::uint64_t unk00[6323];
    WorldLockStorage worldLock;
    void Function104fd00();
};
