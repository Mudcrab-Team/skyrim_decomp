// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original conditional sized-deallocator template.
// CleanupDeallocators, methods and callees: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

extern "C" void CleanupTarget8e4de0(void* object);
extern "C" void DeallocatorTarget15a743c(void* object, unsigned long long size);

struct CleanupDeallocators
{
    static void* Delete888710(void* object, unsigned int flags);
    static void* Delete894750(void* object, unsigned int flags);
    static void* Delete8a4a90(void* object, unsigned int flags);
    static void* Delete8c0220(void* object, unsigned int flags);
};
