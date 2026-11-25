// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original Havok TLS-router scalar deleting destructor wrappers.
// RouterRefMemberDeallocators, types, methods and referenced globals: GUESS(low) STANDIN CRASHLOGGER_PDB(59818@2026.10.24); original ownership unknown.
// Adapted bodies: none
// 0xae2be0 RouterRefMemberDeallocators::Deleteae2be0
// 0xae2d10 RouterRefMemberDeallocators::Deleteae2d10
// 0xae3030 RouterRefMemberDeallocators::Deleteae3030
// 0xae3890 RouterRefMemberDeallocators::Deleteae3890
// 0xae4640 RouterRefMemberDeallocators::Deleteae4640
// 0xae4ca0 RouterRefMemberDeallocators::Deleteae4ca0
// 0xae4fe0 RouterRefMemberDeallocators::Deleteae4fe0
// 0xae5700 RouterRefMemberDeallocators::Deleteae5700
// 0xbb6ee0 RouterRefMemberDeallocators::Deletebb6ee0
// 0xbb77a0 RouterRefMemberDeallocators::Deletebb77a0
// 0xbbb840 RouterRefMemberDeallocators::Deletebbb840
// 0xbbbf00 RouterRefMemberDeallocators::Deletebbbf00
// CI hash: 0xae2be0 ?Deleteae2be0@RouterRefMemberDeallocators@@SAPEAXPEAURefNodeWithTargetAt50@@I@Z
// CI hash: 0xae2d10 ?Deleteae2d10@RouterRefMemberDeallocators@@SAPEAXPEAURefNodeWithTargetAt58@@I@Z
// CI hash: 0xae3030 ?Deleteae3030@RouterRefMemberDeallocators@@SAPEAXPEAURefNodeWithTargetAt50@@I@Z
// CI hash: 0xae3890 ?Deleteae3890@RouterRefMemberDeallocators@@SAPEAXPEAURefNodeWithTargetAt50@@I@Z
// CI hash: 0xae4640 ?Deleteae4640@RouterRefMemberDeallocators@@SAPEAXPEAURefNodeWithTargetAt50@@I@Z
// CI hash: 0xae4ca0 ?Deleteae4ca0@RouterRefMemberDeallocators@@SAPEAXPEAURefNodeWithTargetAtF8@@I@Z
// CI hash: 0xae4fe0 ?Deleteae4fe0@RouterRefMemberDeallocators@@SAPEAXPEAURefNodeWithTargetAt90@@I@Z
// CI hash: 0xae5700 ?Deleteae5700@RouterRefMemberDeallocators@@SAPEAXPEAURefNodeWithTargetAt60@@I@Z
// CI hash: 0xbb6ee0 ?Deletebb6ee0@RouterRefMemberDeallocators@@SAPEAXPEAURefNodeWithTargetAt70@@I@Z
// CI hash: 0xbb77a0 ?Deletebb77a0@RouterRefMemberDeallocators@@SAPEAXPEAURefNodeWithTargetAt58@@I@Z
// CI hash: 0xbbb840 ?Deletebbb840@RouterRefMemberDeallocators@@SAPEAXPEAURefNodeWithTargetAt88@@I@Z
// CI hash: 0xbbbf00 ?Deletebbbf00@RouterRefMemberDeallocators@@SAPEAXPEAURefNodeWithTargetAt60@@I@Z
#include "RouterRefMemberDeallocators.h"

// CrashLogger PDB records deleting destructors with 0-arg void() prototypes; MSVC x64 scalar
// deleting destructors take (this, deleteFlags) and return this.
namespace
{
constexpr unsigned int kDeleteMemoryFlag = 1u;
constexpr unsigned int kGlobalDeleteFlag = 4u;
constexpr unsigned short kDynamicAllocSizeTag = 0xffffu;
} // namespace

void* RouterRefMemberDeallocators::Deleteae2be0(RefNodeWithTargetAt50* object, unsigned int deleteFlags)
{
    if (object->refTarget != nullptr)
    {
        RemoveReferencedObject(object->refTarget);
    }
    object->refTarget = nullptr;
    DestroyOwnedStringPtr(&object->name);
    DestroyBindableBase(object);
    if ((deleteFlags & kDeleteMemoryFlag) != 0u)
    {
        if ((deleteFlags & kGlobalDeleteFlag) == 0u)
        {
            unsigned short taggedSize = object->memSizeAndFlags;
            int allocSize = (taggedSize == kDynamicAllocSizeTag) ? 104 : taggedSize;
            RouterRefMemoryRouter* router = static_cast<RouterRefMemoryRouter*>(g_tlsGetValue(g_memoryRouterTlsSlot));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalSizedDelete(object, 104ull);
        }
    }
    return object;
}

