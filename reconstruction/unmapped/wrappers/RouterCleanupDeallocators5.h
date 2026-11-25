// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original custom-allocator deleting-destructor template.
// RouterCleanupDeallocators5, Router5, types, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

struct RouterCleanupDeallocators5BlockHeap
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void BlockFree(void* block, int size);
};

struct RouterCleanupDeallocators5MemoryRouter
{
    unsigned char unk00[0x58];
    RouterCleanupDeallocators5BlockHeap* heap;
};

struct RouterCleanupDeallocators5TaggedObject
{
    void* table;
    unsigned short memSizeAndFlags;
};

extern "C" unsigned int RouterTlsSlot325a844;
extern "C" void* (*const TlsGetValueSlot17c8418)(unsigned int slot);
extern "C" void GlobalDeallocTarget1177a80(void* object, unsigned long long size);
extern "C" void CleanupTargetb36b80(void* object);
extern "C" void CleanupTargetb374f0(void* object);
extern "C" void CleanupTargetb3c0d0(void* object);
extern "C" void CleanupTargetb3d9a0(void* object);
extern "C" void CleanupTargetb3da40(void* object);
extern "C" void CleanupTargetb3fa90(void* object);
extern "C" void CleanupTargetb40100(void* object);
extern "C" void CleanupTargetb40e10(void* object);
extern "C" void CleanupTargetb41370(void* object);
extern "C" void CleanupTargetb45150(void* object);
extern "C" void CleanupTargetb46df0(void* object);
extern "C" void CleanupTargetb4a430(void* object);
extern "C" void CleanupTargetb4a990(void* object);
extern "C" void CleanupTargetb4c240(void* object);
extern "C" void CleanupTargetb4cbb0(void* object);
extern "C" void CleanupTargetb4e440(void* object);
extern "C" void CleanupTargetb4f880(void* object);
extern "C" void CleanupTargetb50130(void* object);
extern "C" void CleanupTargetb517f0(void* object);
extern "C" void CleanupTargetb5b5e0(void* object);
extern "C" void CleanupTargetb5c710(void* object);
extern "C" void CleanupTargetb622c0(void* object);
extern "C" void CleanupTargetb63740(void* object);
extern "C" void CleanupTargetb64520(void* object);
extern "C" void CleanupTargetb65010(void* object);
extern "C" void CleanupTargetb660e0(void* object);
extern "C" void CleanupTargetb66fd0(void* object);
extern "C" void CleanupTargetb6ccd0(void* object);
extern "C" void CleanupTargetb6f4f0(void* object);
extern "C" void CleanupTargetb70a50(void* object);
extern "C" void CleanupTargetb71850(void* object);
extern "C" void CleanupTargetb73710(void* object);
extern "C" void CleanupTargetb76080(void* object);
extern "C" void CleanupTargetb768a0(void* object);
extern "C" void CleanupTargetb77ce0(void* object);
extern "C" void CleanupTargetb78480(void* object);
extern "C" void CleanupTargetb787f0(void* object);
extern "C" void CleanupTargetb79ae0(void* object);
extern "C" void CleanupTargetb7a420(void* object);
extern "C" void CleanupTargetb7bb50(void* object);
extern "C" void CleanupTargetb7c950(void* object);
extern "C" void CleanupTargetb7d2c0(void* object);
extern "C" void CleanupTargetb7ded0(void* object);
extern "C" void CleanupTargetb7e560(void* object);
extern "C" void CleanupTargetb8d9d0(void* object);
extern "C" void CleanupTargetb97840(void* object);
extern "C" void CleanupTargetb97b50(void* object);
extern "C" void CleanupTargetb9ba00(void* object);
extern "C" void CleanupTargetb9bab0(void* object);
extern "C" void CleanupTargetb9bbb0(void* object);
extern "C" void CleanupTargetba1a90(void* object);
extern "C" void CleanupTargetba3cb0(void* object);
extern "C" void CleanupTargetba49e0(void* object);
extern "C" void CleanupTargetba56a0(void* object);
extern "C" void CleanupTargetba5b10(void* object);
extern "C" void CleanupTargetba6510(void* object);
extern "C" void CleanupTargetba68b0(void* object);
extern "C" void CleanupTargetba69d0(void* object);
extern "C" void CleanupTargetba6b20(void* object);
extern "C" void CleanupTargetba70a0(void* object);
extern "C" void CleanupTargetba8760(void* object);
extern "C" void CleanupTargetba8c70(void* object);
extern "C" void CleanupTargetbb0810(void* object);
extern "C" void CleanupTargetbb1e40(void* object);
extern "C" void CleanupTargetc2e4f0(void* object);

struct RouterCleanupDeallocators5
{
};

