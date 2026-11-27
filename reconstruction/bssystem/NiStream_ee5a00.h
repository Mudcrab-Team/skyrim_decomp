// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// NiStream: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionee5a00: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// CopyPath, NormalizePath: GUESS(low); bounded path-copy and normalization interfaces
extern "C" __declspec(dllimport) int CopyPath(char*, std::size_t, const char*, std::size_t);
extern "C" void NormalizePath(char*);

class NiStream
{
public:
    std::uint8_t unknown00[0x518];
    char path[260];

    void Functionee5a00(const char* text);
};
