// Source exposure: mixed
// Code origin: Allocation helper adapted from the cited Fallout: New Vegas sibling.
// InlFree: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0); adapted allocation helper
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nisystem/nimemorydefines.cpp:145
// Unlockeaca30: GUESS(low) STANDIN; original owner is unknown
// Functioneaca30: GUESS(low); provisional entry name
// 0xeaca30 Unlockeaca30::Functioneaca30
#include "Unlockeaca30.h"

void Unlockeaca30::Functioneaca30(void* memory)
{
    if (memory)
        allocatorManager->allocator->Deallocate(memory, 9, static_cast<std::size_t>(-1));
}
