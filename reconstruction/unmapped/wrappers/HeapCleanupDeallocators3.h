// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original custom-allocator deleting-destructor template.
// HeapCleanupDeallocators3, types, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

struct HeapCleanupDeallocators3GlobalHeap
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

extern "C" HeapCleanupDeallocators3GlobalHeap* GlobalHeapSlot3275ae0;
extern "C" void GlobalDeallocTarget1177a80(void* object, unsigned long long size);
extern "C" void CleanupTargetcf3100(void* object);
extern "C" void CleanupTargetd163b0(void* object);
extern "C" void CleanupTargetd6dd80(void* object);
extern "C" void CleanupTargete18110(void* object);
extern "C" void CleanupTargete25450(void* object);
extern "C" void CleanupTargete47850(void* object);
extern "C" void CleanupTargete47980(void* object);
extern "C" void CleanupTargete6c390(void* object);
extern "C" void CleanupTarget1187710(void* object);
extern "C" void CleanupTarget1187a20(void* object);
extern "C" void CleanupTarget1187ad0(void* object);
extern "C" void CleanupTarget11a3dc0(void* object);
extern "C" void CleanupTarget11a3e60(void* object);

struct HeapCleanupDeallocators3
{
    static void* Deletee188f0(void* object, unsigned int flags);
    static void* Deletee25560(void* object, unsigned int flags);
    static void* Deletee255c0(void* object, unsigned int flags);
    static void* Deletee25620(void* object, unsigned int flags);
    static void* Deletee25680(void* object, unsigned int flags);
    static void* Deletee25930(void* object, unsigned int flags);
    static void* Deletee25a50(void* object, unsigned int flags);
    static void* Deletee2c6d0(void* object, unsigned int flags);
    static void* Deletee3bcf0(void* object, unsigned int flags);
    static void* Deletee482b0(void* object, unsigned int flags);
    static void* Deletee48310(void* object, unsigned int flags);
    static void* Deletee48370(void* object, unsigned int flags);
    static void* Deletee50a90(void* object, unsigned int flags);
    static void* Deletee50af0(void* object, unsigned int flags);
    static void* Deletee55900(void* object, unsigned int flags);
    static void* Deletee559c0(void* object, unsigned int flags);
    static void* Deletee59d90(void* object, unsigned int flags);
    static void* Deletee59df0(void* object, unsigned int flags);
    static void* Deletee59e50(void* object, unsigned int flags);
    static void* Deletee59eb0(void* object, unsigned int flags);
    static void* Deletee59f10(void* object, unsigned int flags);
    static void* Deletee59f70(void* object, unsigned int flags);
    static void* Deletee59fd0(void* object, unsigned int flags);
    static void* Deletee5a030(void* object, unsigned int flags);
    static void* Deletee5a090(void* object, unsigned int flags);
    static void* Deletee5a0f0(void* object, unsigned int flags);
    static void* Deletee5a150(void* object, unsigned int flags);
    static void* Deletee5a580(void* object, unsigned int flags);
    static void* Deletee692e0(void* object, unsigned int flags);
    static void* Deletee699f0(void* object, unsigned int flags);
    static void* Deletee69a50(void* object, unsigned int flags);
    static void* Deletee6c440(void* object, unsigned int flags);
    static void* Deletee6c5c0(void* object, unsigned int flags);
    static void* Deletee73be0(void* object, unsigned int flags);
    static void* Deletee7d580(void* object, unsigned int flags);
    static void* Delete1180a20(void* object, unsigned int flags);
    static void* Delete1180a80(void* object, unsigned int flags);
    static void* Delete1187c50(void* object, unsigned int flags);
    static void* Delete1187dc0(void* object, unsigned int flags);
    static void* Delete1187e20(void* object, unsigned int flags);
    static void* Delete1187e80(void* object, unsigned int flags);
    static void* Delete1187ee0(void* object, unsigned int flags);
    static void* Delete1187f40(void* object, unsigned int flags);
};
