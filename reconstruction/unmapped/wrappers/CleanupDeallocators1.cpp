// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original conditional sized-deallocator template.
// CleanupDeallocators1, methods and callees: GUESS(low) STANDIN
// Adapted bodies: none
// 0x419860 CleanupDeallocators1::Delete419860
#include "CleanupDeallocators1.h"

void* CleanupDeallocators1::Delete419860(void* object, unsigned int flags)
{
    CleanupTarget411280(object);
    if ((flags & 1u) != 0u)
    {
        DeallocatorTarget15a743c(object, 712ull);
    }
    return object;
}
