// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.
// BSTArrayEraseUnordered1, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
#pragma once
#include <cstdint>

struct BSTArrayHeap {
    void* data;
    std::uint32_t capacity;
    alignas(8) std::uint32_t size;
};

extern "C" void __cdecl ArrayMove_ce0980(std::uint32_t* sizePtr, void* data, std::uint32_t dstIdx, std::uint32_t srcIdx, std::uint32_t count, std::uint32_t elemSize);

struct BSTArrayEraseUnordered1 {
    static void Op1b5660(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op1ef3d0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op242080(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op280e40(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op286090(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op286180(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op29df90(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op2d5fa0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op2fbca0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op31c2f0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op398af0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op39c5b0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op3cd7f0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op3e0920(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op3e0980(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op4857d0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op4b8bd0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op53de60(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op53dec0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op5b9980(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op5b99e0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op5eb900(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op5eb960(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op60b280(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op6303c0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op63e180(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op6450c0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op647330(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op64ce40(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op664070(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
};
