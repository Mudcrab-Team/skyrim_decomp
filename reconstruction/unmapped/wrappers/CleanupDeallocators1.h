// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original conditional sized-deallocator template.
// CleanupDeallocators1, methods and callees: GUESS(low) STANDIN
// Adapted bodies: none
#pragma once

extern "C" void CleanupTarget411280(void* object);
extern "C" void DeallocatorTarget15a743c(void* object, unsigned long long size);

struct CleanupDeallocators1
{
    static void* Delete419860(void* object, unsigned int flags);
};
