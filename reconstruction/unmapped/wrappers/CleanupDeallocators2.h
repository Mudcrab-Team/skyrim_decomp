// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original conditional sized-deallocator template.
// CleanupDeallocators2, methods and callees: GUESS(low) STANDIN
// Adapted bodies: none
#pragma once

extern "C" void CleanupTarget4e3290(void* object);
extern "C" void CleanupTarget652600(void* object);
extern "C" void CleanupTarget740690(void* object);
extern "C" void DeallocatorTarget15a743c(void* object, unsigned long long size);

struct CleanupDeallocators2
{
    static void* Delete4f5070(void* object, unsigned int flags);
    static void* Delete4f8e20(void* object, unsigned int flags);
    static void* Delete4f9100(void* object, unsigned int flags);
    static void* Delete4f96f0(void* object, unsigned int flags);
    static void* Delete661e20(void* object, unsigned int flags);
    static void* Delete769500(void* object, unsigned int flags);
};
