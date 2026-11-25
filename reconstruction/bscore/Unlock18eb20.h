// Source exposure: binary-analysis
// Unlock18eb20: GUESS(low) STANDIN; original owner is unknown
// Function18eb20: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
#include <intrin.h>
class Ref18eb20 {
public:
    virtual ~Ref18eb20();
    virtual void DeleteThis();
// volatile: lock and reference words are shared with other threads.
    volatile long refCount;
    void Release() {
        // Handle reference counts are shared across threads.
        long count = _InterlockedExchangeAdd(&refCount, -1) - 1;
        if (!(count & 0x3ff)) DeleteThis();
    }
};
struct Object18eb20 { std::uint64_t unk00, unk08, unk10, unk18; Ref18eb20 handle;
    void Release() { handle.Release(); }
};

class Unlock18eb20 {
public:
    Object18eb20* pointer;
    ~Unlock18eb20();
};
