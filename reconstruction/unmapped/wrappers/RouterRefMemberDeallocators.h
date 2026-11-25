// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original Havok TLS-router scalar deleting destructor wrappers.
// RouterRefMemberDeallocators, types, methods and referenced globals: GUESS(low) STANDIN CRASHLOGGER_PDB(59818@2026.10.24); original ownership unknown.
// Adapted bodies: none
#pragma once

struct RouterRefBlockHeap
{
    virtual ~RouterRefBlockHeap();
    virtual void ReservedSlot01();
    virtual void BlockFree(void* block, int size);
};

struct RouterRefMemoryRouter
{
    unsigned char reservedHeader[0x58];
    RouterRefBlockHeap* heap;
};

// Typed stand-in for hkStringPtr (at +0x38 in hkbNode).
struct RouterRefStringPtr
{
    const char* dataAndFlags;
};

// Layout matching hkbNode (size 0x48: hkReferencedObject + hkbBindable + userData + name + id/cloneState).
struct RouterRefNodeBase
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
    RouterRefStringPtr name;
    unsigned short id;
    unsigned char cloneState;
};

struct RefNodeWithTargetAt50 : RouterRefNodeBase
{
    unsigned long long modifierFields48;
    void* refTarget;
};

struct RefNodeWithTargetAt58 : RouterRefNodeBase
{
    unsigned long long modifierFields48[2];
    void* refTarget;
};

struct RefNodeWithTargetAt60 : RouterRefNodeBase
{
    unsigned long long modifierFields48[3];
    void* refTarget;
};

struct RefNodeWithTargetAt70 : RouterRefNodeBase
{
    unsigned long long modifierFields48[5];
    void* refTarget;
};

struct RefNodeWithTargetAt88 : RouterRefNodeBase
{
    unsigned long long modifierFields48[8];
    void* refTarget;
};

struct RefNodeWithTargetAt90 : RouterRefNodeBase
{
    unsigned long long modifierFields48[9];
    void* refTarget;
};

struct RefNodeWithTargetAtF8 : RouterRefNodeBase
{
    unsigned long long modifierFields48[22];
    void* refTarget;
};

extern "C" unsigned int g_memoryRouterTlsSlot;
extern "C" void* (*const g_tlsGetValue)(unsigned int tlsIndex);
extern "C" void GlobalSizedDelete(void* object, unsigned long long objectSize);
extern "C" void RemoveReferencedObject(void* referencedObject);
extern "C" void DestroyOwnedStringPtr(RouterRefStringPtr* stringPtr);
extern "C" void DestroyBindableBase(RouterRefNodeBase* object);

struct RouterRefMemberDeallocators
{
    static void* Deleteae2be0(RefNodeWithTargetAt50* object, unsigned int deleteFlags);
    static void* Deleteae2d10(RefNodeWithTargetAt58* object, unsigned int deleteFlags);
    static void* Deleteae3030(RefNodeWithTargetAt50* object, unsigned int deleteFlags);
    static void* Deleteae3890(RefNodeWithTargetAt50* object, unsigned int deleteFlags);
    static void* Deleteae4640(RefNodeWithTargetAt50* object, unsigned int deleteFlags);
    static void* Deleteae4ca0(RefNodeWithTargetAtF8* object, unsigned int deleteFlags);
    static void* Deleteae4fe0(RefNodeWithTargetAt90* object, unsigned int deleteFlags);
    static void* Deleteae5700(RefNodeWithTargetAt60* object, unsigned int deleteFlags);
    static void* Deletebb6ee0(RefNodeWithTargetAt70* object, unsigned int deleteFlags);
    static void* Deletebb77a0(RefNodeWithTargetAt58* object, unsigned int deleteFlags);
    static void* Deletebbb840(RefNodeWithTargetAt88* object, unsigned int deleteFlags);
    static void* Deletebbbf00(RefNodeWithTargetAt60* object, unsigned int deleteFlags);
};
