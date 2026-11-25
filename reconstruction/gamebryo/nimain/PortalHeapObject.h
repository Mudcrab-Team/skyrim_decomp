// Source exposure: mixed (pinned image and labelled declarations).
// Code origin: Heap allocation follows the project implementation in BSTDerivedCreator_7db450.h.
// MemoryManager, EnsureInit and Allocate: CRASHLOGGER_PDB(59818@2026.10.24)
// PortalHeapObject, g_memoryManager and g_memoryManagerGuard: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

struct MemoryManager
{
    void EnsureInit(std::uint32_t* guard);
    void* Allocate(std::size_t size, std::int32_t alignment, bool alignmentRequired);
};

extern MemoryManager g_memoryManager;
extern std::uint32_t g_memoryManagerGuard;


struct PortalHeapObject
{
    static void* operator new(std::size_t size)
    {
        if (g_memoryManagerGuard != 2) {
            g_memoryManager.EnsureInit(&g_memoryManagerGuard);
        }
        return g_memoryManager.Allocate(size, 0, false);
    }
};
