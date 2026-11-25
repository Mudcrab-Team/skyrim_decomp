// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original Havok TLS-router scalar deleting destructor wrappers.
// RouterMemberCleanupDeallocators, types, methods and referenced globals: GUESS(low) STANDIN CRASHLOGGER_PDB(59818@2026.10.24); original ownership unknown.
// Adapted bodies: none
#pragma once

struct RouterCleanupBlockHeap
{
    virtual ~RouterCleanupBlockHeap();
    virtual void ReservedSlot01();
    virtual void BlockFree(void* block, int size);
};

struct RouterCleanupMemoryRouter
{
    unsigned char reservedHeader[0x58];
    RouterCleanupBlockHeap* heap;
};

// Typed stand-in for hkStringPtr (owned string storage released by DestroyStringPtr).
struct RouterOwnedStringPtr
{
    const char* dataAndFlags;
};

// Layout matching hkbNode prefix (hkReferencedObject + hkbBindable + userData + name at +0x38).
struct RouterBindableNodeObject
{
    void* vftable;
    unsigned short memSizeAndFlags;
    short referenceCount;
    void* variableBindingSet;
    void* cachedBindablesData;
    int cachedBindablesSize;
    int cachedBindablesCapacityAndFlags;
    bool areBindablesCached;
    unsigned long long userData;
    RouterOwnedStringPtr name;
};

extern "C" unsigned int g_memoryRouterTlsSlot;
extern "C" void* (*const g_tlsGetValue)(unsigned int tlsIndex);
extern "C" void GlobalSizedDelete(void* object, unsigned long long objectSize);
extern "C" void DestroyOwnedStringPtr(RouterOwnedStringPtr* stringPtr);
extern "C" void DestroyBindableBase(RouterBindableNodeObject* object);

struct RouterMemberCleanupDeallocators
{
    static void* Deletead1d70(RouterBindableNodeObject* object, unsigned int deleteFlags);
    static void* Deletead1e00(RouterBindableNodeObject* object, unsigned int deleteFlags);
    static void* Deleteae2240(RouterBindableNodeObject* object, unsigned int deleteFlags);
    static void* Deleteae2530(RouterBindableNodeObject* object, unsigned int deleteFlags);
    static void* Deleteae26d0(RouterBindableNodeObject* object, unsigned int deleteFlags);
    static void* Deleteae27f0(RouterBindableNodeObject* object, unsigned int deleteFlags);
    static void* Deleteae2910(RouterBindableNodeObject* object, unsigned int deleteFlags);
    static void* Deleteae2ac0(RouterBindableNodeObject* object, unsigned int deleteFlags);
    static void* Deleteae3630(RouterBindableNodeObject* object, unsigned int deleteFlags);
    static void* Deleteae3a70(RouterBindableNodeObject* object, unsigned int deleteFlags);
    static void* Deleteae3b90(RouterBindableNodeObject* object, unsigned int deleteFlags);
    static void* Deleteae40f0(RouterBindableNodeObject* object, unsigned int deleteFlags);
    static void* Deleteae4320(RouterBindableNodeObject* object, unsigned int deleteFlags);
    static void* Deleteae4470(RouterBindableNodeObject* object, unsigned int deleteFlags);
    static void* Deleteae46e0(RouterBindableNodeObject* object, unsigned int deleteFlags);
    static void* Deleteae4eb0(RouterBindableNodeObject* object, unsigned int deleteFlags);
    static void* Deleteae5090(RouterBindableNodeObject* object, unsigned int deleteFlags);
    static void* Deleteae5440(RouterBindableNodeObject* object, unsigned int deleteFlags);
    static void* Deleteae5830(RouterBindableNodeObject* object, unsigned int deleteFlags);
    static void* Deleteae5950(RouterBindableNodeObject* object, unsigned int deleteFlags);
    static void* Deletebb5920(RouterBindableNodeObject* object, unsigned int deleteFlags);
    static void* Deletebb6280(RouterBindableNodeObject* object, unsigned int deleteFlags);
    static void* Deletebb64e0(RouterBindableNodeObject* object, unsigned int deleteFlags);
    static void* Deletebb8130(RouterBindableNodeObject* object, unsigned int deleteFlags);
    static void* Deletebb83e0(RouterBindableNodeObject* object, unsigned int deleteFlags);
    static void* Deletebb86c0(RouterBindableNodeObject* object, unsigned int deleteFlags);
    static void* Deletebb9b20(RouterBindableNodeObject* object, unsigned int deleteFlags);
    static void* Deletebbbb40(RouterBindableNodeObject* object, unsigned int deleteFlags);
    static void* Deletebbc4c0(RouterBindableNodeObject* object, unsigned int deleteFlags);
};
