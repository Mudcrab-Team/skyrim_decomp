// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// AllocDerefU32Tail3Wrappers, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

extern "C" void* (*gAllocFn_3356368)(unsigned long long size);
extern "C" void* Construct_1359b30(void* mem, unsigned int a1, void* a2, void* a3);
extern "C" void* Construct_1367380(void* mem, unsigned int a1, void* a2, void* a3);
extern "C" void* Construct_1368680(void* mem, unsigned int a1, void* a2, void* a3);
extern "C" void* Construct_1369110(void* mem, unsigned int a1, void* a2, void* a3);
extern "C" void* Construct_1369f40(void* mem, unsigned int a1, void* a2, void* a3);

struct AllocDerefU32Tail3Wrappers
{
    static void* Wrap12d8b80(unsigned int* a1, void* a2, void* a3);
    static void* Wrap12d8bd0(unsigned int* a1, void* a2, void* a3);
    static void* Wrap12d9760(unsigned int* a1, void* a2, void* a3);
    static void* Wrap12d97b0(unsigned int* a1, void* a2, void* a3);
    static void* Wrap12d9870(unsigned int* a1, void* a2, void* a3);
    static void* Wrap12d98c0(unsigned int* a1, void* a2, void* a3);
    static void* Wrap12d9980(unsigned int* a1, void* a2, void* a3);
    static void* Wrap12d99d0(unsigned int* a1, void* a2, void* a3);
    static void* Wrap12d9a90(unsigned int* a1, void* a2, void* a3);
    static void* Wrap12d9ae0(unsigned int* a1, void* a2, void* a3);
};
