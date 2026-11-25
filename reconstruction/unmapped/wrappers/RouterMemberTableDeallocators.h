// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original Havok TLS-router scalar deleting destructor wrappers.
// RouterMemberTableDeallocators, types, methods and referenced globals: GUESS(low) STANDIN CRASHLOGGER_PDB(59818@2026.10.24); original ownership unknown.
// Adapted bodies: none
#pragma once

struct RouterTableBlockHeap
{
    virtual ~RouterTableBlockHeap();
    virtual void ReservedSlot01();
    virtual void BlockFree(void* block, int size);
};

struct RouterTableMemoryRouter
{
    unsigned char reservedHeader[0x58];
    RouterTableBlockHeap* heap;
};

// Typed stand-in for hkStringPtr and owned member subobjects destroyed before base vftable reset.
struct RouterTableStringPtr
{
    const char* dataAndFlags;
};

struct RouterTableOwnedMember
{
    void* storage;
};

struct RouterReferencedBase
{
    void* vftable;
    unsigned short memSizeAndFlags;
    short referenceCount;
};

struct StringAt10Object : RouterReferencedBase
{
    RouterTableStringPtr member;
};

struct StringAt18Object : RouterReferencedBase
{
    unsigned long long field10;
    RouterTableStringPtr member;
};

struct StringAt20Object : RouterReferencedBase
{
    unsigned long long field10;
    unsigned long long field18;
    RouterTableStringPtr member;
};

struct SubobjectAt10Object : RouterReferencedBase
{
    RouterTableOwnedMember member;
};

struct SubobjectAt18Object : RouterReferencedBase
{
    unsigned long long field10;
    RouterTableOwnedMember member;
};

extern "C" unsigned int g_memoryRouterTlsSlot;
extern "C" void* (*const g_tlsGetValue)(unsigned int tlsIndex);
extern "C" void GlobalSizedDelete(void* object, unsigned long long objectSize);
extern "C" void DestroyOwnedStringPtr(RouterTableStringPtr* stringPtr);
extern "C" void DestroyOwnedSubobjectB(RouterTableOwnedMember* member);
extern "C" void DestroyOwnedSubobjectC(RouterTableOwnedMember* member);
extern "C" unsigned char kReferencedObjectVftable[];

struct RouterMemberTableDeallocators
{
    static void* Deleteaaa370(StringAt10Object* object, unsigned int deleteFlags);
    static void* Deleteae4800(StringAt10Object* object, unsigned int deleteFlags);
    static void* Deleteae4890(StringAt10Object* object, unsigned int deleteFlags);
    static void* Deleteae4920(StringAt10Object* object, unsigned int deleteFlags);
    static void* Deleteae55e0(StringAt10Object* object, unsigned int deleteFlags);
    static void* Deleteae5670(StringAt10Object* object, unsigned int deleteFlags);
    static void* Deleteb2e460(SubobjectAt18Object* object, unsigned int deleteFlags);
    static void* Deleteb2e700(SubobjectAt18Object* object, unsigned int deleteFlags);
    static void* Deleteb2eb20(SubobjectAt10Object* object, unsigned int deleteFlags);
    static void* Deleteca1d40(StringAt20Object* object, unsigned int deleteFlags);
    static void* Deletecc8180(SubobjectAt10Object* object, unsigned int deleteFlags);
    static void* Delete10d1d00(StringAt18Object* object, unsigned int deleteFlags);
    static void* Delete10d2320(StringAt18Object* object, unsigned int deleteFlags);
};
