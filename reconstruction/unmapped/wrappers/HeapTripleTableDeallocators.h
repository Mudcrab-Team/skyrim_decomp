// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original custom-allocator deleting-destructor template.
// HeapTripleTableDeallocators, types, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

struct HeapTripleTableDeallocatorsGlobalHeap
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

struct HeapTripleTableDeallocatorsTripleTableObject20_68
{
    void* table0;
    unsigned char unk08[0x18];
    void* table1;
    unsigned char unk28[0x40];
    void* table2;
};

struct HeapTripleTableDeallocatorsTripleTableObject20_70
{
    void* table0;
    unsigned char unk08[0x18];
    void* table1;
    unsigned char unk28[0x48];
    void* table2;
};

struct HeapTripleTableDeallocatorsTripleTableObject20_78
{
    void* table0;
    unsigned char unk08[0x18];
    void* table1;
    unsigned char unk28[0x50];
    void* table2;
};

struct HeapTripleTableDeallocatorsTripleTableObject20_88
{
    void* table0;
    unsigned char unk08[0x18];
    void* table1;
    unsigned char unk28[0x60];
    void* table2;
};

struct HeapTripleTableDeallocatorsTripleTableObject20_90
{
    void* table0;
    unsigned char unk08[0x18];
    void* table1;
    unsigned char unk28[0x68];
    void* table2;
};

struct HeapTripleTableDeallocatorsTripleTableObject20_98
{
    void* table0;
    unsigned char unk08[0x18];
    void* table1;
    unsigned char unk28[0x70];
    void* table2;
};

extern "C" HeapTripleTableDeallocatorsGlobalHeap* GlobalHeapSlot3275ae0;
extern "C" void GlobalDeallocTarget1177a80(void* object, unsigned long long size);
extern "C" void CleanupTargetd116d0(void* object);
extern "C" void CleanupTargetd11840(void* object);
extern "C" void CleanupTargetd6b0d0(void* object);
extern "C" void CleanupTargetdaa660(void* object);
extern "C" void CleanupTargetdccc40(void* object);
extern "C" unsigned char TableTarget1a28148[];
extern "C" unsigned char TableTarget1a28190[];
extern "C" unsigned char TableTarget1a28238[];
extern "C" unsigned char TableTarget1a2c760[];
extern "C" unsigned char TableTarget1a2c7a8[];
extern "C" unsigned char TableTarget1a2c850[];
extern "C" unsigned char TableTarget1a2e9e0[];
extern "C" unsigned char TableTarget1a2ea28[];
extern "C" unsigned char TableTarget1a2ead0[];
extern "C" unsigned char TableTarget1a30ee8[];
extern "C" unsigned char TableTarget1a30f30[];
extern "C" unsigned char TableTarget1a30fd8[];
extern "C" unsigned char TableTarget1a31360[];
extern "C" unsigned char TableTarget1a313a8[];
extern "C" unsigned char TableTarget1a31450[];
extern "C" unsigned char TableTarget1a31a40[];
extern "C" unsigned char TableTarget1a31a88[];
extern "C" unsigned char TableTarget1a31b30[];
extern "C" unsigned char TableTarget1a31ea0[];
extern "C" unsigned char TableTarget1a31ee8[];
extern "C" unsigned char TableTarget1a31f90[];
extern "C" unsigned char TableTarget1a328c8[];
extern "C" unsigned char TableTarget1a32910[];
extern "C" unsigned char TableTarget1a329b8[];
extern "C" unsigned char TableTarget1a32d90[];
extern "C" unsigned char TableTarget1a32dd8[];
extern "C" unsigned char TableTarget1a32e80[];
extern "C" unsigned char TableTarget1a33d30[];
extern "C" unsigned char TableTarget1a33d78[];
extern "C" unsigned char TableTarget1a33e20[];
extern "C" unsigned char TableTarget1a342a8[];
extern "C" unsigned char TableTarget1a342f0[];
extern "C" unsigned char TableTarget1a34398[];
extern "C" unsigned char TableTarget1a347b0[];
extern "C" unsigned char TableTarget1a347f8[];
extern "C" unsigned char TableTarget1a348a0[];
extern "C" unsigned char TableTarget1a35148[];
extern "C" unsigned char TableTarget1a35190[];
extern "C" unsigned char TableTarget1a35238[];
extern "C" unsigned char TableTarget1a356c0[];
extern "C" unsigned char TableTarget1a35708[];
extern "C" unsigned char TableTarget1a357b0[];
extern "C" unsigned char TableTarget1a35cb0[];
extern "C" unsigned char TableTarget1a35cf8[];
extern "C" unsigned char TableTarget1a35da0[];
extern "C" unsigned char TableTarget1a36280[];
extern "C" unsigned char TableTarget1a362c8[];
extern "C" unsigned char TableTarget1a36370[];
extern "C" unsigned char TableTarget1a36850[];
extern "C" unsigned char TableTarget1a36898[];
extern "C" unsigned char TableTarget1a36940[];
extern "C" unsigned char TableTarget1a36e48[];
extern "C" unsigned char TableTarget1a36e90[];
extern "C" unsigned char TableTarget1a36f38[];
extern "C" unsigned char TableTarget1a37858[];
extern "C" unsigned char TableTarget1a378a0[];
extern "C" unsigned char TableTarget1a37948[];
extern "C" unsigned char TableTarget1a385d0[];
extern "C" unsigned char TableTarget1a38618[];
extern "C" unsigned char TableTarget1a386c0[];

