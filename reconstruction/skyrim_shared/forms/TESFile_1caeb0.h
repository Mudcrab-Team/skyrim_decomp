// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESFile: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function1caeb0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Scope1caeb0, allocationTag1caeb0, Copy1caeb0, Append1caeb0, Check1caeb0: GUESS(low); tagged file-path check
extern __declspec(thread) unsigned allocationTag1caeb0;
struct Scope1caeb0 { unsigned saved; Scope1caeb0(unsigned value):saved(allocationTag1caeb0) { allocationTag1caeb0=value; } ~Scope1caeb0() { allocationTag1caeb0=saved; } };
extern "C" __declspec(dllimport) int Copy1caeb0(char*, std::size_t, const char*);
extern "C" __declspec(dllimport) int Append1caeb0(char*, std::size_t, const char*);
int Check1caeb0(const char*);

class TESFile
{
public:
    std::uint8_t unknown00[0x58];
    char filename[260];
    char directory[260];
    void Prepare(unsigned);

    bool Function1caeb0();
};
