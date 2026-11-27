// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// AllocSharedConstruct5Wrappers, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once
#include <intrin.h>

struct AllocSharedConstruct5WrappersRefControl
{
    unsigned char unk00[0x08];
    volatile long uses; // volatile: atomic refcount increment target

    void AddRef()
    {
        // Copies can share a control block across threads.
        _InterlockedIncrement(&uses);
    }
};

struct AllocSharedConstruct5WrappersSharedBase
{
    void* ptr = nullptr;
    AllocSharedConstruct5WrappersRefControl* ctrl = nullptr;

    AllocSharedConstruct5WrappersSharedBase() = default;

    void CopyFrom(const AllocSharedConstruct5WrappersSharedBase& other)
    {
        if (other.ctrl != nullptr)
        {
            other.ctrl->AddRef();
        }
        ptr = other.ptr;
        ctrl = other.ctrl;
    }
};

struct AllocSharedConstruct5WrappersSharedRef : AllocSharedConstruct5WrappersSharedBase
{
    AllocSharedConstruct5WrappersSharedRef() = default;
    AllocSharedConstruct5WrappersSharedRef(const AllocSharedConstruct5WrappersSharedRef& other)
    {
        CopyFrom(other);
    }
    ~AllocSharedConstruct5WrappersSharedRef();
};

extern "C" void* (*gAllocFn_3356368)(unsigned long long size);
extern "C" void* Construct_13510d0(void* mem, AllocSharedConstruct5WrappersSharedRef sp, void* a2, void* a3, void* a4);
extern "C" void* Construct_1352660(void* mem, AllocSharedConstruct5WrappersSharedRef sp, void* a2, void* a3, void* a4);
extern "C" void* Construct_1360ce0(void* mem, AllocSharedConstruct5WrappersSharedRef sp, void* a2, void* a3, void* a4);
extern "C" void* Construct_13731a0(void* mem, AllocSharedConstruct5WrappersSharedRef sp, void* a2, void* a3, void* a4);
extern "C" void* Construct_136ae20(void* mem, AllocSharedConstruct5WrappersSharedRef sp, void* a2, void* a3, void* a4);
extern "C" void* Construct_136cc40(void* mem, AllocSharedConstruct5WrappersSharedRef sp, void* a2, void* a3, void* a4);
extern "C" void* Construct_13a0d40(void* mem, AllocSharedConstruct5WrappersSharedRef sp, void* a2, void* a3, void* a4);
extern "C" void* Construct_13d0b20(void* mem, AllocSharedConstruct5WrappersSharedRef sp, void* a2, void* a3, void* a4);
extern "C" void* Construct_1437000(void* mem, AllocSharedConstruct5WrappersSharedRef sp, void* a2, void* a3, void* a4);
extern "C" void* Construct_14378b0(void* mem, AllocSharedConstruct5WrappersSharedRef sp, void* a2, void* a3, void* a4);

struct AllocSharedConstruct5Wrappers
{
    static void* Wrap12d8540(AllocSharedConstruct5WrappersSharedRef* sp, void** a2, void* a3, void* a4);
    static void* Wrap12d86b0(AllocSharedConstruct5WrappersSharedRef* sp, void** a2, void** a3, void* a4);
    static void* Wrap12d8ed0(AllocSharedConstruct5WrappersSharedRef* sp, void** a2, void* a3, void* a4);
    static void* Wrap12d9430(AllocSharedConstruct5WrappersSharedRef* sp, void** a2, void** a3, void* a4);
    static void* Wrap12d9b30(AllocSharedConstruct5WrappersSharedRef* sp, void** a2, void* a3, void* a4);
    static void* Wrap12d9d10(AllocSharedConstruct5WrappersSharedRef* sp, void** a2, void* a3, void* a4);
    static void* Wrap1310090(AllocSharedConstruct5WrappersSharedRef* sp, void** a2, void** a3, void* a4);
    static void* Wrap13254f0(AllocSharedConstruct5WrappersSharedRef* sp, void** a2, void** a3, void* a4);
    static void* Wrap13b71d0(AllocSharedConstruct5WrappersSharedRef* sp, void** a2, void** a3, void* a4);
    static void* Wrap13c8380(AllocSharedConstruct5WrappersSharedRef* sp, void** a2, void** a3, void* a4);
};