struct HeapTripleTableDeallocators
{
    static void* Deleted11b80(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags);
    static void* Deleted11d70(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags);
    static void* Deleted6b220(HeapTripleTableDeallocatorsTripleTableObject20_98* object, unsigned int flags);
    static void* Deleted6b370(HeapTripleTableDeallocatorsTripleTableObject20_98* object, unsigned int flags);
    static void* Deleted876e0(HeapTripleTableDeallocatorsTripleTableObject20_78* object, unsigned int flags);
    static void* Deleted87830(HeapTripleTableDeallocatorsTripleTableObject20_78* object, unsigned int flags);
    static void* Deleteda27c0(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags);
    static void* Deleteda2910(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags);
    static void* Deleteda4d10(HeapTripleTableDeallocatorsTripleTableObject20_88* object, unsigned int flags);
    static void* Deleteda4e60(HeapTripleTableDeallocatorsTripleTableObject20_88* object, unsigned int flags);
    static void* Deleteda8350(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags);
    static void* Deleteda84a0(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags);
    static void* Deletedaa750(HeapTripleTableDeallocatorsTripleTableObject20_90* object, unsigned int flags);
    static void* Deletedaa8a0(HeapTripleTableDeallocatorsTripleTableObject20_90* object, unsigned int flags);
    static void* Deletedaecf0(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags);
    static void* Deletedaee40(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags);
    static void* Deletedb0340(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags);
    static void* Deletedb0490(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags);
    static void* Deletedb5ee0(HeapTripleTableDeallocatorsTripleTableObject20_70* object, unsigned int flags);
    static void* Deletedb6030(HeapTripleTableDeallocatorsTripleTableObject20_70* object, unsigned int flags);
    static void* Deletedb79b0(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags);
    static void* Deletedb7b00(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags);
    static void* Deletedb8ba0(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags);
    static void* Deletedb8cf0(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags);
    static void* Deletedbce40(HeapTripleTableDeallocatorsTripleTableObject20_98* object, unsigned int flags);
    static void* Deletedbcf90(HeapTripleTableDeallocatorsTripleTableObject20_98* object, unsigned int flags);
    static void* Deletedbef50(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags);
    static void* Deletedbf0b0(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags);
    static void* Deletedbff90(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags);
    static void* Deletedc0180(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags);
    static void* Deletedc2810(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags);
    static void* Deletedc2960(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags);
    static void* Deletedc3f00(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags);
    static void* Deletedc4050(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags);
    static void* Deletedc6a30(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags);
    static void* Deletedc6b80(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags);
    static void* Deletedcce30(HeapTripleTableDeallocatorsTripleTableObject20_78* object, unsigned int flags);
    static void* Deletedcd0d0(HeapTripleTableDeallocatorsTripleTableObject20_78* object, unsigned int flags);
    static void* Deletedd1a00(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags);
    static void* Deletedd1b50(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags);
};
