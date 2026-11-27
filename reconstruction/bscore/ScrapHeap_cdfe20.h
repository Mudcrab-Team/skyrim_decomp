// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ScrapHeap: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functioncdfe20: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Blockcdfe20, Releasecdfe20: GUESS(low) STANDIN; free-block page trimming
struct Blockcdfe20 { std::intptr_t size; Blockcdfe20* next; };
extern "C" __declspec(dllimport) int Releasecdfe20(void*,std::size_t,unsigned);

class ScrapHeap
{
public:
    std::uint8_t unknown00[0x40];
    Blockcdfe20* head;
    std::uintptr_t base;
    std::uint64_t unknown50;
    std::uintptr_t end;
    std::uint64_t unknown60;
    std::size_t minimum;
    std::uint64_t unknown70;
    unsigned flags;
    void Remove(Blockcdfe20*);
    void Insert(Blockcdfe20*);

    void Functioncdfe20();
};
