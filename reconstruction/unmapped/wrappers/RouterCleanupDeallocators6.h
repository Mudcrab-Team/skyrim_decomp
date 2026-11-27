// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original custom-allocator deleting-destructor template.
// RouterCleanupDeallocators6, Router6, types, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

struct RouterCleanupDeallocators6BlockHeap
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void BlockFree(void* block, int size);
};

struct RouterCleanupDeallocators6MemoryRouter
{
    unsigned char unk00[0x58];
    RouterCleanupDeallocators6BlockHeap* heap;
};

struct RouterCleanupDeallocators6TaggedObject
{
    void* table;
    unsigned short memSizeAndFlags;
};

extern "C" unsigned int RouterTlsSlot325a844;
extern "C" void* (*const TlsGetValueSlot17c8418)(unsigned int slot);
extern "C" void GlobalDeallocTarget1177a80(void* object, unsigned long long size);
extern "C" void CleanupTargetbb2a90(void* object);
extern "C" void CleanupTargetbb30c0(void* object);
extern "C" void CleanupTargetbb6a60(void* object);
extern "C" void CleanupTargetbb7eb0(void* object);
extern "C" void CleanupTargetbbac30(void* object);
extern "C" void CleanupTargetbbae40(void* object);
extern "C" void CleanupTargetbbcf30(void* object);
extern "C" void CleanupTargetbeca60(void* object);
extern "C" void CleanupTargetbf36d0(void* object);
extern "C" void CleanupTargetbf5e50(void* object);
extern "C" void CleanupTargetbf67b0(void* object);
extern "C" void CleanupTargetbfb0e0(void* object);
extern "C" void CleanupTargetbfb190(void* object);
extern "C" void CleanupTargetbfb450(void* object);
extern "C" void CleanupTargetbfbec0(void* object);
extern "C" void CleanupTargetbfd3f0(void* object);
extern "C" void CleanupTargetbfec00(void* object);
extern "C" void CleanupTargetc07d00(void* object);
extern "C" void CleanupTargetc1eed0(void* object);
extern "C" void CleanupTargetc28660(void* object);
extern "C" void CleanupTargetc28e20(void* object);
extern "C" void CleanupTargetc28fa0(void* object);
extern "C" void CleanupTargetc293b0(void* object);
extern "C" void CleanupTargetc2a550(void* object);
extern "C" void CleanupTargetc2a780(void* object);
extern "C" void CleanupTargetc35610(void* object);
extern "C" void CleanupTargetc3ab10(void* object);
extern "C" void CleanupTargetc3d1f0(void* object);
extern "C" void CleanupTargetc41450(void* object);
extern "C" void CleanupTargetc42270(void* object);
extern "C" void CleanupTargetc47bf0(void* object);
extern "C" void CleanupTargetc47c90(void* object);
extern "C" void CleanupTargetc47d30(void* object);
extern "C" void CleanupTargetc47db0(void* object);
extern "C" void CleanupTargetc47ed0(void* object);
extern "C" void CleanupTargetc47f70(void* object);
extern "C" void CleanupTargetc48050(void* object);
extern "C" void CleanupTargetc480e0(void* object);
extern "C" void CleanupTargetc48180(void* object);
extern "C" void CleanupTargetc48250(void* object);
extern "C" void CleanupTargetc4d5b0(void* object);
extern "C" void CleanupTargetc50af0(void* object);
extern "C" void CleanupTargetc50c20(void* object);
extern "C" void CleanupTargetc52460(void* object);
extern "C" void CleanupTargetc52950(void* object);
extern "C" void CleanupTargetc57280(void* object);
extern "C" void CleanupTargetc58cf0(void* object);
extern "C" void CleanupTargetc59eb0(void* object);
extern "C" void CleanupTargetc5b960(void* object);
extern "C" void CleanupTargetc5d850(void* object);
extern "C" void CleanupTargetc5d900(void* object);
extern "C" void CleanupTargetc5d9e0(void* object);
extern "C" void CleanupTargetc5db10(void* object);
extern "C" void CleanupTargetc64040(void* object);
extern "C" void CleanupTargetc6e0e0(void* object);
extern "C" void CleanupTargetc72a30(void* object);
extern "C" void CleanupTargetc75450(void* object);
extern "C" void CleanupTargetca1b20(void* object);
extern "C" void CleanupTargetca1fb0(void* object);
extern "C" void CleanupTargetca2950(void* object);
extern "C" void CleanupTargetca2aa0(void* object);
extern "C" void CleanupTargetca2ff0(void* object);
extern "C" void CleanupTargetca35e0(void* object);
extern "C" void CleanupTargetca40e0(void* object);
extern "C" void CleanupTargetca41f0(void* object);
extern "C" void CleanupTargetca48d0(void* object);
extern "C" void CleanupTargetcb9e50(void* object);
extern "C" void CleanupTargetcba110(void* object);
extern "C" void CleanupTargetcba570(void* object);
extern "C" void CleanupTargetcbf630(void* object);
extern "C" void CleanupTargetcc01b0(void* object);
extern "C" void CleanupTargetcc0580(void* object);
extern "C" void CleanupTargetcc08a0(void* object);
extern "C" void CleanupTarget10a5840(void* object);

