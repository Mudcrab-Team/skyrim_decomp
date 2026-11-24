// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.
// BSTArrayEraseOrdered4, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
#pragma once
#include <cstdint>

struct BSTArrayHeap {
    void* data;
    std::uint32_t capacity;
    alignas(8) std::uint32_t size;
};

struct BSTArrayScrap {
    void* allocator;
    void* data;
    std::uint32_t capacity;
    alignas(8) std::uint32_t size;
};

extern "C" void __cdecl ArrayMove_ce0980(std::uint32_t* sizePtr, void* data, std::uint32_t dstIdx, std::uint32_t srcIdx, std::uint32_t count, std::uint32_t elemSize);

struct BSTArrayEraseOrdered4 {
    static void Op1514470(BSTArrayScrap* self, std::uint32_t pos, std::uint32_t count);
    static void Op15144d0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op1569b30(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
};
