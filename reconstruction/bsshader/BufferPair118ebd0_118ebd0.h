// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BufferPair118ebd0: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function118ebd0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Allocator118ebd0, Resource118ebd0: GUESS(low) STANDIN; buffer resource release
struct Resource118ebd0 { virtual void Unk00(); virtual void Unk01(); virtual void Release(); };
struct Allocator118ebd0 { void Release(Resource118ebd0*); };

class BufferPair118ebd0
{
public:
    std::uint8_t unknown00[0x38];
    void* active;
    std::uint64_t unknown40;
    Allocator118ebd0* allocator;
    Resource118ebd0* first;
    Resource118ebd0* second;

    void Function118ebd0();
};
