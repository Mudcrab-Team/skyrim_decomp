// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original custom-allocator deleting-destructor template.
// RouterTableDeallocators, types, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

struct RouterTableDeallocatorsBlockHeap
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void BlockFree(void* block, int size);
};

struct RouterTableDeallocatorsMemoryRouter
{
    unsigned char unk00[0x58];
    RouterTableDeallocatorsBlockHeap* heap;
};

struct RouterTableDeallocatorsTaggedObject
{
    void* table;
    unsigned short memSizeAndFlags;
};

extern "C" unsigned int RouterTlsSlot325a844;
extern "C" void* (*const TlsGetValueSlot17c8418)(unsigned int slot);
extern "C" void GlobalDeallocTarget1177a80(void* object, unsigned long long size);
extern "C" unsigned char TableTarget1820b98[];
extern "C" unsigned char TableTarget1a173a0[];

struct RouterTableDeallocators
{
    static void* Deleteb2e680(RouterTableDeallocatorsTaggedObject* object, unsigned int flags);
    static void* Deleteb2ea20(RouterTableDeallocatorsTaggedObject* object, unsigned int flags);
    static void* Deleteb2eaa0(RouterTableDeallocatorsTaggedObject* object, unsigned int flags);
    static void* Deleteb32590(RouterTableDeallocatorsTaggedObject* object, unsigned int flags);
    static void* Deleteb34000(RouterTableDeallocatorsTaggedObject* object, unsigned int flags);
    static void* Deleteb34080(RouterTableDeallocatorsTaggedObject* object, unsigned int flags);
    static void* Deleteb34100(RouterTableDeallocatorsTaggedObject* object, unsigned int flags);
    static void* Deletebafbb0(RouterTableDeallocatorsTaggedObject* object, unsigned int flags);
    static void* Deletebb1a80(RouterTableDeallocatorsTaggedObject* object, unsigned int flags);
    static void* Deletec2ba90(RouterTableDeallocatorsTaggedObject* object, unsigned int flags);
    static void* Deletec2bb10(RouterTableDeallocatorsTaggedObject* object, unsigned int flags);
    static void* Deletec2bb90(RouterTableDeallocatorsTaggedObject* object, unsigned int flags);
    static void* Deletec2bc10(RouterTableDeallocatorsTaggedObject* object, unsigned int flags);
    static void* Deletec2bc90(RouterTableDeallocatorsTaggedObject* object, unsigned int flags);
    static void* Deletec2bd10(RouterTableDeallocatorsTaggedObject* object, unsigned int flags);
    static void* Deletec2bd90(RouterTableDeallocatorsTaggedObject* object, unsigned int flags);
    static void* Deletec3d300(RouterTableDeallocatorsTaggedObject* object, unsigned int flags);
    static void* Deletec5b7f0(RouterTableDeallocatorsTaggedObject* object, unsigned int flags);
    static void* Deletec5e0e0(RouterTableDeallocatorsTaggedObject* object, unsigned int flags);
    static void* Deletec5e480(RouterTableDeallocatorsTaggedObject* object, unsigned int flags);
    static void* Deletec5e500(RouterTableDeallocatorsTaggedObject* object, unsigned int flags);
    static void* Deletec5e650(RouterTableDeallocatorsTaggedObject* object, unsigned int flags);
    static void* Deletec5e790(RouterTableDeallocatorsTaggedObject* object, unsigned int flags);
    static void* Deletec5e810(RouterTableDeallocatorsTaggedObject* object, unsigned int flags);
    static void* Deletec5e890(RouterTableDeallocatorsTaggedObject* object, unsigned int flags);
    static void* Deletec646e0(RouterTableDeallocatorsTaggedObject* object, unsigned int flags);
    static void* Deletec64760(RouterTableDeallocatorsTaggedObject* object, unsigned int flags);
    static void* Deletec647e0(RouterTableDeallocatorsTaggedObject* object, unsigned int flags);
    static void* Deletec68cd0(RouterTableDeallocatorsTaggedObject* object, unsigned int flags);
    static void* Deletec76730(RouterTableDeallocatorsTaggedObject* object, unsigned int flags);
    static void* Deletec79280(RouterTableDeallocatorsTaggedObject* object, unsigned int flags);
    static void* Deletecba3d0(RouterTableDeallocatorsTaggedObject* object, unsigned int flags);
};