void* RouterRefMemberDeallocators::Deleteae2d10(RefNodeWithTargetAt58* object, unsigned int deleteFlags)
{
    if (object->refTarget != nullptr)
    {
        RemoveReferencedObject(object->refTarget);
    }
    object->refTarget = nullptr;
    DestroyOwnedStringPtr(&object->name);
    DestroyBindableBase(object);
    if ((deleteFlags & kDeleteMemoryFlag) != 0u)
    {
        if ((deleteFlags & kGlobalDeleteFlag) == 0u)
        {
            unsigned short taggedSize = object->memSizeAndFlags;
            int allocSize = (taggedSize == kDynamicAllocSizeTag) ? 120 : taggedSize;
            RouterRefMemoryRouter* router = static_cast<RouterRefMemoryRouter*>(g_tlsGetValue(g_memoryRouterTlsSlot));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalSizedDelete(object, 120ull);
        }
    }
    return object;
}

void* RouterRefMemberDeallocators::Deleteae3030(RefNodeWithTargetAt50* object, unsigned int deleteFlags)
{
    if (object->refTarget != nullptr)
    {
        RemoveReferencedObject(object->refTarget);
    }
    object->refTarget = nullptr;
    DestroyOwnedStringPtr(&object->name);
    DestroyBindableBase(object);
    if ((deleteFlags & kDeleteMemoryFlag) != 0u)
    {
        if ((deleteFlags & kGlobalDeleteFlag) == 0u)
        {
            unsigned short taggedSize = object->memSizeAndFlags;
            int allocSize = (taggedSize == kDynamicAllocSizeTag) ? 104 : taggedSize;
            RouterRefMemoryRouter* router = static_cast<RouterRefMemoryRouter*>(g_tlsGetValue(g_memoryRouterTlsSlot));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalSizedDelete(object, 104ull);
        }
    }
    return object;
}

void* RouterRefMemberDeallocators::Deleteae3890(RefNodeWithTargetAt50* object, unsigned int deleteFlags)
{
    if (object->refTarget != nullptr)
    {
        RemoveReferencedObject(object->refTarget);
    }
    object->refTarget = nullptr;
    DestroyOwnedStringPtr(&object->name);
    DestroyBindableBase(object);
    if ((deleteFlags & kDeleteMemoryFlag) != 0u)
    {
        if ((deleteFlags & kGlobalDeleteFlag) == 0u)
        {
            unsigned short taggedSize = object->memSizeAndFlags;
            int allocSize = (taggedSize == kDynamicAllocSizeTag) ? 144 : taggedSize;
            RouterRefMemoryRouter* router = static_cast<RouterRefMemoryRouter*>(g_tlsGetValue(g_memoryRouterTlsSlot));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalSizedDelete(object, 144ull);
        }
    }
    return object;
}

void* RouterRefMemberDeallocators::Deleteae4640(RefNodeWithTargetAt50* object, unsigned int deleteFlags)
{
    if (object->refTarget != nullptr)
    {
        RemoveReferencedObject(object->refTarget);
    }
    object->refTarget = nullptr;
    DestroyOwnedStringPtr(&object->name);
    DestroyBindableBase(object);
    if ((deleteFlags & kDeleteMemoryFlag) != 0u)
    {
        if ((deleteFlags & kGlobalDeleteFlag) == 0u)
        {
            unsigned short taggedSize = object->memSizeAndFlags;
            int allocSize = (taggedSize == kDynamicAllocSizeTag) ? 88 : taggedSize;
            RouterRefMemoryRouter* router = static_cast<RouterRefMemoryRouter*>(g_tlsGetValue(g_memoryRouterTlsSlot));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalSizedDelete(object, 88ull);
        }
    }
    return object;
}

void* RouterRefMemberDeallocators::Deleteae4ca0(RefNodeWithTargetAtF8* object, unsigned int deleteFlags)
{
    if (object->refTarget != nullptr)
    {
        RemoveReferencedObject(object->refTarget);
    }
    object->refTarget = nullptr;
    DestroyOwnedStringPtr(&object->name);
    DestroyBindableBase(object);
    if ((deleteFlags & kDeleteMemoryFlag) != 0u)
    {
        if ((deleteFlags & kGlobalDeleteFlag) == 0u)
        {
            unsigned short taggedSize = object->memSizeAndFlags;
            int allocSize = (taggedSize == kDynamicAllocSizeTag) ? 288 : taggedSize;
            RouterRefMemoryRouter* router = static_cast<RouterRefMemoryRouter*>(g_tlsGetValue(g_memoryRouterTlsSlot));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalSizedDelete(object, 288ull);
        }
    }
    return object;
}

void* RouterRefMemberDeallocators::Deleteae4fe0(RefNodeWithTargetAt90* object, unsigned int deleteFlags)
{
    if (object->refTarget != nullptr)
    {
        RemoveReferencedObject(object->refTarget);
    }
    object->refTarget = nullptr;
    DestroyOwnedStringPtr(&object->name);
    DestroyBindableBase(object);
    if ((deleteFlags & kDeleteMemoryFlag) != 0u)
    {
        if ((deleteFlags & kGlobalDeleteFlag) == 0u)
        {
            unsigned short taggedSize = object->memSizeAndFlags;
            int allocSize = (taggedSize == kDynamicAllocSizeTag) ? 160 : taggedSize;
            RouterRefMemoryRouter* router = static_cast<RouterRefMemoryRouter*>(g_tlsGetValue(g_memoryRouterTlsSlot));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalSizedDelete(object, 160ull);
        }
    }
    return object;
}

