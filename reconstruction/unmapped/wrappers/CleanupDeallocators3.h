// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original conditional sized-deallocator template.
// CleanupDeallocators3, methods and callees: GUESS(low) STANDIN
// Adapted bodies: none
#pragma once

extern "C" void CleanupTargetcd57b0(void* object);
extern "C" void CleanupTargete12230(void* object);
extern "C" void CleanupTargeteaefb0(void* object);
extern "C" void CleanupTargeteb95f0(void* object);
extern "C" void CleanupTargetf6b010(void* object);
extern "C" void DeallocatorTarget15a743c(void* object, unsigned long long size);

struct CleanupDeallocators3
{
    static void* Deletecd6c10(void* object, unsigned int flags);
    static void* Deletee12350(void* object, unsigned int flags);
    static void* Deleteeba640(void* object, unsigned int flags);
    static void* Deleteec3f30(void* object, unsigned int flags);
    static void* Deletef6a130(void* object, unsigned int flags);
};
