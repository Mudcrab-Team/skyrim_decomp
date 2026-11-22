// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original conditional sized-deallocator template.
// ConditionalDeallocators1, methods and callees: GUESS(low) STANDIN
// Adapted bodies: none
#pragma once

extern "C" void DeallocatorTarget15a743c(void* object, unsigned long long size);

struct ConditionalDeallocators1
{
    static void* Delete1259d40(void* object, unsigned int flags);
    static void* Delete1259da0(void* object, unsigned int flags);
    static void* Delete1283370(void* object, unsigned int flags);
    static void* Delete12adf70(void* object, unsigned int flags);
    static void* Delete12adfd0(void* object, unsigned int flags);
    static void* Delete12ae060(void* object, unsigned int flags);
    static void* Delete12bc650(void* object, unsigned int flags);
    static void* Delete12c99f0(void* object, unsigned int flags);
    static void* Delete12c9a20(void* object, unsigned int flags);
    static void* Delete1338d60(void* object, unsigned int flags);
    static void* Delete1338d90(void* object, unsigned int flags);
};
