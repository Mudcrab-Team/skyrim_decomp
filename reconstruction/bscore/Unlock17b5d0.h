// Source exposure: binary-analysis
// Unlock17b5d0: GUESS(low) STANDIN; original owner is unknown
// Function17b5d0: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
#include <intrin.h>
struct Lock17b5d0 { std::uint32_t owner; long count; };
extern "C" __declspec(dllimport) unsigned long GetCurrentThreadId();

class Unlock17b5d0 {
public:
    Lock17b5d0* lock;
    void Function17b5d0();
};
