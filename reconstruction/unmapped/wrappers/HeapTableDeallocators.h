// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original Scaleform-heap scalar deleting destructor wrappers.
// HeapTableDeallocators, ScaleformHeapAllocator, PolymorphicHeapObject and referenced globals: GUESS(low) STANDIN; original types unknown.
// Adapted bodies: none
#pragma once

// Minimal vtable stand-in matching slot 12 (Free) of the Scaleform global heap.
struct ScaleformHeapAllocator
{
    virtual ~ScaleformHeapAllocator();
    virtual void Reserved01();
    virtual void Reserved02();
    virtual void Reserved03();
    virtual void Reserved04();
    virtual void Reserved05();
    virtual void Reserved06();
    virtual void Reserved07();
    virtual void Reserved08();
    virtual void Reserved09();
    virtual void Reserved10();
    virtual void Reserved11();
    virtual void Free(void* block);
};

struct PolymorphicHeapObject
{
    void* vftable;
};

extern "C" ScaleformHeapAllocator* g_scaleformHeap;
extern "C" void GlobalSizedDelete(void* object, unsigned long long objectSize);
extern "C" unsigned char kBaseVftable1a27c18[];
extern "C" unsigned char kBaseVftable1a2b938[];
extern "C" unsigned char kBaseVftable1a3bc78[];
extern "C" unsigned char kBaseVftable1ab9430[];
extern "C" unsigned char kBaseVftable1ab9490[];

struct HeapTableDeallocators
{
    static void* Deleted0c180(PolymorphicHeapObject* object, unsigned int deleteFlags);
    static void* Deleted0c1d0(PolymorphicHeapObject* object, unsigned int deleteFlags);
    static void* Deleted11c10(PolymorphicHeapObject* object, unsigned int deleteFlags);
    static void* Deleted1ced0(PolymorphicHeapObject* object, unsigned int deleteFlags);
    static void* Deleted1d8d0(PolymorphicHeapObject* object, unsigned int deleteFlags);
    static void* Deleted5b300(PolymorphicHeapObject* object, unsigned int deleteFlags);
    static void* Deleted5b350(PolymorphicHeapObject* object, unsigned int deleteFlags);
    static void* Deleted5b4d0(PolymorphicHeapObject* object, unsigned int deleteFlags);
    static void* Deleted5b520(PolymorphicHeapObject* object, unsigned int deleteFlags);
    static void* Deleted7d560(PolymorphicHeapObject* object, unsigned int deleteFlags);
    static void* Deletedf1780(PolymorphicHeapObject* object, unsigned int deleteFlags);
    static void* Deletedf17d0(PolymorphicHeapObject* object, unsigned int deleteFlags);
    static void* Deletee6e290(PolymorphicHeapObject* object, unsigned int deleteFlags);
    static void* Delete11a3ef0(PolymorphicHeapObject* object, unsigned int deleteFlags);
    static void* Delete11a4010(PolymorphicHeapObject* object, unsigned int deleteFlags);
};
