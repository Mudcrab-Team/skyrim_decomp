// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// AllocSharedConstruct4Wrappers4, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once
#include <intrin.h>

struct AllocSharedConstruct4Wrappers4RefControl
{
    unsigned char unk00[0x08];
    volatile long uses; // volatile: atomic refcount increment target

    void AddRef()
    {
        // Copies can share a control block across threads.
        _InterlockedIncrement(&uses);
    }
};

struct AllocSharedConstruct4Wrappers4SharedBase
{
    void* ptr = nullptr;
    AllocSharedConstruct4Wrappers4RefControl* ctrl = nullptr;

    AllocSharedConstruct4Wrappers4SharedBase() = default;

    void CopyFrom(const AllocSharedConstruct4Wrappers4SharedBase& other)
    {
        if (other.ctrl != nullptr)
        {
            other.ctrl->AddRef();
        }
        ptr = other.ptr;
        ctrl = other.ctrl;
    }
};

struct AllocSharedConstruct4Wrappers4SharedRef : AllocSharedConstruct4Wrappers4SharedBase
{
    AllocSharedConstruct4Wrappers4SharedRef() = default;
    AllocSharedConstruct4Wrappers4SharedRef(const AllocSharedConstruct4Wrappers4SharedRef& other)
    {
        CopyFrom(other);
    }
    ~AllocSharedConstruct4Wrappers4SharedRef();
};

extern "C" void* (*gAllocFn_3356368)(unsigned long long size);
extern "C" void* Construct_13be580(void* mem, AllocSharedConstruct4Wrappers4SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_13cf240(void* mem, AllocSharedConstruct4Wrappers4SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_13cc640(void* mem, AllocSharedConstruct4Wrappers4SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_13cd870(void* mem, AllocSharedConstruct4Wrappers4SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_13cd9f0(void* mem, AllocSharedConstruct4Wrappers4SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_13d7540(void* mem, AllocSharedConstruct4Wrappers4SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_1328100(void* mem, AllocSharedConstruct4Wrappers4SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_1434be0(void* mem, AllocSharedConstruct4Wrappers4SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_1434fd0(void* mem, AllocSharedConstruct4Wrappers4SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_14404c0(void* mem, AllocSharedConstruct4Wrappers4SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_143f5e0(void* mem, AllocSharedConstruct4Wrappers4SharedRef sp, void* a2, void* a3);

struct AllocSharedConstruct4Wrappers4
{
    static void* Wrap131ef00(AllocSharedConstruct4Wrappers4SharedRef* sp, void* a2, void* a3);
    static void* Wrap1325480(AllocSharedConstruct4Wrappers4SharedRef* sp, void** a2, void* a3);
    static void* Wrap1325580(AllocSharedConstruct4Wrappers4SharedRef* sp, void** a2, void* a3);
    static void* Wrap13255f0(AllocSharedConstruct4Wrappers4SharedRef* sp, void* a2, void* a3);
    static void* Wrap1325660(AllocSharedConstruct4Wrappers4SharedRef* sp, void* a2, void* a3);
    static void* Wrap1327db0(AllocSharedConstruct4Wrappers4SharedRef* sp, void* a2, void* a3);
    static void* Wrap1327e20(AllocSharedConstruct4Wrappers4SharedRef* sp, void* a2, void* a3);
    static void* Wrap13afa30(AllocSharedConstruct4Wrappers4SharedRef* sp, void* a2, void* a3);
    static void* Wrap13b0420(AllocSharedConstruct4Wrappers4SharedRef* sp, void** a2, void* a3);
    static void* Wrap13d80b0(AllocSharedConstruct4Wrappers4SharedRef* sp, void* a2, void* a3);
    static void* Wrap13d8120(AllocSharedConstruct4Wrappers4SharedRef* sp, void* a2, void* a3);
};
