// Source exposure: binary-analysis
// Unlock9e21c0: GUESS(low) STANDIN; original owner is unknown
// Function9e21c0: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
struct Profiler9e21c0 { std::uint64_t unk00; };
extern bool profiling;

class Unlock9e21c0 {
public:
    std::uint64_t unk00[180];
    Profiler9e21c0 profiler;
    void* Function9e21c0();
};
