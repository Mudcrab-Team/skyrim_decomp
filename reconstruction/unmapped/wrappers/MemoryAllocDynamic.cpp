// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda MemoryFactoryManager::Allocate factory helpers.
// MemoryAllocDynamic, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
// 0x10b9f0 MemoryAllocDynamic::Op10b9f0
// 0x10ba30 MemoryAllocDynamic::Op10ba30
// 0x10c130 MemoryAllocDynamic::Op10c130
// 0x121170 MemoryAllocDynamic::Op121170
// 0x3ffc60 MemoryAllocDynamic::Op3ffc60
// 0x105e600 MemoryAllocDynamic::Op105e600
// 0x15de940 MemoryAllocDynamic::Op15de940
#include "MemoryAllocDynamic.h"

void* MemoryAllocDynamic::Op10b9f0(std::size_t size)
{
    return MemoryFactoryManager::Alloc(size, 0x0u, false);
}

void* MemoryAllocDynamic::Op10ba30(std::size_t size)
{
    return MemoryFactoryManager::Alloc(size, 0x0u, false);
}

void* MemoryAllocDynamic::Op10c130(std::size_t size)
{
    return MemoryFactoryManager::Alloc(size, 0x0u, false);
}

void* MemoryAllocDynamic::Op121170(std::size_t size)
{
    return MemoryFactoryManager::Alloc(size, 0x0u, false);
}

void* MemoryAllocDynamic::Op3ffc60(std::size_t size)
{
    return MemoryFactoryManager::Alloc(size, 0x10u, true);
}

void* MemoryAllocDynamic::Op105e600(std::size_t size)
{
    return MemoryFactoryManager::Alloc(size, 0x10u, true);
}

void* MemoryAllocDynamic::Op15de940(std::size_t size)
{
    return MemoryFactoryManager::Alloc(size, 0x0u, false);
}

