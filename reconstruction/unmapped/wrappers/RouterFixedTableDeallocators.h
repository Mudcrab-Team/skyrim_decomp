// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original custom-allocator deleting-destructor template.
// RouterFixedTableDeallocators, types, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

struct RouterFixedTableDeallocatorsBlockHeap
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void BlockFree(void* block, int size);
};

struct RouterFixedTableDeallocatorsMemoryRouter
{
    unsigned char unk00[0x58];
    RouterFixedTableDeallocatorsBlockHeap* heap;
};

struct RouterFixedTableDeallocatorsTableObject
{
    void* table;
};

extern "C" unsigned int RouterTlsSlot325a844;
extern "C" void* (*const TlsGetValueSlot17c8418)(unsigned int slot);
extern "C" void GlobalDeallocTarget1177a80(void* object, unsigned long long size);
extern "C" unsigned char TableTarget17fde30[];
extern "C" unsigned char TableTarget1867170[];
extern "C" unsigned char TableTarget1867d68[];
extern "C" unsigned char TableTarget19c1168[];
extern "C" unsigned char TableTarget19e6638[];
extern "C" unsigned char TableTarget19e6b78[];
extern "C" unsigned char TableTarget19f2798[];
extern "C" unsigned char TableTarget19f4ed8[];
extern "C" unsigned char TableTarget19f4ef8[];
extern "C" unsigned char TableTarget19f5f20[];
extern "C" unsigned char TableTarget1a126a8[];
extern "C" unsigned char TableTarget1a97e28[];
extern "C" unsigned char TableTarget1a98488[];
extern "C" unsigned char TableTarget1a98538[];
extern "C" unsigned char TableTarget1a98ee8[];
extern "C" unsigned char TableTarget1a98f28[];
extern "C" unsigned char TableTarget1a990a8[];
extern "C" unsigned char TableTarget1a995f8[];

struct RouterFixedTableDeallocators
{
    static void* Deleteadbc70(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Deleteadbcd0(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Deleteadbfc0(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Deleteb34180(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Deleteb36eb0(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Deleteb51dd0(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Deleteb5cc70(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Deleteb5cd50(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Deleteb5cdb0(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Deleteb7cf70(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Deletec41520(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Deletec7b8c0(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Deletec7b920(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Deletec7b980(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Deletec7b9e0(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Delete10dd230(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Delete10dd290(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Delete10dd2f0(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Delete1106d30(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Delete1123f20(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Delete1124400(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Delete1126710(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Delete1150f40(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Delete11514a0(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Delete1151500(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Delete1151620(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Delete1151860(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Delete11518c0(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags);
    static void* Delete1166af0(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags);
};
