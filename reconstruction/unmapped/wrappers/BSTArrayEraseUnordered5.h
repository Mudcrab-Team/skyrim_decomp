// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.
// BSTArrayEraseUnordered5, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
#pragma once
#include <cstdint>

struct BSTArrayHeap {
    void* data;
    std::uint32_t capacity;
    alignas(8) std::uint32_t size;
};

extern "C" void __cdecl ArrayMove_ce0980(std::uint32_t* sizePtr, void* data, std::uint32_t dstIdx, std::uint32_t srcIdx, std::uint32_t count, std::uint32_t elemSize);

struct BSTArrayEraseUnordered5 {
    static void Op9f7130(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f7190(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f71f0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f7250(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f72b0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f7310(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f7370(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f73d0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f7430(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9f7490(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Opcdf110(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Opce2030(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Opcebae0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Opecca20(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Oped3610(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Oped3670(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Oped36d0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op14cd210(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op14cd270(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op1596df0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
};
