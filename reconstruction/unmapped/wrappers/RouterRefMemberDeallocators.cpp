// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original custom-allocator deleting-destructor template.
// RouterRefMemberDeallocators, types, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
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
#include "RouterRefMemberDeallocators.h"

void* RouterRefMemberDeallocators::Deleteae2be0(RouterRefMemberDeallocatorsRefMemberObject38_50* object, unsigned int flags)
{
    if (object->refObj != nullptr)
    {
        CleanupTargetaa2770(object->refObj);
    }
    object->refObj = nullptr;
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 104 : tagged;
            RouterRefMemberDeallocatorsMemoryRouter* router = static_cast<RouterRefMemberDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 104ull);
        }
    }
    return object;
}

void* RouterRefMemberDeallocators::Deleteae2d10(RouterRefMemberDeallocatorsRefMemberObject38_58* object, unsigned int flags)
{
    if (object->refObj != nullptr)
    {
        CleanupTargetaa2770(object->refObj);
    }
    object->refObj = nullptr;
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 120 : tagged;
            RouterRefMemberDeallocatorsMemoryRouter* router = static_cast<RouterRefMemberDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 120ull);
        }
    }
    return object;
}

void* RouterRefMemberDeallocators::Deleteae3030(RouterRefMemberDeallocatorsRefMemberObject38_50* object, unsigned int flags)
{
    if (object->refObj != nullptr)
    {
        CleanupTargetaa2770(object->refObj);
    }
    object->refObj = nullptr;
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 104 : tagged;
            RouterRefMemberDeallocatorsMemoryRouter* router = static_cast<RouterRefMemberDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 104ull);
        }
    }
    return object;
}

void* RouterRefMemberDeallocators::Deleteae3890(RouterRefMemberDeallocatorsRefMemberObject38_50* object, unsigned int flags)
{
    if (object->refObj != nullptr)
    {
        CleanupTargetaa2770(object->refObj);
    }
    object->refObj = nullptr;
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 144 : tagged;
            RouterRefMemberDeallocatorsMemoryRouter* router = static_cast<RouterRefMemberDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 144ull);
        }
    }
    return object;
}

void* RouterRefMemberDeallocators::Deleteae4640(RouterRefMemberDeallocatorsRefMemberObject38_50* object, unsigned int flags)
{
    if (object->refObj != nullptr)
    {
        CleanupTargetaa2770(object->refObj);
    }
    object->refObj = nullptr;
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 88 : tagged;
            RouterRefMemberDeallocatorsMemoryRouter* router = static_cast<RouterRefMemberDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 88ull);
        }
    }
    return object;
}

void* RouterRefMemberDeallocators::Deleteae4ca0(RouterRefMemberDeallocatorsRefMemberObject38_f8* object, unsigned int flags)
{
    if (object->refObj != nullptr)
    {
        CleanupTargetaa2770(object->refObj);
    }
    object->refObj = nullptr;
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 288 : tagged;
            RouterRefMemberDeallocatorsMemoryRouter* router = static_cast<RouterRefMemberDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 288ull);
        }
    }
    return object;
}

void* RouterRefMemberDeallocators::Deleteae4fe0(RouterRefMemberDeallocatorsRefMemberObject38_90* object, unsigned int flags)
{
    if (object->refObj != nullptr)
    {
        CleanupTargetaa2770(object->refObj);
    }
    object->refObj = nullptr;
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 160 : tagged;
            RouterRefMemberDeallocatorsMemoryRouter* router = static_cast<RouterRefMemberDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 160ull);
        }
    }
    return object;
}

void* RouterRefMemberDeallocators::Deleteae5700(RouterRefMemberDeallocatorsRefMemberObject38_60* object, unsigned int flags)
{
    if (object->refObj != nullptr)
    {
        CleanupTargetaa2770(object->refObj);
    }
    object->refObj = nullptr;
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 112 : tagged;
            RouterRefMemberDeallocatorsMemoryRouter* router = static_cast<RouterRefMemberDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 112ull);
        }
    }
    return object;
}

void* RouterRefMemberDeallocators::Deletebb6ee0(RouterRefMemberDeallocatorsRefMemberObject38_70* object, unsigned int flags)
{
    if (object->refObj != nullptr)
    {
        CleanupTargetaa2770(object->refObj);
    }
    object->refObj = nullptr;
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 128 : tagged;
            RouterRefMemberDeallocatorsMemoryRouter* router = static_cast<RouterRefMemberDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 128ull);
        }
    }
    return object;
}

void* RouterRefMemberDeallocators::Deletebb77a0(RouterRefMemberDeallocatorsRefMemberObject38_58* object, unsigned int flags)
{
    if (object->refObj != nullptr)
    {
        CleanupTargetaa2770(object->refObj);
    }
    object->refObj = nullptr;
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 96 : tagged;
            RouterRefMemberDeallocatorsMemoryRouter* router = static_cast<RouterRefMemberDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 96ull);
        }
    }
    return object;
}

void* RouterRefMemberDeallocators::Deletebbb840(RouterRefMemberDeallocatorsRefMemberObject38_88* object, unsigned int flags)
{
    if (object->refObj != nullptr)
    {
        CleanupTargetaa2770(object->refObj);
    }
    object->refObj = nullptr;
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 160 : tagged;
            RouterRefMemberDeallocatorsMemoryRouter* router = static_cast<RouterRefMemberDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 160ull);
        }
    }
    return object;
}

void* RouterRefMemberDeallocators::Deletebbbf00(RouterRefMemberDeallocatorsRefMemberObject38_60* object, unsigned int flags)
{
    if (object->refObj != nullptr)
    {
        CleanupTargetaa2770(object->refObj);
    }
    object->refObj = nullptr;
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 112 : tagged;
            RouterRefMemberDeallocatorsMemoryRouter* router = static_cast<RouterRefMemberDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 112ull);
        }
    }
    return object;
}
