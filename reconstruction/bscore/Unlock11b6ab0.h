// Source exposure: binary-analysis
// Unlock11b6ab0: GUESS(low) STANDIN; original owner is unknown
// Function11b6ab0: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
#include <intrin.h>
// volatile: reference count is updated by atomic lifetime operations.
class Ref11b6ab0 { public: virtual ~Ref11b6ab0(); volatile long refCount; };

class Unlock11b6ab0 {
public:
    std::uint64_t unk00, unk08, unk10, unk18;
    Ref11b6ab0* pointer;
    void Function11b6ab0();
};
