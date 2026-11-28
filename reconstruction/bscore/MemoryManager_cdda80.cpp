// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// Adapted bodies: none
// 0xcdda80 MemoryManager::QPoolExists
#include "MemoryManager_cdda80.h"

// Checks whether the pool table exists and contains an entry at poolIndex.
// Parameter count or return type differs from the CrashLogger prototype: the signature here is
// inferred from the body and is a guess.
bool MemoryManager::QPoolExists(std::uint32_t poolIndex) const
{
    if (poolTable && poolIndex < poolTable->GetPoolCount())
    {
        return true;
    }
    return false;
}
