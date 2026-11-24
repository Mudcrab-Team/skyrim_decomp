// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.
// BSTArrayEraseUnordered2, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
#pragma once
#include <cstdint>

struct BSTArrayHeap {
    void* data;
    std::uint32_t capacity;
    alignas(8) std::uint32_t size;
};

extern "C" void __cdecl ArrayMove_ce0980(std::uint32_t* sizePtr, void* data, std::uint32_t dstIdx, std::uint32_t srcIdx, std::uint32_t count, std::uint32_t elemSize);

struct BSTArrayEraseUnordered2 {
    static void Op6640d0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op664130(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op6c25e0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op6c2640(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op6c26a0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op6c2700(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op6c2760(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op6c27c0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op6c2820(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op6c2880(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op6c28e0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op6c2940(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op6c78f0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op6d1d70(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op6d1dd0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op6d1e30(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op6dbac0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op6dbb20(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op736ba0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op73bce0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op73bd40(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op772320(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op772380(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op7723e0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op772440(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op7724a0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op772500(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op772560(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op7725c0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op772620(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
};
