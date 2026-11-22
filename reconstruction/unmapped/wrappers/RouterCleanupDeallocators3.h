// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original custom-allocator deleting-destructor template.
// RouterCleanupDeallocators3, types, methods and referenced symbols: GUESS(low) STANDIN
// Adapted bodies: none
#pragma once

struct RouterCleanupDeallocators3BlockHeap
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void BlockFree(void* block, int size);
};

struct RouterCleanupDeallocators3MemoryRouter
{
    unsigned char unk00[0x58];
    RouterCleanupDeallocators3BlockHeap* heap;
};

struct RouterCleanupDeallocators3TaggedObject
{
    void* table;
    unsigned short memSizeAndFlags;
};

extern "C" unsigned int RouterTlsSlot325a844;
extern "C" void* (*const TlsGetValueSlot17c8418)(unsigned int slot);
extern "C" void GlobalDeallocTarget1177a80(void* object, unsigned long long size);
extern "C" void CleanupTargetbaf420(void* object);
extern "C" void CleanupTargetbb5400(void* object);

struct RouterCleanupDeallocators3
{
    static void* Deletebafb10(RouterCleanupDeallocators3TaggedObject* object, unsigned int flags);
    static void* Deletebb54b0(RouterCleanupDeallocators3TaggedObject* object, unsigned int flags);
};
