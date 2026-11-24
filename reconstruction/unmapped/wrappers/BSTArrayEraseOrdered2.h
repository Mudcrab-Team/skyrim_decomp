// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.
// BSTArrayEraseOrdered2, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
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

struct BSTArrayEraseOrdered2 {
    static void Op3ec610(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op3ec670(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op4680d0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op48d300(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op4c80b0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op4d5020(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op51c770(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op535bb0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op539f10(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op53dda0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op53de00(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op56f980(BSTArrayScrap* self, std::uint32_t pos, std::uint32_t count);
    static void Op577ec0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op5ff740(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op60b220(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op60d560(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op630270(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op645bc0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op6c2410(BSTArrayScrap* self, std::uint32_t pos, std::uint32_t count);
    static void Op6c2470(BSTArrayScrap* self, std::uint32_t pos, std::uint32_t count);
    static void Op71f290(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op771e70(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op771ed0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op771fb0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op7b4b50(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op805630(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op8095b0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op812fd0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op861850(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op8618b0(BSTArrayScrap* self, std::uint32_t pos, std::uint32_t count);
};
