// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// AllocDeref2Construct5Wrappers, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

extern "C" void* (*gAllocFn_3356368)(unsigned long long size);
extern "C" void* Construct_1343350(void* mem, void* a1, void* a2, void* a3, void* a4);
extern "C" void* Construct_1374f40(void* mem, void* a1, void* a2, void* a3, void* a4);

struct AllocDeref2Construct5Wrappers
{
    static void* Wrap12d8740(void* a1, void** a2, void** a3, void* a4);
    static void* Wrap12ee230(void* a1, void** a2, void** a3, void* a4);
    static void* Wrap12ee300(void* a1, void** a2, void** a3, void* a4);
    static void* Wrap12ee360(void* a1, void** a2, void** a3, void* a4);
    static void* Wrap12ee3c0(void* a1, void** a2, void** a3, void* a4);
    static void* Wrap1423580(void* a1, void** a2, void** a3, void* a4);
};
