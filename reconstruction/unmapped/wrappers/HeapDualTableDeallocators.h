// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original custom-allocator deleting-destructor template.
// HeapDualTableDeallocators, types, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

struct HeapDualTableDeallocatorsGlobalHeap
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0a();
    virtual void Slot0b();
    virtual void Free(void* block);
};

struct HeapDualTableDeallocatorsDualTableObject20
{
    void* table0;
    unsigned char unk08[0x18];
    void* table1;
};

extern "C" HeapDualTableDeallocatorsGlobalHeap* GlobalHeapSlot3275ae0;
extern "C" void GlobalDeallocTarget1177a80(void* object, unsigned long long size);
extern "C" void CleanupTargetd116d0(void* object);
extern "C" void CleanupTargetd163b0(void* object);
extern "C" void CleanupTargetddd750(void* object);
extern "C" unsigned char TableTarget1a28010[];
extern "C" unsigned char TableTarget1a28098[];
extern "C" unsigned char TableTarget1a28428[];
extern "C" unsigned char TableTarget1a284b0[];
extern "C" unsigned char TableTarget1a290c0[];
extern "C" unsigned char TableTarget1a29108[];
extern "C" unsigned char TableTarget1a399a8[];
extern "C" unsigned char TableTarget1a399f0[];
extern "C" unsigned char TableTarget1a39dd8[];
extern "C" unsigned char TableTarget1a39e20[];
extern "C" unsigned char TableTarget1a3a248[];
extern "C" unsigned char TableTarget1a3a290[];
extern "C" unsigned char TableTarget1a3a678[];
extern "C" unsigned char TableTarget1a3a6c0[];
extern "C" unsigned char TableTarget1a3aaa8[];
extern "C" unsigned char TableTarget1a3aaf0[];
extern "C" unsigned char TableTarget1a3af00[];
extern "C" unsigned char TableTarget1a3af48[];

struct HeapDualTableDeallocators
{
    static void* Deleted11cc0(HeapDualTableDeallocatorsDualTableObject20* object, unsigned int flags);
    static void* Deleted16530(HeapDualTableDeallocatorsDualTableObject20* object, unsigned int flags);
    static void* Deleted165a0(HeapDualTableDeallocatorsDualTableObject20* object, unsigned int flags);
    static void* Deleted16610(HeapDualTableDeallocatorsDualTableObject20* object, unsigned int flags);
    static void* Deleted1d5a0(HeapDualTableDeallocatorsDualTableObject20* object, unsigned int flags);
    static void* Deleteddd8c0(HeapDualTableDeallocatorsDualTableObject20* object, unsigned int flags);
    static void* Deletedde8d0(HeapDualTableDeallocatorsDualTableObject20* object, unsigned int flags);
    static void* Deletede0720(HeapDualTableDeallocatorsDualTableObject20* object, unsigned int flags);
    static void* Deletede20e0(HeapDualTableDeallocatorsDualTableObject20* object, unsigned int flags);
    static void* Deletede3400(HeapDualTableDeallocatorsDualTableObject20* object, unsigned int flags);
    static void* Deletede53e0(HeapDualTableDeallocatorsDualTableObject20* object, unsigned int flags);
};
