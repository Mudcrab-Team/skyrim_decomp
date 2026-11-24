// Source exposure: mixed (the listing of the pinned image; names from the sibling declarations used by the adapted body).
// Code origin: body adapted from the sibling; the memory manager initialisation check read from the listing
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/BSScript/BSScriptObject.inl:5
// BSScript::Object, BSScript::Object::operator delete, MemoryManager::Instance: SIBLING(fo4-private@1b765c70, author-permission)
// MemoryManager::EnsureInit, MemoryManager::Deallocate: CRASHLOGGER_PDB(59818@2026.10.24)
// g_memoryManager, g_memoryManagerGuard: GUESS(low)
#pragma once

#include <cstdint>

struct MemoryManager
{
    void EnsureInit(std::uint32_t* guard);
    void Deallocate(void* memory, bool aligned);

    static MemoryManager& Instance();
};

extern MemoryManager g_memoryManager;
extern std::uint32_t g_memoryManagerGuard;

inline MemoryManager& MemoryManager::Instance()
{
    if (g_memoryManagerGuard != 2) {
        g_memoryManager.EnsureInit(&g_memoryManagerGuard);
    }
    return g_memoryManager;
}

namespace BSScript
{
    class Object
    {
    public:
        static void operator delete(void* apMemory);  // compared: 0x11754d0
    };
}
