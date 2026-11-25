// Source exposure: binary-analysis
// Unlock17bca0: GUESS(low) STANDIN; original owner is unknown
// Function17bca0: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
#include <intrin.h>
class Ref17bca0 {
public:
    virtual ~Ref17bca0();
    virtual void DeleteThis();
// volatile: lock and reference words are shared with other threads.
    volatile long refCount;
    void Release() {
        // Handle reference counts are shared across threads.
        long count = _InterlockedExchangeAdd(&refCount, -1) - 1;
        if (!(count & 0x3ff)) DeleteThis();
    }
};
struct Object17bca0 { std::uint64_t unk00, unk08, unk10, unk18; Ref17bca0 handle;
    void Release() { handle.Release(); }
};

class Unlock17bca0 {
public:
    Object17bca0* pointer;
    ~Unlock17bca0();
};
