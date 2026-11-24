// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.
// BSTArrayEraseUnordered4, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
#pragma once
#include <cstdint>

struct BSTArrayHeap {
    void* data;
    std::uint32_t capacity;
    alignas(8) std::uint32_t size;
};

extern "C" void __cdecl ArrayMove_ce0980(std::uint32_t* sizePtr, void* data, std::uint32_t dstIdx, std::uint32_t srcIdx, std::uint32_t count, std::uint32_t elemSize);

struct BSTArrayEraseUnordered4 {
    static void Op9f65f0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f6650(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f66b0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f6710(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f6770(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f67d0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f6830(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f6890(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f68f0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f6950(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f69b0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f6a10(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f6a70(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f6ad0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f6b30(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f6b90(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f6bf0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f6c50(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f6cb0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f6d10(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f6d70(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f6dd0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f6e30(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f6e90(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f6ef0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f6f50(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f6fb0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f7010(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f7070(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f70d0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
};
