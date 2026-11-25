// Source exposure: binary-analysis
// Unlock20d100: GUESS(low) STANDIN; original owner is unknown
// Function20d100: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
extern "C" __declspec(dllimport) int ComparePrefix(const char*, const char*, std::size_t);
extern const char prefix[];

class Unlock20d100 {
public:
    const char* value;
    const char* Function20d100();
};
