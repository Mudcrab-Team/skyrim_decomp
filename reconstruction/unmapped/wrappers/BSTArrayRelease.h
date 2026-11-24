// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.
// BSTArrayRelease, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
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

extern "C" void __cdecl ArrayDealloc_ce0ed0(BSTArrayHeap* self);
extern "C" void __cdecl ArrayDealloc_ce11f0(BSTArrayScrap* self);

struct BSTArrayRelease {
    static void Op111b60(BSTArrayHeap* self);
    static void Op11a4e0(BSTArrayHeap* self);
    static void Op11aed0(BSTArrayHeap* self);
    static void Op11af70(BSTArrayScrap* self);
    static void Op12c2f0(BSTArrayHeap* self);
    static void Op136120(BSTArrayHeap* self);
    static void Op733fc0(BSTArrayHeap* self);
};
