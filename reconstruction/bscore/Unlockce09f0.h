// Source exposure: binary-analysis
// Unlockce09f0: GUESS(low) STANDIN; original owner is unknown
// Functionce09f0: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
class Allocatorce09f0 { public: virtual bool Allocate(std::uint32_t, std::uint32_t); };

class Unlockce09f0 {
public:
    static bool Functionce09f0(void*, Allocatorce09f0* allocator, std::uint32_t count, std::uint32_t stride);
};
