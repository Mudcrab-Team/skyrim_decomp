// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.
// BSTArrayResizeTrivial1, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
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

struct BSTArrayResizeTrivial1 {
    static bool Op17fd90(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op17fe10(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op17fe90(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op1800b0(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op190670(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op1ecc60(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op2a0c70(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op31b220(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op31d3d0(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op326c80(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op328950(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op38fc40(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op391230(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op39eb80(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op39ec00(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op3cd8e0(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op3cd960(BSTArrayScrap* self, std::uint32_t newSize);
    static bool Op3e0c40(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op41e680(BSTArrayScrap* self, std::uint32_t newSize);
    static bool Op441690(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op45d540(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op48d360(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op4c0c10(BSTArrayScrap* self, std::uint32_t newSize);
    static bool Op4c0c90(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op4c0ee0(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op4c8220(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op4e75d0(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op53df20(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op55c5d0(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op565270(BSTArrayHeap* self, std::uint32_t newSize);
};
