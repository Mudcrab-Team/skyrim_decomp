// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original custom-allocator deleting-destructor template.
// HeapTableDeallocators, types, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

struct HeapTableDeallocatorsGlobalHeap
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

struct HeapTableDeallocatorsTableObject
{
    void* table;
};

extern "C" HeapTableDeallocatorsGlobalHeap* GlobalHeapSlot3275ae0;
extern "C" void GlobalDeallocTarget1177a80(void* object, unsigned long long size);
extern "C" unsigned char TableTarget1a27c18[];
extern "C" unsigned char TableTarget1a2b938[];
extern "C" unsigned char TableTarget1a3bc78[];
extern "C" unsigned char TableTarget1ab9430[];
extern "C" unsigned char TableTarget1ab9490[];

struct HeapTableDeallocators
{
    static void* Deleted0c180(HeapTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Deleted0c1d0(HeapTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Deleted11c10(HeapTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Deleted1ced0(HeapTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Deleted1d8d0(HeapTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Deleted5b300(HeapTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Deleted5b350(HeapTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Deleted5b4d0(HeapTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Deleted5b520(HeapTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Deleted7d560(HeapTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Deletedf1780(HeapTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Deletedf17d0(HeapTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Deletee6e290(HeapTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Delete11a3ef0(HeapTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Delete11a4010(HeapTableDeallocatorsTableObject* object, unsigned int flags);
};