struct RouterCleanupDeallocators6
{
    static void* Deletec5e060(RouterCleanupDeallocators6TaggedObject* object, unsigned int flags);
    static void* Deletec5e160(RouterCleanupDeallocators6TaggedObject* object, unsigned int flags);
    static void* Deletec5e2b0(RouterCleanupDeallocators6TaggedObject* object, unsigned int flags);
    static void* Deletec5e330(RouterCleanupDeallocators6TaggedObject* object, unsigned int flags);
};

struct Router6
{
    static void* Deletebb2f50(void* rawObject, unsigned int flags);
    static void* Deletebb3750(void* rawObject, unsigned int flags);
    static void* Deletebb6ad0(void* rawObject, unsigned int flags);
    static void* Deletebb7f20(void* rawObject, unsigned int flags);
    static void* Deletebbace0(void* rawObject, unsigned int flags);
    static void* Deletebbb1f0(void* rawObject, unsigned int flags);
    static void* Deletebbd020(void* rawObject, unsigned int flags);
    static void* Deletebef700(void* rawObject, unsigned int flags);
    static void* Deletebf53e0(void* rawObject, unsigned int flags);
    static void* Deletebf6890(void* rawObject, unsigned int flags);
    static void* Deletebf6910(void* rawObject, unsigned int flags);
    static void* Deletebfb570(void* rawObject, unsigned int flags);
    static void* Deletebfb5f0(void* rawObject, unsigned int flags);
    static void* Deletebfb670(void* rawObject, unsigned int flags);
    static void* Deletebfb870(void* rawObject, unsigned int flags);
    static void* Deletebfb8f0(void* rawObject, unsigned int flags);
    static void* Deletebfb970(void* rawObject, unsigned int flags);
    static void* Deletebfb9f0(void* rawObject, unsigned int flags);
    static void* Deletebfd1c0(void* rawObject, unsigned int flags);
    static void* Deletebfd900(void* rawObject, unsigned int flags);
    static void* Deletec124c0(void* rawObject, unsigned int flags);
    static void* Deletec1efe0(void* rawObject, unsigned int flags);
    static void* Deletec29050(void* rawObject, unsigned int flags);
    static void* Deletec290d0(void* rawObject, unsigned int flags);
    static void* Deletec2a9d0(void* rawObject, unsigned int flags);
    static void* Deletec2aa50(void* rawObject, unsigned int flags);
    static void* Deletec2aad0(void* rawObject, unsigned int flags);
    static void* Deletec2cc30(void* rawObject, unsigned int flags);
    static void* Deletec36320(void* rawObject, unsigned int flags);
    static void* Deletec3c180(void* rawObject, unsigned int flags);
    static void* Deletec3d280(void* rawObject, unsigned int flags);
    static void* Deletec41580(void* rawObject, unsigned int flags);
    static void* Deletec424b0(void* rawObject, unsigned int flags);
    static void* Deletec486a0(void* rawObject, unsigned int flags);
    static void* Deletec48880(void* rawObject, unsigned int flags);
    static void* Deletec48900(void* rawObject, unsigned int flags);
    static void* Deletec48a10(void* rawObject, unsigned int flags);
    static void* Deletec48b60(void* rawObject, unsigned int flags);
    static void* Deletec48be0(void* rawObject, unsigned int flags);
    static void* Deletec48c60(void* rawObject, unsigned int flags);
    static void* Deletec48ce0(void* rawObject, unsigned int flags);
    static void* Deletec48d60(void* rawObject, unsigned int flags);
    static void* Deletec48de0(void* rawObject, unsigned int flags);
    static void* Deletec48e60(void* rawObject, unsigned int flags);
    static void* Deletec48f80(void* rawObject, unsigned int flags);
    static void* Deletec49000(void* rawObject, unsigned int flags);
    static void* Deletec49120(void* rawObject, unsigned int flags);
    static void* Deletec50da0(void* rawObject, unsigned int flags);
    static void* Deletec52b50(void* rawObject, unsigned int flags);
    static void* Deletec56880(void* rawObject, unsigned int flags);
    static void* Deletec58aa0(void* rawObject, unsigned int flags);
    static void* Deletec59ab0(void* rawObject, unsigned int flags);
    static void* Deletec5a4e0(void* rawObject, unsigned int flags);
    static void* Deletec5e910(void* rawObject, unsigned int flags);
    static void* Deletec64860(void* rawObject, unsigned int flags);
    static void* Deletec74620(void* rawObject, unsigned int flags);
    static void* Deletec766b0(void* rawObject, unsigned int flags);
    static void* Deleteca1c30(void* rawObject, unsigned int flags);
    static void* Deleteca29f0(void* rawObject, unsigned int flags);
    static void* Deleteca3680(void* rawObject, unsigned int flags);
    static void* Deleteca4150(void* rawObject, unsigned int flags);
    static void* Deleteca4660(void* rawObject, unsigned int flags);
    static void* Deletecba350(void* rawObject, unsigned int flags);
    static void* Deletecba450(void* rawObject, unsigned int flags);
    static void* Deletecba7d0(void* rawObject, unsigned int flags);
    static void* Deletecc0090(void* rawObject, unsigned int flags);
    static void* Deletecc03f0(void* rawObject, unsigned int flags);
    static void* Deletecc0770(void* rawObject, unsigned int flags);
    static void* Deletecc0bf0(void* rawObject, unsigned int flags);
    static void* Deletecc1920(void* rawObject, unsigned int flags);
    static void* Delete10a5f30(void* rawObject, unsigned int flags);
};
