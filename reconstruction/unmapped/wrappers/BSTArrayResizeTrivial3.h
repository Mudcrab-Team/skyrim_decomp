// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.
// BSTArrayResizeTrivial3, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
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

struct BSTArrayResizeTrivial3 {
    static bool Op11eb340(BSTArrayScrap* self, std::uint32_t newSize);
    static bool Op11ef780(BSTArrayScrap* self, std::uint32_t newSize);
    static bool Op11ef800(BSTArrayScrap* self, std::uint32_t newSize);
    static bool Op11f24e0(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op11f2560(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op1202ad0(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op1202b50(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op12508f0(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op125c1b0(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op12732e0(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op1273360(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op14e9e90(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op1514770(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op1593bf0(BSTArrayScrap* self, std::uint32_t newSize);
};
