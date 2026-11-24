// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original custom-allocator deleting-destructor template.
// RouterMemberCleanupDeallocators, types, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

struct RouterMemberCleanupDeallocatorsBlockHeap
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void BlockFree(void* block, int size);
};

struct RouterMemberCleanupDeallocatorsMemoryRouter
{
    unsigned char unk00[0x58];
    RouterMemberCleanupDeallocatorsBlockHeap* heap;
};

struct RouterMemberCleanupDeallocatorsMemberObject38
{
    void* table;
    unsigned short memSizeAndFlags;
    unsigned char unk0a[0x2e];
    unsigned char member38[1];
};

extern "C" unsigned int RouterTlsSlot325a844;
extern "C" void* (*const TlsGetValueSlot17c8418)(unsigned int slot);
extern "C" void GlobalDeallocTarget1177a80(void* object, unsigned long long size);
extern "C" void CleanupTargetaa77d0(void* object);
extern "C" void CleanupTargetad1a70(void* object);

struct RouterMemberCleanupDeallocators
{
    static void* Deletead1d70(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags);
    static void* Deletead1e00(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags);
    static void* Deleteae2240(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags);
    static void* Deleteae2530(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags);
    static void* Deleteae26d0(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags);
    static void* Deleteae27f0(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags);
    static void* Deleteae2910(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags);
    static void* Deleteae2ac0(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags);
    static void* Deleteae3630(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags);
    static void* Deleteae3a70(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags);
    static void* Deleteae3b90(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags);
    static void* Deleteae40f0(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags);
    static void* Deleteae4320(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags);
    static void* Deleteae4470(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags);
    static void* Deleteae46e0(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags);
    static void* Deleteae4eb0(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags);
    static void* Deleteae5090(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags);
    static void* Deleteae5440(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags);
    static void* Deleteae5830(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags);
    static void* Deleteae5950(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags);
    static void* Deletebb5920(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags);
    static void* Deletebb6280(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags);
    static void* Deletebb64e0(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags);
    static void* Deletebb8130(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags);
    static void* Deletebb83e0(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags);
    static void* Deletebb86c0(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags);
    static void* Deletebb9b20(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags);
    static void* Deletebbbb40(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags);
    static void* Deletebbc4c0(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags);
};
