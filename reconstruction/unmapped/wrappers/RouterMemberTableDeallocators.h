// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original custom-allocator deleting-destructor template.
// RouterMemberTableDeallocators, types, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

struct RouterMemberTableDeallocatorsBlockHeap
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void BlockFree(void* block, int size);
};

struct RouterMemberTableDeallocatorsMemoryRouter
{
    unsigned char unk00[0x58];
    RouterMemberTableDeallocatorsBlockHeap* heap;
};

struct RouterMemberTableDeallocatorsMemberObject10
{
    void* table;
    unsigned short memSizeAndFlags;
    unsigned char unk0a[0x6];
    unsigned char member10[1];
};

struct RouterMemberTableDeallocatorsMemberObject18
{
    void* table;
    unsigned short memSizeAndFlags;
    unsigned char unk0a[0xe];
    unsigned char member18[1];
};

struct RouterMemberTableDeallocatorsMemberObject20
{
    void* table;
    unsigned short memSizeAndFlags;
    unsigned char unk0a[0x16];
    unsigned char member20[1];
};

extern "C" unsigned int RouterTlsSlot325a844;
extern "C" void* (*const TlsGetValueSlot17c8418)(unsigned int slot);
extern "C" void GlobalDeallocTarget1177a80(void* object, unsigned long long size);
extern "C" void CleanupTargetaa77d0(void* object);
extern "C" void CleanupTargetab55b0(void* object);
extern "C" void CleanupTargetcc08a0(void* object);
extern "C" unsigned char TableTarget1820b98[];

struct RouterMemberTableDeallocators
{
    static void* Deleteaaa370(RouterMemberTableDeallocatorsMemberObject10* object, unsigned int flags);
    static void* Deleteae4800(RouterMemberTableDeallocatorsMemberObject10* object, unsigned int flags);
    static void* Deleteae4890(RouterMemberTableDeallocatorsMemberObject10* object, unsigned int flags);
    static void* Deleteae4920(RouterMemberTableDeallocatorsMemberObject10* object, unsigned int flags);
    static void* Deleteae55e0(RouterMemberTableDeallocatorsMemberObject10* object, unsigned int flags);
    static void* Deleteae5670(RouterMemberTableDeallocatorsMemberObject10* object, unsigned int flags);
    static void* Deleteb2e460(RouterMemberTableDeallocatorsMemberObject18* object, unsigned int flags);
    static void* Deleteb2e700(RouterMemberTableDeallocatorsMemberObject18* object, unsigned int flags);
    static void* Deleteb2eb20(RouterMemberTableDeallocatorsMemberObject10* object, unsigned int flags);
    static void* Deleteca1d40(RouterMemberTableDeallocatorsMemberObject20* object, unsigned int flags);
    static void* Deletecc8180(RouterMemberTableDeallocatorsMemberObject10* object, unsigned int flags);
    static void* Delete10d1d00(RouterMemberTableDeallocatorsMemberObject18* object, unsigned int flags);
    static void* Delete10d2320(RouterMemberTableDeallocatorsMemberObject18* object, unsigned int flags);
};
