// Source exposure: binary-analysis
// Unlock5f2120: GUESS(low) STANDIN; original owner is unknown
// Function5f2120: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
extern "C" __declspec(dllimport) void LeaveCriticalSection(void*);

class Unlock5f2120 {
public:
    void* section;
    void Function5f2120();
};
