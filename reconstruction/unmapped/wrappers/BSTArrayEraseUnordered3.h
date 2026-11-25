// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.
// BSTArrayEraseUnordered3, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
#pragma once
#include <cstdint>

struct BSTArrayHeap {
    void* data;
    std::uint32_t capacity;
    alignas(8) std::uint32_t size;
};

extern "C" void __cdecl ArrayMove_ce0980(std::uint32_t* sizePtr, void* data, std::uint32_t dstIdx, std::uint32_t srcIdx, std::uint32_t count, std::uint32_t elemSize);

struct BSTArrayEraseUnordered3 {
    static void Op772680(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op7726e0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op772740(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op7727a0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op772800(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op772860(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op7728c0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op772920(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op78c360(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op7b4c50(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op7b4cb0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op7c3840(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op805730(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op905c10(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op915b60(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op915bc0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op924ec0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op93ce10(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op946da0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op950e10(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op974660(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op975db0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9869d0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9c3010(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9cc850(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9cc8b0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f6470(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f64d0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f6530(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f6590(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
};
