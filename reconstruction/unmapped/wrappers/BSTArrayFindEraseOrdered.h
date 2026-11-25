// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.
// BSTArrayFindEraseOrdered, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
#pragma once
#include <cstdint>

struct BSTArrayHeap {
    void* data;
    std::uint32_t capacity;
    alignas(8) std::uint32_t size;
};

extern "C" void __cdecl ArrayMove_ce0980(std::uint32_t* sizePtr, void* data, std::uint32_t dstIdx, std::uint32_t srcIdx, std::uint32_t count, std::uint32_t elemSize);

struct BSTArrayFindEraseOrdered {
    static bool Op1c5810(BSTArrayHeap* self, const std::uint64_t* key);
    static bool Op1c58c0(BSTArrayHeap* self, const std::uint64_t* key);
    static bool Op1c5970(BSTArrayHeap* self, const std::uint64_t* key);
    static bool Op1c5a20(BSTArrayHeap* self, const std::uint64_t* key);
    static bool Op2dc170(BSTArrayHeap* self, const std::uint32_t* key);
    static bool Op2dc220(BSTArrayHeap* self, const std::uint32_t* key);
    static bool Op397c50(BSTArrayHeap* self, const std::uint64_t* key);
    static bool Op397d00(BSTArrayHeap* self, const std::uint64_t* key);
    static bool Op62af00(BSTArrayHeap* self, const std::uint64_t* key);
    static bool Op62afb0(BSTArrayHeap* self, const std::uint64_t* key);
    static bool Op766020(BSTArrayHeap* self, const std::uint64_t* key);
    static bool Op7660d0(BSTArrayHeap* self, const std::uint64_t* key);
    static bool Op94c790(BSTArrayHeap* self, const std::uint64_t* key);
    static bool Op94c840(BSTArrayHeap* self, const std::uint64_t* key);
    static bool Op1569860(BSTArrayHeap* self, const std::uint64_t* key);
    static bool Op1569910(BSTArrayHeap* self, const std::uint64_t* key);
};
