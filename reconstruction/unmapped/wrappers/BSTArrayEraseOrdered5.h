// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.
// BSTArrayEraseOrdered5, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
#pragma once
#include <cstdint>

struct BSTArrayHeap {
    void* data;
    std::uint32_t capacity;
    alignas(8) std::uint32_t size;
};

extern "C" void __cdecl ArrayMove_ce0980(std::uint32_t* sizePtr, void* data, std::uint32_t dstIdx, std::uint32_t srcIdx, std::uint32_t count, std::uint32_t elemSize);

struct BSTArrayEraseOrdered5 {
    static void Op14c910(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op17f280(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op17f2e0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op190200(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op190260(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op1c8fa0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op1c9000(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op2539d0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op26ffe0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op29ded0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op29df30(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op2fbb80(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op309f30(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op3257d0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op328850(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op38fbe0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op398a90(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op3a41b0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op3a4210(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op3a4270(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op3aaa50(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op3aaab0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op3cd6e0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op3e0440(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op3e04a0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op3e0500(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op3e0560(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op3ec4f0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op3ec550(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op3ec5b0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
};
