// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.
// BSTArrayEraseOrdered3, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
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

struct BSTArrayEraseOrdered3 {
    static void Op861910(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op86f7a0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op872a00(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op905b10(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op915b00(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op94cd60(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op964420(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op98c760(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9a58a0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9a5900(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9a5960(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op9c19f0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Opa5d8f0(BSTArrayScrap* self, std::uint32_t pos, std::uint32_t count);
    static void Opa77850(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Opcf2ef0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Opebe360(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Opfdd350(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Opffacb0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op1051700(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op10de120(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op11c7150(BSTArrayScrap* self, std::uint32_t pos, std::uint32_t count);
    static void Op11c71b0(BSTArrayScrap* self, std::uint32_t pos, std::uint32_t count);
    static void Op1224410(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op1241380(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op12507b0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op1250810(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op1251c60(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op1272a60(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op1272ac0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
    static void Op1514410(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count);
};
