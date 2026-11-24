// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original custom-allocator deleting-destructor template.
// RouterRefMemberDeallocators, types, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

struct RouterRefMemberDeallocatorsBlockHeap
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void BlockFree(void* block, int size);
};

struct RouterRefMemberDeallocatorsMemoryRouter
{
    unsigned char unk00[0x58];
    RouterRefMemberDeallocatorsBlockHeap* heap;
};

struct RouterRefMemberDeallocatorsRefMemberObject38_50
{
    void* table;
    unsigned short memSizeAndFlags;
    unsigned char unk0a[0x2e];
    unsigned char member38[0x18];
    void* refObj;
};

struct RouterRefMemberDeallocatorsRefMemberObject38_58
{
    void* table;
    unsigned short memSizeAndFlags;
    unsigned char unk0a[0x2e];
    unsigned char member38[0x20];
    void* refObj;
};

struct RouterRefMemberDeallocatorsRefMemberObject38_60
{
    void* table;
    unsigned short memSizeAndFlags;
    unsigned char unk0a[0x2e];
    unsigned char member38[0x28];
    void* refObj;
};

struct RouterRefMemberDeallocatorsRefMemberObject38_70
{
    void* table;
    unsigned short memSizeAndFlags;
    unsigned char unk0a[0x2e];
    unsigned char member38[0x38];
    void* refObj;
};

struct RouterRefMemberDeallocatorsRefMemberObject38_88
{
    void* table;
    unsigned short memSizeAndFlags;
    unsigned char unk0a[0x2e];
    unsigned char member38[0x50];
    void* refObj;
};

struct RouterRefMemberDeallocatorsRefMemberObject38_90
{
    void* table;
    unsigned short memSizeAndFlags;
    unsigned char unk0a[0x2e];
    unsigned char member38[0x58];
    void* refObj;
};

struct RouterRefMemberDeallocatorsRefMemberObject38_f8
{
    void* table;
    unsigned short memSizeAndFlags;
    unsigned char unk0a[0x2e];
    unsigned char member38[0xc0];
    void* refObj;
};

extern "C" unsigned int RouterTlsSlot325a844;
extern "C" void* (*const TlsGetValueSlot17c8418)(unsigned int slot);
extern "C" void GlobalDeallocTarget1177a80(void* object, unsigned long long size);
extern "C" void CleanupTargetaa2770(void* object);
extern "C" void CleanupTargetaa77d0(void* object);
extern "C" void CleanupTargetad1a70(void* object);

struct RouterRefMemberDeallocators
{
    static void* Deleteae2be0(RouterRefMemberDeallocatorsRefMemberObject38_50* object, unsigned int flags);
    static void* Deleteae2d10(RouterRefMemberDeallocatorsRefMemberObject38_58* object, unsigned int flags);
    static void* Deleteae3030(RouterRefMemberDeallocatorsRefMemberObject38_50* object, unsigned int flags);
    static void* Deleteae3890(RouterRefMemberDeallocatorsRefMemberObject38_50* object, unsigned int flags);
    static void* Deleteae4640(RouterRefMemberDeallocatorsRefMemberObject38_50* object, unsigned int flags);
    static void* Deleteae4ca0(RouterRefMemberDeallocatorsRefMemberObject38_f8* object, unsigned int flags);
    static void* Deleteae4fe0(RouterRefMemberDeallocatorsRefMemberObject38_90* object, unsigned int flags);
    static void* Deleteae5700(RouterRefMemberDeallocatorsRefMemberObject38_60* object, unsigned int flags);
    static void* Deletebb6ee0(RouterRefMemberDeallocatorsRefMemberObject38_70* object, unsigned int flags);
    static void* Deletebb77a0(RouterRefMemberDeallocatorsRefMemberObject38_58* object, unsigned int flags);
    static void* Deletebbb840(RouterRefMemberDeallocatorsRefMemberObject38_88* object, unsigned int flags);
    static void* Deletebbbf00(RouterRefMemberDeallocatorsRefMemberObject38_60* object, unsigned int flags);
};
