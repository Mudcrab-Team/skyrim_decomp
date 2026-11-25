// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original conditional sized-deallocator template.
// CleanupDeallocators, methods and callees: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
// 0x888710 CleanupDeallocators::Delete888710
// 0x894750 CleanupDeallocators::Delete894750
// 0x8a4a90 CleanupDeallocators::Delete8a4a90
// 0x8c0220 CleanupDeallocators::Delete8c0220
#include "CleanupDeallocators.h"

void* CleanupDeallocators::Delete888710(void* object, unsigned int flags)
{
    CleanupTarget8e4de0(object);
    if ((flags & 1u) != 0u)
    {
        DeallocatorTarget15a743c(object, 312ull);
    }
    return object;
}

void* CleanupDeallocators::Delete894750(void* object, unsigned int flags)
{
    CleanupTarget8e4de0(object);
    if ((flags & 1u) != 0u)
    {
        DeallocatorTarget15a743c(object, 328ull);
    }
    return object;
}

void* CleanupDeallocators::Delete8a4a90(void* object, unsigned int flags)
{
    CleanupTarget8e4de0(object);
    if ((flags & 1u) != 0u)
    {
        DeallocatorTarget15a743c(object, 320ull);
    }
    return object;
}

void* CleanupDeallocators::Delete8c0220(void* object, unsigned int flags)
{
    CleanupTarget8e4de0(object);
    if ((flags & 1u) != 0u)
    {
        DeallocatorTarget15a743c(object, 320ull);
    }
    return object;
}
