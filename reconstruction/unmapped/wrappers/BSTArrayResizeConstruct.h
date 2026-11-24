// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.
// BSTArrayResizeConstruct, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
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

extern "C" bool __cdecl ArrayAlloc_ce0cd0(BSTArrayHeap* self, std::uint32_t cap, std::uint32_t elemSize);
extern "C" bool __cdecl ArrayAlloc_ce1010(BSTArrayScrap* self, std::uint32_t cap, std::uint32_t elemSize);
extern "C" bool __cdecl ArrayRealloc_ce0d50(BSTArrayHeap* self, std::uint32_t newCap, std::uint32_t oldSize, std::uint32_t extra1, std::uint32_t extra2, std::uint32_t elemSize);
extern "C" bool __cdecl ArrayRealloc_ce10a0(BSTArrayScrap* self, std::uint32_t newCap, std::uint32_t oldSize, std::uint32_t extra1, std::uint32_t extra2, std::uint32_t elemSize);
extern "C" void __cdecl ArrayConstruct_5d0370(BSTArrayHeap* self, std::uint32_t start, std::uint32_t count);
extern "C" void __cdecl ArrayConstruct_76a760(BSTArrayHeap* self, std::uint32_t start, std::uint32_t count);
extern "C" void __cdecl ArrayConstruct_794bf0(BSTArrayHeap* self, std::uint32_t start, std::uint32_t count);
extern "C" void __cdecl ArrayConstruct_ff1660(BSTArrayHeap* self, std::uint32_t start, std::uint32_t count);
extern "C" void __cdecl ArrayConstruct_121fb70(BSTArrayScrap* self, std::uint32_t start, std::uint32_t count);
extern "C" void __cdecl ArrayConstruct_121fc10(BSTArrayHeap* self, std::uint32_t start, std::uint32_t count);

struct BSTArrayResizeConstruct {
    static bool Op5d06f0(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op773050(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op794c40(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Opff16d0(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op121fe40(BSTArrayScrap* self, std::uint32_t newSize);
    static bool Op121fed0(BSTArrayHeap* self, std::uint32_t newSize);
};
