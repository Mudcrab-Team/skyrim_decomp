// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// BSShaderAccumulator::FinishAccumulatingCollectGeometry, BSGeometry, MemoryManager::EnsureInit: CRASHLOGGER_PDB(59818@2026.10.24)
// GeometryListNode, head, tail, count and allocator globals: GUESS(low) STANDIN
#pragma once

#include <cstddef>
struct MemoryManager {
    void EnsureInit(unsigned int* state);
    void* Allocate(std::size_t size, int alignment, bool aligned);
};
extern MemoryManager memoryManager;
extern unsigned int memoryState;
struct BSGeometry;
struct GeometryListNode {
    GeometryListNode* next;
    GeometryListNode* previous;
    BSGeometry* geometry;
    static void* operator new(std::size_t size) noexcept {
        if (memoryState != 2)
            memoryManager.EnsureInit(&memoryState);
        return memoryManager.Allocate(size, 0, false);
    }
    GeometryListNode() : previous(nullptr) {}
};
struct BSShaderAccumulator {
    unsigned char unknown00[0x18];
    GeometryListNode* head;
    GeometryListNode* tail;
    unsigned int count;
    bool FinishAccumulatingCollectGeometry(BSGeometry* geometry);
};
