// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// AllocSharedConstruct4Wrappers1, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once
#include <intrin.h>

struct AllocSharedConstruct4Wrappers1RefControl
{
    unsigned char unk00[0x08];
    volatile long uses; // volatile: atomic refcount increment target

    void AddRef()
    {
        // Copies can share a control block across threads.
        _InterlockedIncrement(&uses);
    }
};

struct AllocSharedConstruct4Wrappers1SharedBase
{
    void* ptr = nullptr;
    AllocSharedConstruct4Wrappers1RefControl* ctrl = nullptr;

    AllocSharedConstruct4Wrappers1SharedBase() = default;

    void CopyFrom(const AllocSharedConstruct4Wrappers1SharedBase& other)
    {
        if (other.ctrl != nullptr)
        {
            other.ctrl->AddRef();
        }
        ptr = other.ptr;
        ctrl = other.ctrl;
    }
};

struct AllocSharedConstruct4Wrappers1SharedRef : AllocSharedConstruct4Wrappers1SharedBase
{
    AllocSharedConstruct4Wrappers1SharedRef() = default;
    AllocSharedConstruct4Wrappers1SharedRef(const AllocSharedConstruct4Wrappers1SharedRef& other)
    {
        CopyFrom(other);
    }
    ~AllocSharedConstruct4Wrappers1SharedRef();
};

extern "C" void* (*gAllocFn_3356368)(unsigned long long size);
extern "C" void* Construct_134a090(void* mem, AllocSharedConstruct4Wrappers1SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_134b2f0(void* mem, AllocSharedConstruct4Wrappers1SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_134c460(void* mem, AllocSharedConstruct4Wrappers1SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_134c8b0(void* mem, AllocSharedConstruct4Wrappers1SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_134dc00(void* mem, AllocSharedConstruct4Wrappers1SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_134f820(void* mem, AllocSharedConstruct4Wrappers1SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_1351f00(void* mem, AllocSharedConstruct4Wrappers1SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_13522b0(void* mem, AllocSharedConstruct4Wrappers1SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_1352c20(void* mem, AllocSharedConstruct4Wrappers1SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_13540a0(void* mem, AllocSharedConstruct4Wrappers1SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_1356220(void* mem, AllocSharedConstruct4Wrappers1SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_1357780(void* mem, AllocSharedConstruct4Wrappers1SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_1357fe0(void* mem, AllocSharedConstruct4Wrappers1SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_13599a0(void* mem, AllocSharedConstruct4Wrappers1SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_135b3f0(void* mem, AllocSharedConstruct4Wrappers1SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_135c2e0(void* mem, AllocSharedConstruct4Wrappers1SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_135d370(void* mem, AllocSharedConstruct4Wrappers1SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_135e3f0(void* mem, AllocSharedConstruct4Wrappers1SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_135f330(void* mem, AllocSharedConstruct4Wrappers1SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_1361ca0(void* mem, AllocSharedConstruct4Wrappers1SharedRef sp, void* a2, void* a3);

struct AllocSharedConstruct4Wrappers1
{
    static void* Wrap12d82a0(AllocSharedConstruct4Wrappers1SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d8310(AllocSharedConstruct4Wrappers1SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d8380(AllocSharedConstruct4Wrappers1SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d83f0(AllocSharedConstruct4Wrappers1SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d8460(AllocSharedConstruct4Wrappers1SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d84d0(AllocSharedConstruct4Wrappers1SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d85d0(AllocSharedConstruct4Wrappers1SharedRef* sp, void** a2, void* a3);
    static void* Wrap12d8640(AllocSharedConstruct4Wrappers1SharedRef* sp, void** a2, void* a3);
    static void* Wrap12d87a0(AllocSharedConstruct4Wrappers1SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d8810(AllocSharedConstruct4Wrappers1SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d8900(AllocSharedConstruct4Wrappers1SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d89f0(AllocSharedConstruct4Wrappers1SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d8aa0(AllocSharedConstruct4Wrappers1SharedRef* sp, void** a2, void* a3);
    static void* Wrap12d8b10(AllocSharedConstruct4Wrappers1SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d8c20(AllocSharedConstruct4Wrappers1SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d8cd0(AllocSharedConstruct4Wrappers1SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d8d40(AllocSharedConstruct4Wrappers1SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d8db0(AllocSharedConstruct4Wrappers1SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d8e20(AllocSharedConstruct4Wrappers1SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d8f60(AllocSharedConstruct4Wrappers1SharedRef* sp, void* a2, void* a3);
};
