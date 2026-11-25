// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original conditional sized-deallocator template.
// CleanupDeallocatorLeaves, methods and callees: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
// 0x4b8680 CleanupDeallocatorLeaves::Delete4b8680
// 0x53d110 CleanupDeallocatorLeaves::Delete53d110
// 0x79a7b0 CleanupDeallocatorLeaves::Delete79a7b0
// 0x7b1c40 CleanupDeallocatorLeaves::Delete7b1c40
// 0x8fc670 CleanupDeallocatorLeaves::Delete8fc670
// 0xf9fd70 CleanupDeallocatorLeaves::Deletef9fd70
// 0x1099550 CleanupDeallocatorLeaves::Delete1099550
#include "CleanupDeallocatorLeaves.h"

void* CleanupDeallocatorLeaves::Delete4b8680(void* object, unsigned int flags)
{
    CleanupTarget4b6fd0(object);
    if ((flags & 1u) != 0u)
    {
        DeallocatorTarget15a743c(object, 184ull);
    }
    return object;
}

void* CleanupDeallocatorLeaves::Delete53d110(void* object, unsigned int flags)
{
    CleanupTarget53a0c0(object);
    if ((flags & 1u) != 0u)
    {
        DeallocatorTarget15a743c(object, 216ull);
    }
    return object;
}

void* CleanupDeallocatorLeaves::Delete79a7b0(void* object, unsigned int flags)
{
    CleanupTarget794e70(object);
    if ((flags & 1u) != 0u)
    {
        DeallocatorTarget15a743c(object, 464ull);
    }
    return object;
}

void* CleanupDeallocatorLeaves::Delete7b1c40(void* object, unsigned int flags)
{
    CleanupTarget7ad6e0(object);
    if ((flags & 1u) != 0u)
    {
        DeallocatorTarget15a743c(object, 480ull);
    }
    return object;
}

void* CleanupDeallocatorLeaves::Delete8fc670(void* object, unsigned int flags)
{
    CleanupTarget8f7b20(object);
    if ((flags & 1u) != 0u)
    {
        DeallocatorTarget15a743c(object, 360ull);
    }
    return object;
}

void* CleanupDeallocatorLeaves::Deletef9fd70(void* object, unsigned int flags)
{
    CleanupTargetf9ea90(object);
    if ((flags & 1u) != 0u)
    {
        DeallocatorTarget15a743c(object, 408ull);
    }
    return object;
}

void* CleanupDeallocatorLeaves::Delete1099550(void* object, unsigned int flags)
{
    CleanupTarget10de5d0(object);
    if ((flags & 1u) != 0u)
    {
        DeallocatorTarget15a743c(object, 608ull);
    }
    return object;
}
