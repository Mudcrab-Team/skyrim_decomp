// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original custom-allocator deleting-destructor template.
// HeapCleanupDeallocators2, types, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

struct HeapCleanupDeallocators2GlobalHeap
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

extern "C" HeapCleanupDeallocators2GlobalHeap* GlobalHeapSlot3275ae0;
extern "C" void GlobalDeallocTarget1177a80(void* object, unsigned long long size);
extern "C" void CleanupTargetcf3100(void* object);
extern "C" void CleanupTargetd116d0(void* object);
extern "C" void CleanupTargetd163b0(void* object);
extern "C" void CleanupTargetdac510(void* object);
extern "C" void CleanupTargetdb4a40(void* object);
extern "C" void CleanupTargetdccc40(void* object);
extern "C" void CleanupTargetde7590(void* object);
extern "C" void CleanupTargetdf3b80(void* object);
extern "C" void CleanupTargetdf7ab0(void* object);
extern "C" void CleanupTargete13a00(void* object);
extern "C" void CleanupTargete25400(void* object);

struct HeapCleanupDeallocators2
{
    static void* Deletedac6c0(void* object, unsigned int flags);
    static void* Deletedac720(void* object, unsigned int flags);
    static void* Deletedaed80(void* object, unsigned int flags);
    static void* Deletedaede0(void* object, unsigned int flags);
    static void* Deletedb03d0(void* object, unsigned int flags);
    static void* Deletedb0430(void* object, unsigned int flags);
    static void* Deletedb3140(void* object, unsigned int flags);
    static void* Deletedb4af0(void* object, unsigned int flags);
    static void* Deletedb4b50(void* object, unsigned int flags);
    static void* Deletedb4c30(void* object, unsigned int flags);
    static void* Deletedb5f70(void* object, unsigned int flags);
    static void* Deletedb5fd0(void* object, unsigned int flags);
    static void* Deletedb7a40(void* object, unsigned int flags);
    static void* Deletedb7aa0(void* object, unsigned int flags);
    static void* Deletedb8c30(void* object, unsigned int flags);
    static void* Deletedb8c90(void* object, unsigned int flags);
    static void* Deletedbced0(void* object, unsigned int flags);
    static void* Deletedbcf30(void* object, unsigned int flags);
    static void* Deletedbf050(void* object, unsigned int flags);
    static void* Deletedc0020(void* object, unsigned int flags);
    static void* Deletedc28a0(void* object, unsigned int flags);
    static void* Deletedc2900(void* object, unsigned int flags);
    static void* Deletedc3f90(void* object, unsigned int flags);
    static void* Deletedc3ff0(void* object, unsigned int flags);
    static void* Deletedc6ac0(void* object, unsigned int flags);
    static void* Deletedc6b20(void* object, unsigned int flags);
    static void* Deletedc8880(void* object, unsigned int flags);
    static void* Deletedccec0(void* object, unsigned int flags);
    static void* Deletedccf90(void* object, unsigned int flags);
    static void* Deletedcd1c0(void* object, unsigned int flags);
    static void* Deletedcff60(void* object, unsigned int flags);
    static void* Deletedd1a90(void* object, unsigned int flags);
    static void* Deletedd1af0(void* object, unsigned int flags);
    static void* Deletedd6ba0(void* object, unsigned int flags);
    static void* Deleteddc630(void* object, unsigned int flags);
    static void* Deleteddd860(void* object, unsigned int flags);
    static void* Deletedde870(void* object, unsigned int flags);
    static void* Deletede06c0(void* object, unsigned int flags);
    static void* Deletede2080(void* object, unsigned int flags);
    static void* Deletede33a0(void* object, unsigned int flags);
    static void* Deletede5380(void* object, unsigned int flags);
    static void* Deletede7a20(void* object, unsigned int flags);
    static void* Deletede7a80(void* object, unsigned int flags);
    static void* Deletede7ae0(void* object, unsigned int flags);
    static void* Deletede7b40(void* object, unsigned int flags);
    static void* Deletede7ba0(void* object, unsigned int flags);
    static void* Deletede7c00(void* object, unsigned int flags);
    static void* Deletede7e00(void* object, unsigned int flags);
    static void* Deleteded200(void* object, unsigned int flags);
    static void* Deleteded260(void* object, unsigned int flags);
    static void* Deleteded900(void* object, unsigned int flags);
    static void* Deleteded960(void* object, unsigned int flags);
    static void* Deletedf14d0(void* object, unsigned int flags);
    static void* Deletedf1530(void* object, unsigned int flags);
    static void* Deletedf3cd0(void* object, unsigned int flags);
    static void* Deletedf3f90(void* object, unsigned int flags);
    static void* Deletedf7c40(void* object, unsigned int flags);
    static void* Deletedf7ca0(void* object, unsigned int flags);
    static void* Deletedf7fd0(void* object, unsigned int flags);
    static void* Deletedfa2e0(void* object, unsigned int flags);
    static void* Deletee03e10(void* object, unsigned int flags);
    static void* Deletee03e70(void* object, unsigned int flags);
    static void* Deletee06980(void* object, unsigned int flags);
    static void* Deletee069e0(void* object, unsigned int flags);
    static void* Deletee0e470(void* object, unsigned int flags);
    static void* Deletee0e4d0(void* object, unsigned int flags);
    static void* Deletee0e530(void* object, unsigned int flags);
    static void* Deletee0e590(void* object, unsigned int flags);
    static void* Deletee13c10(void* object, unsigned int flags);
    static void* Deletee18640(void* object, unsigned int flags);
    static void* Deletee186a0(void* object, unsigned int flags);
    static void* Deletee18700(void* object, unsigned int flags);
    static void* Deletee18760(void* object, unsigned int flags);
    static void* Deletee187c0(void* object, unsigned int flags);
    static void* Deletee18820(void* object, unsigned int flags);
};
