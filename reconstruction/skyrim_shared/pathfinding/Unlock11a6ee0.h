// Source exposure: binary-analysis
// Unlock11a6ee0: GUESS(low) STANDIN; original owner is unknown
// Function11a6ee0: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
struct Context11a6ee0 {
    std::uint64_t unk00[134];
    void (*release)(Context11a6ee0*, void*);
};
extern void DefaultRelease(void*);

class Unlock11a6ee0 {
public:
    static void Function11a6ee0(Context11a6ee0* context, void* memory);
};
