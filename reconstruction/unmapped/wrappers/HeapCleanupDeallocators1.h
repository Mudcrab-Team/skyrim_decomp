// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original custom-allocator deleting-destructor template.
// HeapCleanupDeallocators1, types, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

struct HeapCleanupDeallocators1GlobalHeap
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

extern "C" HeapCleanupDeallocators1GlobalHeap* GlobalHeapSlot3275ae0;
extern "C" void GlobalDeallocTarget1177a80(void* object, unsigned long long size);
extern "C" void CleanupTargetcf3100(void* object);
extern "C" void CleanupTargetcf3110(void* object);
extern "C" void CleanupTargetd08c20(void* object);
extern "C" void CleanupTargetd0be30(void* object);
extern "C" void CleanupTargetd116d0(void* object);
extern "C" void CleanupTargetd163b0(void* object);
extern "C" void CleanupTargetd30720(void* object);
extern "C" void CleanupTargetd30880(void* object);
extern "C" void CleanupTargetd3f930(void* object);
extern "C" void CleanupTargetd5ab70(void* object);
extern "C" void CleanupTargetd5ac40(void* object);
extern "C" void CleanupTargetd6b0d0(void* object);
extern "C" void CleanupTargetd74ab0(void* object);
extern "C" void CleanupTargetd7c1b0(void* object);
extern "C" void CleanupTargetd7c4f0(void* object);
extern "C" void CleanupTargetd8dd60(void* object);
extern "C" void CleanupTargetd8e180(void* object);
extern "C" void CleanupTargetdaa660(void* object);
extern "C" void CleanupTargetdac510(void* object);

struct HeapCleanupDeallocators1
{
    static void* Deletecf34a0(void* object, unsigned int flags);
    static void* Deletecf3500(void* object, unsigned int flags);
    static void* Deleted07120(void* object, unsigned int flags);
    static void* Deleted07180(void* object, unsigned int flags);
    static void* Deleted071e0(void* object, unsigned int flags);
    static void* Deleted07240(void* object, unsigned int flags);
    static void* Deleted072a0(void* object, unsigned int flags);
    static void* Deleted07450(void* object, unsigned int flags);
    static void* Deleted09090(void* object, unsigned int flags);
    static void* Deleted090f0(void* object, unsigned int flags);
    static void* Deleted09150(void* object, unsigned int flags);
    static void* Deleted11c60(void* object, unsigned int flags);
    static void* Deleted1cf50(void* object, unsigned int flags);
    static void* Deleted1cfb0(void* object, unsigned int flags);
    static void* Deleted1d010(void* object, unsigned int flags);
    static void* Deleted1d070(void* object, unsigned int flags);
    static void* Deleted1d0d0(void* object, unsigned int flags);
    static void* Deleted1d130(void* object, unsigned int flags);
    static void* Deleted1d6b0(void* object, unsigned int flags);
    static void* Deleted1d7e0(void* object, unsigned int flags);
    static void* Deleted30d90(void* object, unsigned int flags);
    static void* Deleted30df0(void* object, unsigned int flags);
    static void* Deleted30ff0(void* object, unsigned int flags);
    static void* Deleted31050(void* object, unsigned int flags);
    static void* Deleted406e0(void* object, unsigned int flags);
    static void* Deleted40740(void* object, unsigned int flags);
    static void* Deleted407a0(void* object, unsigned int flags);
    static void* Deleted40800(void* object, unsigned int flags);
    static void* Deleted40860(void* object, unsigned int flags);
    static void* Deleted408c0(void* object, unsigned int flags);
    static void* Deleted40920(void* object, unsigned int flags);
    static void* Deleted411c0(void* object, unsigned int flags);
    static void* Deleted41320(void* object, unsigned int flags);
    static void* Deleted5b180(void* object, unsigned int flags);
    static void* Deleted5b3a0(void* object, unsigned int flags);
    static void* Deleted6b2b0(void* object, unsigned int flags);
    static void* Deleted6b310(void* object, unsigned int flags);
    static void* Deleted6de60(void* object, unsigned int flags);
    static void* Deleted6dec0(void* object, unsigned int flags);
    static void* Deleted74e00(void* object, unsigned int flags);
    static void* Deleted75070(void* object, unsigned int flags);
    static void* Deleted7cc50(void* object, unsigned int flags);
    static void* Deleted7ccb0(void* object, unsigned int flags);
    static void* Deleted7cd10(void* object, unsigned int flags);
    static void* Deleted7cd70(void* object, unsigned int flags);
    static void* Deleted7cdd0(void* object, unsigned int flags);
    static void* Deleted7ce30(void* object, unsigned int flags);
    static void* Deleted7ce90(void* object, unsigned int flags);
    static void* Deleted7d0d0(void* object, unsigned int flags);
    static void* Deleted7d6b0(void* object, unsigned int flags);
    static void* Deleted856b0(void* object, unsigned int flags);
    static void* Deleted87770(void* object, unsigned int flags);
    static void* Deleted877d0(void* object, unsigned int flags);
    static void* Deleted8e550(void* object, unsigned int flags);
    static void* Deleted8e5b0(void* object, unsigned int flags);
    static void* Deleted8e610(void* object, unsigned int flags);
    static void* Deleted8e670(void* object, unsigned int flags);
    static void* Deleted8e6d0(void* object, unsigned int flags);
    static void* Deleted8e730(void* object, unsigned int flags);
    static void* Deleted8e7c0(void* object, unsigned int flags);
    static void* Deleted8e820(void* object, unsigned int flags);
    static void* Deleted8e920(void* object, unsigned int flags);
    static void* Deleted8e980(void* object, unsigned int flags);
    static void* Deleted8ebb0(void* object, unsigned int flags);
    static void* Deleted8ed10(void* object, unsigned int flags);
    static void* Deleteda01e0(void* object, unsigned int flags);
    static void* Deleteda2850(void* object, unsigned int flags);
    static void* Deleteda28b0(void* object, unsigned int flags);
    static void* Deleteda4da0(void* object, unsigned int flags);
    static void* Deleteda4e00(void* object, unsigned int flags);
    static void* Deleteda83e0(void* object, unsigned int flags);
    static void* Deleteda8440(void* object, unsigned int flags);
    static void* Deletedaa7e0(void* object, unsigned int flags);
    static void* Deletedaa840(void* object, unsigned int flags);
    static void* Deletedac5d0(void* object, unsigned int flags);
};
