// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original conditional sized-deallocator template.
// CleanupDeallocatorLeaves, methods and callees: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

extern "C" void CleanupTarget4b6fd0(void* object);
extern "C" void CleanupTarget53a0c0(void* object);
extern "C" void CleanupTarget794e70(void* object);
extern "C" void CleanupTarget7ad6e0(void* object);
extern "C" void CleanupTarget8f7b20(void* object);
extern "C" void CleanupTargetf9ea90(void* object);
extern "C" void CleanupTarget10de5d0(void* object);
extern "C" void DeallocatorTarget15a743c(void* object, unsigned long long size);

struct CleanupDeallocatorLeaves
{
    static void* Delete4b8680(void* object, unsigned int flags);
    static void* Delete53d110(void* object, unsigned int flags);
    static void* Delete79a7b0(void* object, unsigned int flags);
    static void* Delete7b1c40(void* object, unsigned int flags);
    static void* Delete8fc670(void* object, unsigned int flags);
    static void* Deletef9fd70(void* object, unsigned int flags);
    static void* Delete1099550(void* object, unsigned int flags);
};
