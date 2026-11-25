// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// hkFreeList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionabc410: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Blockabc410: GUESS(low) STANDIN; allocator block chain
struct Blockabc410 { Blockabc410* next; std::uint64_t unknown08; char* data; std::size_t count; };

class hkFreeList
{
public:
    std::uint64_t unknown00;
    std::size_t elementSize;

    void Functionabc410(Blockabc410* block, void (*callback)(void*, std::size_t, int, int, void*), int mode, void* context);
};
