// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.
// BSTArrayResizeTrivial2, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
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

struct BSTArrayResizeTrivial2 {
    static bool Op5652f0(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op71fad0(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op772b30(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op772bb0(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op772c30(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op772cb0(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op816e80(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op861af0(BSTArrayScrap* self, std::uint32_t newSize);
    static bool Op861b70(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op86f800(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op872a60(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op8e8950(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op9427b0(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op98c860(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op9a59c0(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op9a5a40(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op9a5ac0(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Opa6c540(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Opbdc0e0(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Opbdc2f0(BSTArrayScrap* self, std::uint32_t newSize);
    static bool Opc43190(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Opf15200(BSTArrayScrap* self, std::uint32_t newSize);
    static bool Opff99b0(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Opffc560(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op1062350(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op109ea40(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op109ebd0(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op10c3560(BSTArrayHeap* self, std::uint32_t newSize);
    static bool Op11b8c70(BSTArrayScrap* self, std::uint32_t newSize);
    static bool Op11e9e50(BSTArrayScrap* self, std::uint32_t newSize);
};
