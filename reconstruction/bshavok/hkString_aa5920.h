// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// hkString: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionaa5920: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// CompareBounded: GUESS(low); imported bounded string comparison
extern "C" __declspec(dllimport) int CompareBounded(const char*, const char*, std::size_t);

class hkString
{
public:

    static int Functionaa5920(const char* left, const char* right, unsigned count);
};
