// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.
// BSTArrayFindEraseUnordered, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
#pragma once
#include <cstdint>

struct BSTArrayHeap {
    void* data;
    std::uint32_t capacity;
    alignas(8) std::uint32_t size;
};

extern "C" void __cdecl ArrayMove_ce0980(std::uint32_t* sizePtr, void* data, std::uint32_t dstIdx, std::uint32_t srcIdx, std::uint32_t count, std::uint32_t elemSize);

struct BSTArrayFindEraseUnordered {
    static bool Op17ac40(BSTArrayHeap* self, const std::uint64_t* key);
    static bool Op17ace0(BSTArrayHeap* self, const std::uint64_t* key);
    static bool Op32a930(BSTArrayHeap* self, const std::uint32_t* key);
    static bool Op32a9d0(BSTArrayHeap* self, const std::uint32_t* key);
    static bool Op4d1ea0(BSTArrayHeap* self, const std::uint64_t* key);
    static bool Op4d1f40(BSTArrayHeap* self, const std::uint64_t* key);
};