struct Router5
{
    static void* Deleteb36e30(void* rawObject, unsigned int flags);
    static void* Deleteb37500(void* rawObject, unsigned int flags);
    static void* Deleteb3c530(void* rawObject, unsigned int flags);
    static void* Deleteb3dcb0(void* rawObject, unsigned int flags);
    static void* Deleteb3dd30(void* rawObject, unsigned int flags);
    static void* Deleteb3df10(void* rawObject, unsigned int flags);
    static void* Deleteb3e040(void* rawObject, unsigned int flags);
    static void* Deleteb3e250(void* rawObject, unsigned int flags);
    static void* Deleteb3e2d0(void* rawObject, unsigned int flags);
    static void* Deleteb3f4a0(void* rawObject, unsigned int flags);
    static void* Deleteb3f720(void* rawObject, unsigned int flags);
    static void* Deleteb40b30(void* rawObject, unsigned int flags);
    static void* Deleteb410b0(void* rawObject, unsigned int flags);
    static void* Deleteb4c440(void* rawObject, unsigned int flags);
    static void* Deleteb4c4c0(void* rawObject, unsigned int flags);
    static void* Deleteb4c540(void* rawObject, unsigned int flags);
    static void* Deleteb4c5c0(void* rawObject, unsigned int flags);
    static void* Deleteb4c7f0(void* rawObject, unsigned int flags);
    static void* Deleteb4de10(void* rawObject, unsigned int flags);
    static void* Deleteb4f180(void* rawObject, unsigned int flags);
    static void* Deleteb4f200(void* rawObject, unsigned int flags);
    static void* Deleteb4ffa0(void* rawObject, unsigned int flags);
    static void* Deleteb50350(void* rawObject, unsigned int flags);
    static void* Deleteb51a10(void* rawObject, unsigned int flags);
    static void* Deleteb51bb0(void* rawObject, unsigned int flags);
    static void* Deleteb51cd0(void* rawObject, unsigned int flags);
    static void* Deleteb51d50(void* rawObject, unsigned int flags);
    static void* Deleteb52100(void* rawObject, unsigned int flags);
    static void* Deleteb52180(void* rawObject, unsigned int flags);
    static void* Deleteb52200(void* rawObject, unsigned int flags);
    static void* Deleteb52310(void* rawObject, unsigned int flags);
    static void* Deleteb52390(void* rawObject, unsigned int flags);
    static void* Deleteb52650(void* rawObject, unsigned int flags);
    static void* Deleteb527f0(void* rawObject, unsigned int flags);
    static void* Deleteb52870(void* rawObject, unsigned int flags);
    static void* Deleteb528f0(void* rawObject, unsigned int flags);
    static void* Deleteb5ccd0(void* rawObject, unsigned int flags);
    static void* Deleteb767a0(void* rawObject, unsigned int flags);
    static void* Deleteb76dd0(void* rawObject, unsigned int flags);
    static void* Deleteb78310(void* rawObject, unsigned int flags);
    static void* Deleteb79730(void* rawObject, unsigned int flags);
    static void* Deleteb79d60(void* rawObject, unsigned int flags);
    static void* Deleteb7c190(void* rawObject, unsigned int flags);
    static void* Deleteb7cef0(void* rawObject, unsigned int flags);
    static void* Deleteb7e090(void* rawObject, unsigned int flags);
    static void* Deleteb7e110(void* rawObject, unsigned int flags);
    static void* Deleteb7ec80(void* rawObject, unsigned int flags);
    static void* Deleteb81be0(void* rawObject, unsigned int flags);
    static void* Deleteb8daa0(void* rawObject, unsigned int flags);
    static void* Deleteb97ad0(void* rawObject, unsigned int flags);
    static void* Deleteb983d0(void* rawObject, unsigned int flags);
    static void* Deleteb9bd00(void* rawObject, unsigned int flags);
    static void* Deleteb9be30(void* rawObject, unsigned int flags);
    static void* Deleteb9beb0(void* rawObject, unsigned int flags);
    static void* Deleteb9bfc0(void* rawObject, unsigned int flags);
    static void* Deleteb9c040(void* rawObject, unsigned int flags);
    static void* Deleteb9c0c0(void* rawObject, unsigned int flags);
    static void* Deleteb9c140(void* rawObject, unsigned int flags);
    static void* Deleteb9c280(void* rawObject, unsigned int flags);
    static void* Deleteb9c300(void* rawObject, unsigned int flags);
    static void* Deleteb9c380(void* rawObject, unsigned int flags);
    static void* Deleteb9c400(void* rawObject, unsigned int flags);
    static void* Deleteb9c480(void* rawObject, unsigned int flags);
    static void* Deleteb9c500(void* rawObject, unsigned int flags);
    static void* Deleteb9c610(void* rawObject, unsigned int flags);
    static void* Deleteb9c690(void* rawObject, unsigned int flags);
    static void* Deleteb9c710(void* rawObject, unsigned int flags);
    static void* Deleteba4880(void* rawObject, unsigned int flags);
    static void* Deleteba6ec0(void* rawObject, unsigned int flags);
    static void* Deleteba75c0(void* rawObject, unsigned int flags);
    static void* Deleteba8690(void* rawObject, unsigned int flags);
    static void* Deleteba9060(void* rawObject, unsigned int flags);
    static void* Deleteba90e0(void* rawObject, unsigned int flags);
    static void* Deletebb1a00(void* rawObject, unsigned int flags);
    static void* Deletebb28d0(void* rawObject, unsigned int flags);
};
