// Source exposure: binary-analysis
// Unlock1270b0: GUESS(low) STANDIN; original owner is unknown
// Function1270b0: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
#include <intrin.h>
// volatile: lock and reference words are shared with other threads.
class Ref1270b0 { public: virtual ~Ref1270b0(); std::uint64_t unk08; volatile long refCount; };

class Unlock1270b0 {
public:
    Ref1270b0* pointer;
    void Function1270b0();
};
