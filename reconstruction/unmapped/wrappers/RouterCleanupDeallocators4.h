// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original custom-allocator deleting-destructor template.
// RouterCleanupDeallocators4, types, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

struct RouterCleanupDeallocators4BlockHeap
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void BlockFree(void* block, int size);
};

struct RouterCleanupDeallocators4MemoryRouter
{
    unsigned char unk00[0x58];
    RouterCleanupDeallocators4BlockHeap* heap;
};

struct RouterCleanupDeallocators4TaggedObject
{
    void* table;
    unsigned short memSizeAndFlags;
};

extern "C" unsigned int RouterTlsSlot325a844;
extern "C" void* (*const TlsGetValueSlot17c8418)(unsigned int slot);
extern "C" void GlobalDeallocTarget1177a80(void* object, unsigned long long size);
extern "C" void CleanupTarget10ab140(void* object);
extern "C" void CleanupTarget10d1190(void* object);
extern "C" void CleanupTarget10d1230(void* object);
extern "C" void CleanupTarget10d1350(void* object);
extern "C" void CleanupTarget10d1400(void* object);
extern "C" void CleanupTarget10d1480(void* object);
extern "C" void CleanupTarget10d1520(void* object);
extern "C" void CleanupTarget10d15c0(void* object);
extern "C" void CleanupTarget10d16c0(void* object);
extern "C" void CleanupTarget10d4220(void* object);
extern "C" void CleanupTarget10da160(void* object);
extern "C" void CleanupTarget10e4df0(void* object);
extern "C" void CleanupTarget10eb9a0(void* object);
extern "C" void CleanupTarget10f0f00(void* object);
extern "C" void CleanupTarget1104330(void* object);
extern "C" void CleanupTarget1104690(void* object);
extern "C" void CleanupTarget11075b0(void* object);
extern "C" void CleanupTarget1116690(void* object);
extern "C" void CleanupTarget1116c00(void* object);
extern "C" void CleanupTarget1124040(void* object);
extern "C" void CleanupTarget1128560(void* object);
extern "C" void CleanupTarget1129550(void* object);
extern "C" void CleanupTarget112b050(void* object);
extern "C" void CleanupTarget112b650(void* object);
extern "C" void CleanupTarget113ffc0(void* object);
extern "C" void CleanupTarget115a4c0(void* object);

struct RouterCleanupDeallocators4
{
    static void* Delete10d1790(RouterCleanupDeallocators4TaggedObject* object, unsigned int flags);
    static void* Delete10d18d0(RouterCleanupDeallocators4TaggedObject* object, unsigned int flags);
    static void* Delete10d1950(RouterCleanupDeallocators4TaggedObject* object, unsigned int flags);
    static void* Delete10d1a60(RouterCleanupDeallocators4TaggedObject* object, unsigned int flags);
    static void* Delete10d1c00(RouterCleanupDeallocators4TaggedObject* object, unsigned int flags);
    static void* Delete10d1c80(RouterCleanupDeallocators4TaggedObject* object, unsigned int flags);
    static void* Delete10d1d90(RouterCleanupDeallocators4TaggedObject* object, unsigned int flags);
    static void* Delete10d1f30(RouterCleanupDeallocators4TaggedObject* object, unsigned int flags);
    static void* Delete10d9ee0(RouterCleanupDeallocators4TaggedObject* object, unsigned int flags);
    static void* Delete10dd350(RouterCleanupDeallocators4TaggedObject* object, unsigned int flags);
    static void* Delete10e54a0(RouterCleanupDeallocators4TaggedObject* object, unsigned int flags);
    static void* Delete10e6eb0(RouterCleanupDeallocators4TaggedObject* object, unsigned int flags);
    static void* Delete10f9e30(RouterCleanupDeallocators4TaggedObject* object, unsigned int flags);
    static void* Delete1106d90(RouterCleanupDeallocators4TaggedObject* object, unsigned int flags);
    static void* Delete1106e10(RouterCleanupDeallocators4TaggedObject* object, unsigned int flags);
    static void* Delete1107750(RouterCleanupDeallocators4TaggedObject* object, unsigned int flags);
    static void* Delete1112f00(RouterCleanupDeallocators4TaggedObject* object, unsigned int flags);
    static void* Delete1116b30(RouterCleanupDeallocators4TaggedObject* object, unsigned int flags);
    static void* Delete1117360(RouterCleanupDeallocators4TaggedObject* object, unsigned int flags);
    static void* Delete1124460(RouterCleanupDeallocators4TaggedObject* object, unsigned int flags);
    static void* Delete1128640(RouterCleanupDeallocators4TaggedObject* object, unsigned int flags);
    static void* Delete112a8f0(RouterCleanupDeallocators4TaggedObject* object, unsigned int flags);
    static void* Delete112b2b0(RouterCleanupDeallocators4TaggedObject* object, unsigned int flags);
    static void* Delete112e910(RouterCleanupDeallocators4TaggedObject* object, unsigned int flags);
    static void* Delete1151920(RouterCleanupDeallocators4TaggedObject* object, unsigned int flags);
    static void* Delete115a8e0(RouterCleanupDeallocators4TaggedObject* object, unsigned int flags);
};