void* RouterRefMemberDeallocators::Deleteae5700(RefNodeWithTargetAt60* object, unsigned int deleteFlags)
{
    if (object->refTarget != nullptr)
    {
        RemoveReferencedObject(object->refTarget);
    }
    object->refTarget = nullptr;
    DestroyOwnedStringPtr(&object->name);
    DestroyBindableBase(object);
    if ((deleteFlags & kDeleteMemoryFlag) != 0u)
    {
        if ((deleteFlags & kGlobalDeleteFlag) == 0u)
        {
            unsigned short taggedSize = object->memSizeAndFlags;
            int allocSize = (taggedSize == kDynamicAllocSizeTag) ? 112 : taggedSize;
            RouterRefMemoryRouter* router = static_cast<RouterRefMemoryRouter*>(g_tlsGetValue(g_memoryRouterTlsSlot));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalSizedDelete(object, 112ull);
        }
    }
    return object;
}

void* RouterRefMemberDeallocators::Deletebb6ee0(RefNodeWithTargetAt70* object, unsigned int deleteFlags)
{
    if (object->refTarget != nullptr)
    {
        RemoveReferencedObject(object->refTarget);
    }
    object->refTarget = nullptr;
    DestroyOwnedStringPtr(&object->name);
    DestroyBindableBase(object);
    if ((deleteFlags & kDeleteMemoryFlag) != 0u)
    {
        if ((deleteFlags & kGlobalDeleteFlag) == 0u)
        {
            unsigned short taggedSize = object->memSizeAndFlags;
            int allocSize = (taggedSize == kDynamicAllocSizeTag) ? 128 : taggedSize;
            RouterRefMemoryRouter* router = static_cast<RouterRefMemoryRouter*>(g_tlsGetValue(g_memoryRouterTlsSlot));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalSizedDelete(object, 128ull);
        }
    }
    return object;
}

void* RouterRefMemberDeallocators::Deletebb77a0(RefNodeWithTargetAt58* object, unsigned int deleteFlags)
{
    if (object->refTarget != nullptr)
    {
        RemoveReferencedObject(object->refTarget);
    }
    object->refTarget = nullptr;
    DestroyOwnedStringPtr(&object->name);
    DestroyBindableBase(object);
    if ((deleteFlags & kDeleteMemoryFlag) != 0u)
    {
        if ((deleteFlags & kGlobalDeleteFlag) == 0u)
        {
            unsigned short taggedSize = object->memSizeAndFlags;
            int allocSize = (taggedSize == kDynamicAllocSizeTag) ? 96 : taggedSize;
            RouterRefMemoryRouter* router = static_cast<RouterRefMemoryRouter*>(g_tlsGetValue(g_memoryRouterTlsSlot));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalSizedDelete(object, 96ull);
        }
    }
    return object;
}

void* RouterRefMemberDeallocators::Deletebbb840(RefNodeWithTargetAt88* object, unsigned int deleteFlags)
{
    if (object->refTarget != nullptr)
    {
        RemoveReferencedObject(object->refTarget);
    }
    object->refTarget = nullptr;
    DestroyOwnedStringPtr(&object->name);
    DestroyBindableBase(object);
    if ((deleteFlags & kDeleteMemoryFlag) != 0u)
    {
        if ((deleteFlags & kGlobalDeleteFlag) == 0u)
        {
            unsigned short taggedSize = object->memSizeAndFlags;
            int allocSize = (taggedSize == kDynamicAllocSizeTag) ? 160 : taggedSize;
            RouterRefMemoryRouter* router = static_cast<RouterRefMemoryRouter*>(g_tlsGetValue(g_memoryRouterTlsSlot));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalSizedDelete(object, 160ull);
        }
    }
    return object;
}

void* RouterRefMemberDeallocators::Deletebbbf00(RefNodeWithTargetAt60* object, unsigned int deleteFlags)
{
    if (object->refTarget != nullptr)
    {
        RemoveReferencedObject(object->refTarget);
    }
    object->refTarget = nullptr;
    DestroyOwnedStringPtr(&object->name);
    DestroyBindableBase(object);
    if ((deleteFlags & kDeleteMemoryFlag) != 0u)
    {
        if ((deleteFlags & kGlobalDeleteFlag) == 0u)
        {
            unsigned short taggedSize = object->memSizeAndFlags;
            int allocSize = (taggedSize == kDynamicAllocSizeTag) ? 112 : taggedSize;
            RouterRefMemoryRouter* router = static_cast<RouterRefMemoryRouter*>(g_tlsGetValue(g_memoryRouterTlsSlot));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalSizedDelete(object, 112ull);
        }
    }
    return object;
}
