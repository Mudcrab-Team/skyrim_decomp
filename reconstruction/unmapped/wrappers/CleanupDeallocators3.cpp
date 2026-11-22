// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original conditional sized-deallocator template.
// CleanupDeallocators3, methods and callees: GUESS(low) STANDIN
// Adapted bodies: none
// 0xcd6c10 CleanupDeallocators3::Deletecd6c10
// 0xe12350 CleanupDeallocators3::Deletee12350
// 0xeba640 CleanupDeallocators3::Deleteeba640
// 0xec3f30 CleanupDeallocators3::Deleteec3f30
// 0xf6a130 CleanupDeallocators3::Deletef6a130
#include "CleanupDeallocators3.h"

void* CleanupDeallocators3::Deletecd6c10(void* object, unsigned int flags)
{
    CleanupTargetcd57b0(object);
    if ((flags & 1u) != 0u)
    {
        DeallocatorTarget15a743c(object, 216ull);
    }
    return object;
}

void* CleanupDeallocators3::Deletee12350(void* object, unsigned int flags)
{
    CleanupTargete12230(object);
    if ((flags & 1u) != 0u)
    {
        DeallocatorTarget15a743c(object, 216ull);
    }
    return object;
}

void* CleanupDeallocators3::Deleteeba640(void* object, unsigned int flags)
{
    CleanupTargeteb95f0(object);
    if ((flags & 1u) != 0u)
    {
        DeallocatorTarget15a743c(object, 400ull);
    }
    return object;
}

void* CleanupDeallocators3::Deleteec3f30(void* object, unsigned int flags)
{
    CleanupTargeteaefb0(object);
    if ((flags & 1u) != 0u)
    {
        DeallocatorTarget15a743c(object, 536ull);
    }
    return object;
}

void* CleanupDeallocators3::Deletef6a130(void* object, unsigned int flags)
{
    CleanupTargetf6b010(object);
    if ((flags & 1u) != 0u)
    {
        DeallocatorTarget15a743c(object, 120ull);
    }
    return object;
}
