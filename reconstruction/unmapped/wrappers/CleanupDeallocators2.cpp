// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original conditional sized-deallocator template.
// CleanupDeallocators2, methods and callees: GUESS(low) STANDIN
// Adapted bodies: none
// 0x4f5070 CleanupDeallocators2::Delete4f5070
// 0x4f8e20 CleanupDeallocators2::Delete4f8e20
// 0x4f9100 CleanupDeallocators2::Delete4f9100
// 0x4f96f0 CleanupDeallocators2::Delete4f96f0
// 0x661e20 CleanupDeallocators2::Delete661e20
// 0x769500 CleanupDeallocators2::Delete769500
#include "CleanupDeallocators2.h"

void* CleanupDeallocators2::Delete4f5070(void* object, unsigned int flags)
{
    CleanupTarget4e3290(object);
    if ((flags & 1u) != 0u)
    {
        DeallocatorTarget15a743c(object, 264ull);
    }
    return object;
}

void* CleanupDeallocators2::Delete4f8e20(void* object, unsigned int flags)
{
    CleanupTarget4e3290(object);
    if ((flags & 1u) != 0u)
    {
        DeallocatorTarget15a743c(object, 272ull);
    }
    return object;
}

void* CleanupDeallocators2::Delete4f9100(void* object, unsigned int flags)
{
    CleanupTarget4e3290(object);
    if ((flags & 1u) != 0u)
    {
        DeallocatorTarget15a743c(object, 256ull);
    }
    return object;
}

void* CleanupDeallocators2::Delete4f96f0(void* object, unsigned int flags)
{
    CleanupTarget4e3290(object);
    if ((flags & 1u) != 0u)
    {
        DeallocatorTarget15a743c(object, 256ull);
    }
    return object;
}

void* CleanupDeallocators2::Delete661e20(void* object, unsigned int flags)
{
    CleanupTarget652600(object);
    if ((flags & 1u) != 0u)
    {
        DeallocatorTarget15a743c(object, 624ull);
    }
    return object;
}

void* CleanupDeallocators2::Delete769500(void* object, unsigned int flags)
{
    CleanupTarget740690(object);
    if ((flags & 1u) != 0u)
    {
        DeallocatorTarget15a743c(object, 3056ull);
    }
    return object;
}
