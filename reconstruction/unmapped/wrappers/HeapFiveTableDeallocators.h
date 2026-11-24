// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original custom-allocator deleting-destructor template.
// HeapFiveTableDeallocators, types, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

struct HeapFiveTableDeallocatorsGlobalHeap
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

struct HeapFiveTableDeallocatorsTripleTableObject20_108
{
    void* table0;
    unsigned char unk08[0x18];
    void* table1;
    unsigned char unk28[0xe0];
    void* table2;
};

extern "C" HeapFiveTableDeallocatorsGlobalHeap* GlobalHeapSlot3275ae0;
extern "C" void GlobalDeallocTarget1177a80(void* object, unsigned long long size);
extern "C" void CleanupTargetd116d0(void* object);
extern "C" void CleanupTargetd11840(void* object);
extern "C" void CleanupTargetddd750(void* object);
extern "C" unsigned char TableTarget1a399a8[];
extern "C" unsigned char TableTarget1a399f0[];
extern "C" unsigned char TableTarget1a39a98[];
extern "C" unsigned char TableTarget1a39ae0[];
extern "C" unsigned char TableTarget1a39b88[];
extern "C" unsigned char TableTarget1a39dd8[];
extern "C" unsigned char TableTarget1a39e20[];
extern "C" unsigned char TableTarget1a39ec8[];
extern "C" unsigned char TableTarget1a39f10[];
extern "C" unsigned char TableTarget1a39fb8[];
extern "C" unsigned char TableTarget1a3a248[];
extern "C" unsigned char TableTarget1a3a290[];
extern "C" unsigned char TableTarget1a3a338[];
extern "C" unsigned char TableTarget1a3a380[];
extern "C" unsigned char TableTarget1a3a428[];
extern "C" unsigned char TableTarget1a3a678[];
extern "C" unsigned char TableTarget1a3a6c0[];
extern "C" unsigned char TableTarget1a3a768[];
extern "C" unsigned char TableTarget1a3a7b0[];
extern "C" unsigned char TableTarget1a3a858[];
extern "C" unsigned char TableTarget1a3aaa8[];
extern "C" unsigned char TableTarget1a3aaf0[];
extern "C" unsigned char TableTarget1a3ab98[];
extern "C" unsigned char TableTarget1a3abe0[];
extern "C" unsigned char TableTarget1a3ac88[];
extern "C" unsigned char TableTarget1a3af00[];
extern "C" unsigned char TableTarget1a3af48[];
extern "C" unsigned char TableTarget1a3aff0[];
extern "C" unsigned char TableTarget1a3b038[];
extern "C" unsigned char TableTarget1a3b0e0[];

struct HeapFiveTableDeallocators
{
    static void* Deleteddd7c0(HeapFiveTableDeallocatorsTripleTableObject20_108* object, unsigned int flags);
    static void* Deleteddd930(HeapFiveTableDeallocatorsTripleTableObject20_108* object, unsigned int flags);
    static void* Deletedde7d0(HeapFiveTableDeallocatorsTripleTableObject20_108* object, unsigned int flags);
    static void* Deletedde940(HeapFiveTableDeallocatorsTripleTableObject20_108* object, unsigned int flags);
    static void* Deletede0620(HeapFiveTableDeallocatorsTripleTableObject20_108* object, unsigned int flags);
    static void* Deletede0790(HeapFiveTableDeallocatorsTripleTableObject20_108* object, unsigned int flags);
    static void* Deletede1fe0(HeapFiveTableDeallocatorsTripleTableObject20_108* object, unsigned int flags);
    static void* Deletede2150(HeapFiveTableDeallocatorsTripleTableObject20_108* object, unsigned int flags);
    static void* Deletede3300(HeapFiveTableDeallocatorsTripleTableObject20_108* object, unsigned int flags);
    static void* Deletede3470(HeapFiveTableDeallocatorsTripleTableObject20_108* object, unsigned int flags);
    static void* Deletede52e0(HeapFiveTableDeallocatorsTripleTableObject20_108* object, unsigned int flags);
    static void* Deletede5450(HeapFiveTableDeallocatorsTripleTableObject20_108* object, unsigned int flags);
};
