// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// AllocSharedConstruct4Wrappers3, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once
#include <intrin.h>

struct AllocSharedConstruct4Wrappers3RefControl
{
    unsigned char unk00[0x08];
    volatile long uses; // volatile: atomic refcount increment target

    void AddRef()
    {
        // Copies can share a control block across threads.
        _InterlockedIncrement(&uses);
    }
};

struct AllocSharedConstruct4Wrappers3SharedBase
{
    void* ptr = nullptr;
    AllocSharedConstruct4Wrappers3RefControl* ctrl = nullptr;

    AllocSharedConstruct4Wrappers3SharedBase() = default;

    void CopyFrom(const AllocSharedConstruct4Wrappers3SharedBase& other)
    {
        if (other.ctrl != nullptr)
        {
            other.ctrl->AddRef();
        }
        ptr = other.ptr;
        ctrl = other.ctrl;
    }
};

struct AllocSharedConstruct4Wrappers3SharedRef : AllocSharedConstruct4Wrappers3SharedBase
{
    AllocSharedConstruct4Wrappers3SharedRef() = default;
    AllocSharedConstruct4Wrappers3SharedRef(const AllocSharedConstruct4Wrappers3SharedRef& other)
    {
        CopyFrom(other);
    }
    ~AllocSharedConstruct4Wrappers3SharedRef();
};

extern "C" void* (*gAllocFn_3356368)(unsigned long long size);
extern "C" void* Construct_136bf70(void* mem, AllocSharedConstruct4Wrappers3SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_136c550(void* mem, AllocSharedConstruct4Wrappers3SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_136d690(void* mem, AllocSharedConstruct4Wrappers3SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_136dc50(void* mem, AllocSharedConstruct4Wrappers3SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_136e750(void* mem, AllocSharedConstruct4Wrappers3SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_136eb50(void* mem, AllocSharedConstruct4Wrappers3SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_136ef70(void* mem, AllocSharedConstruct4Wrappers3SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_136f390(void* mem, AllocSharedConstruct4Wrappers3SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_1371210(void* mem, AllocSharedConstruct4Wrappers3SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_137c5d0(void* mem, AllocSharedConstruct4Wrappers3SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_137f980(void* mem, AllocSharedConstruct4Wrappers3SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_13a1620(void* mem, AllocSharedConstruct4Wrappers3SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_13a0b80(void* mem, AllocSharedConstruct4Wrappers3SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_13a0860(void* mem, AllocSharedConstruct4Wrappers3SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_13beb60(void* mem, AllocSharedConstruct4Wrappers3SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_13acdd0(void* mem, AllocSharedConstruct4Wrappers3SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_13c4f90(void* mem, AllocSharedConstruct4Wrappers3SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_13b5100(void* mem, AllocSharedConstruct4Wrappers3SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_13cb3d0(void* mem, AllocSharedConstruct4Wrappers3SharedRef sp, void* a2, void* a3);
extern "C" void* Construct_13c3f20(void* mem, AllocSharedConstruct4Wrappers3SharedRef sp, void* a2, void* a3);

struct AllocSharedConstruct4Wrappers3
{
    static void* Wrap12d9c30(AllocSharedConstruct4Wrappers3SharedRef* sp, void** a2, void* a3);
    static void* Wrap12d9ca0(AllocSharedConstruct4Wrappers3SharedRef* sp, void** a2, void* a3);
    static void* Wrap12d9da0(AllocSharedConstruct4Wrappers3SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d9e10(AllocSharedConstruct4Wrappers3SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d9e80(AllocSharedConstruct4Wrappers3SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d9f40(AllocSharedConstruct4Wrappers3SharedRef* sp, void* a2, void* a3);
    static void* Wrap12d9fb0(AllocSharedConstruct4Wrappers3SharedRef* sp, void* a2, void* a3);
    static void* Wrap12da020(AllocSharedConstruct4Wrappers3SharedRef* sp, void* a2, void* a3);
    static void* Wrap12da1a0(AllocSharedConstruct4Wrappers3SharedRef* sp, void* a2, void* a3);
    static void* Wrap12f1160(AllocSharedConstruct4Wrappers3SharedRef* sp, void* a2, void* a3);
    static void* Wrap12f16c0(AllocSharedConstruct4Wrappers3SharedRef* sp, void* a2, void* a3);
    static void* Wrap1310020(AllocSharedConstruct4Wrappers3SharedRef* sp, void* a2, void* a3);
    static void* Wrap1310120(AllocSharedConstruct4Wrappers3SharedRef* sp, void** a2, void* a3);
    static void* Wrap1310190(AllocSharedConstruct4Wrappers3SharedRef* sp, void* a2, void* a3);
    static void* Wrap131dc70(AllocSharedConstruct4Wrappers3SharedRef* sp, void* a2, void* a3);
    static void* Wrap131dce0(AllocSharedConstruct4Wrappers3SharedRef* sp, void* a2, void* a3);
    static void* Wrap131e0a0(AllocSharedConstruct4Wrappers3SharedRef* sp, void* a2, void* a3);
    static void* Wrap131e890(AllocSharedConstruct4Wrappers3SharedRef* sp, void* a2, void* a3);
    static void* Wrap131ebf0(AllocSharedConstruct4Wrappers3SharedRef* sp, void* a2, void* a3);
    static void* Wrap131eda0(AllocSharedConstruct4Wrappers3SharedRef* sp, void* a2, void* a3);
};
