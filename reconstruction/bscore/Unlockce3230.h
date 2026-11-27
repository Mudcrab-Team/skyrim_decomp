// Source exposure: binary-analysis
// Unlockce3230: GUESS(low) STANDIN; original owner is unknown
#pragma once
#include <cstdint>
#include <cstddef>

class Unlockce3230 {
public:
// volatile: lock and reference words are shared with other threads.
    volatile std::uint32_t owner;
// volatile: lock and reference words are shared with other threads.
    volatile std::uint32_t count;
    Unlockce3230();
};
