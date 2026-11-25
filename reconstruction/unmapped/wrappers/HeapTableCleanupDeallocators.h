// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original custom-allocator deleting-destructor template.
// HeapTableCleanupDeallocators, types, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

struct HeapTableCleanupDeallocatorsGlobalHeap
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

struct HeapTableCleanupDeallocatorsTableObject
{
    void* table;
};

extern "C" HeapTableCleanupDeallocatorsGlobalHeap* GlobalHeapSlot3275ae0;
extern "C" void GlobalDeallocTarget1177a80(void* object, unsigned long long size);
extern "C" void CleanupTargetcf3100(void* object);
extern "C" unsigned char TableTarget1a2aa40[];
extern "C" unsigned char TableTarget1a2dc50[];
extern "C" unsigned char TableTarget1a3de90[];
extern "C" unsigned char TableTarget1a3f538[];
extern "C" unsigned char TableTarget1a40808[];
extern "C" unsigned char TableTarget1a9a998[];
extern "C" unsigned char TableTarget1a9c8b0[];

struct HeapTableCleanupDeallocators
{
    static void* Deleted41670(HeapTableCleanupDeallocatorsTableObject* object, unsigned int flags);
    static void* Deleted7d7a0(HeapTableCleanupDeallocatorsTableObject* object, unsigned int flags);
    static void* Deleted8eab0(HeapTableCleanupDeallocatorsTableObject* object, unsigned int flags);
    static void* Deletedf2620(HeapTableCleanupDeallocatorsTableObject* object, unsigned int flags);
    static void* Deletedf3d30(HeapTableCleanupDeallocatorsTableObject* object, unsigned int flags);
    static void* Deletee18880(HeapTableCleanupDeallocatorsTableObject* object, unsigned int flags);
    static void* Deletee55b20(HeapTableCleanupDeallocatorsTableObject* object, unsigned int flags);
    static void* Deletee9bf70(HeapTableCleanupDeallocatorsTableObject* object, unsigned int flags);
    static void* Delete1180ae0(HeapTableCleanupDeallocatorsTableObject* object, unsigned int flags);
};
