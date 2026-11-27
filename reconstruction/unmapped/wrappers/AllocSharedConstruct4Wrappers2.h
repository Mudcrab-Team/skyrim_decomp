// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// AllocSharedConstruct4Wrappers2, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once
#include <intrin.h>

struct AllocSharedConstruct4Wrappers2RefControl
{
    unsigned char unk00[0x08];
    volatile long uses; // volatile: atomic refcount increment target

    void AddRef()
    {
        // Copies can share a control block across threads.
        _InterlockedIncrement(&uses);
    }
};

struct AllocSharedConstruct4Wrappers2SharedBase
{
    void* ptr = nullptr;
    AllocSharedConstruct4Wrappers2RefControl* ctrl = nullptr;

    AllocSharedConstruct4Wrappers2SharedBase() = default;

    void CopyFrom(const AllocSharedConstruct4Wrappers2SharedBase& other)
    {
        if (other.ctrl != nullptr)
        {
            other.ctrl->AddRef();
        }
        ptr = other.ptr;
        ctrl = other.ctrl;
    }
};

struct AllocSharedConstruct4Wrappers2SharedRef : AllocSharedConstruct4Wrappers2SharedBase
{
    AllocSharedConstruct4Wrappers2SharedRef() = default;
    AllocSharedConstruct4Wrappers2SharedRef(const AllocSharedConstruct4Wrappers2SharedRef& other)
    {
        CopyFrom(other);
    }
    ~AllocSharedConstruct4Wrappers2SharedRef();
};

extern "C" void* (*gAllocFn_3356368)(unsigned long long size);
extern "C" void* Construct_1362350(void* mem, AllocSharedConstruct4Wrappers2SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_1362ed0(void* mem, AllocSharedConstruct4Wrappers2SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_13627d0(void* mem, AllocSharedConstruct4Wrappers2SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_13629a0(void* mem, AllocSharedConstruct4Wrappers2SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_13633d0(void* mem, AllocSharedConstruct4Wrappers2SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_13635b0(void* mem, AllocSharedConstruct4Wrappers2SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_1364350(void* mem, AllocSharedConstruct4Wrappers2SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_1364560(void* mem, AllocSharedConstruct4Wrappers2SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_1365320(void* mem, AllocSharedConstruct4Wrappers2SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_1365940(void* mem, AllocSharedConstruct4Wrappers2SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_1372fc0(void* mem, AllocSharedConstruct4Wrappers2SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_1372c80(void* mem, AllocSharedConstruct4Wrappers2SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_1366650(void* mem, AllocSharedConstruct4Wrappers2SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_1366b00(void* mem, AllocSharedConstruct4Wrappers2SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_1365fc0(void* mem, AllocSharedConstruct4Wrappers2SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_13671e0(void* mem, AllocSharedConstruct4Wrappers2SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_13684e0(void* mem, AllocSharedConstruct4Wrappers2SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_1368f70(void* mem, AllocSharedConstruct4Wrappers2SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_1369db0(void* mem, AllocSharedConstruct4Wrappers2SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_136bbb0(void* mem, AllocSharedConstruct4Wrappers2SharedRef sp, void* a2, void* a3);

struct AllocSharedConstruct4Wrappers2
{
    static void* Wrap12d8fd0(AllocSharedConstruct4Wrappers2SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d9040(AllocSharedConstruct4Wrappers2SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d90b0(AllocSharedConstruct4Wrappers2SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d9120(AllocSharedConstruct4Wrappers2SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d9190(AllocSharedConstruct4Wrappers2SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d9200(AllocSharedConstruct4Wrappers2SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d9270(AllocSharedConstruct4Wrappers2SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d92e0(AllocSharedConstruct4Wrappers2SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d9350(AllocSharedConstruct4Wrappers2SharedRef* sp, void** a2, void* a3);
    static void* Wrap12d93c0(AllocSharedConstruct4Wrappers2SharedRef* sp, void** a2, void* a3);
    static void* Wrap12d94c0(AllocSharedConstruct4Wrappers2SharedRef* sp, void** a2, void* a3);
    static void* Wrap12d9530(AllocSharedConstruct4Wrappers2SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d95a0(AllocSharedConstruct4Wrappers2SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d9610(AllocSharedConstruct4Wrappers2SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d9680(AllocSharedConstruct4Wrappers2SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d96f0(AllocSharedConstruct4Wrappers2SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d9800(AllocSharedConstruct4Wrappers2SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d9910(AllocSharedConstruct4Wrappers2SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d9a20(AllocSharedConstruct4Wrappers2SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d9bc0(AllocSharedConstruct4Wrappers2SharedRef* sp, void* a2, void* a3);
};
