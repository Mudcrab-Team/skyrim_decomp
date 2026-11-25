// Source exposure: binary-analysis
// Unlockfc27b0: GUESS(low) STANDIN; original owner is unknown
// Functionfc27b0: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
struct CriticalSectionfc27b0 { std::uint64_t values[5]; };
extern "C" __declspec(dllimport) void EnterCriticalSection(void*);

class Unlockfc27b0 {
public:
    std::uint64_t unk00[10];
    CriticalSectionfc27b0* section;
    void Functionfc27b0();
};
