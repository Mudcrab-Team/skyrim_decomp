// Source exposure: mixed
// Code origin: Allocation helper adapted from the cited Fallout: New Vegas sibling.
// InlMalloc: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0); adapted allocation helper
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nisystem/nimemorydefines.cpp:151
// Unlockeac790: GUESS(low) STANDIN; original owner is unknown
// Functioneac790: GUESS(low); provisional entry name
// 0xeac790 Unlockeac790::Functioneac790
#include "Unlockeac790.h"

void* Unlockeac790::Functioneac790(std::size_t size)
{
    std::size_t alignment = 4;
    std::size_t bytes = size ? size : 1;
    return allocatorManager->allocator->Allocate(bytes, alignment, 5, false, nullptr, -1, nullptr);
}
