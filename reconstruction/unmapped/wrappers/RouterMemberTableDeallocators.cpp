// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original custom-allocator deleting-destructor template.
// RouterMemberTableDeallocators, types, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
// 0xaaa370 RouterMemberTableDeallocators::Deleteaaa370
// 0xae4800 RouterMemberTableDeallocators::Deleteae4800
// 0xae4890 RouterMemberTableDeallocators::Deleteae4890
// 0xae4920 RouterMemberTableDeallocators::Deleteae4920
// 0xae55e0 RouterMemberTableDeallocators::Deleteae55e0
// 0xae5670 RouterMemberTableDeallocators::Deleteae5670
// 0xb2e460 RouterMemberTableDeallocators::Deleteb2e460
// 0xb2e700 RouterMemberTableDeallocators::Deleteb2e700
// 0xb2eb20 RouterMemberTableDeallocators::Deleteb2eb20
// 0xca1d40 RouterMemberTableDeallocators::Deleteca1d40
// 0xcc8180 RouterMemberTableDeallocators::Deletecc8180
// 0x10d1d00 RouterMemberTableDeallocators::Delete10d1d00
// 0x10d2320 RouterMemberTableDeallocators::Delete10d2320
#include "RouterMemberTableDeallocators.h"

void* RouterMemberTableDeallocators::Deleteaaa370(RouterMemberTableDeallocatorsMemberObject10* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member10);
    object->table = TableTarget1820b98;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 24 : tagged;
            RouterMemberTableDeallocatorsMemoryRouter* router = static_cast<RouterMemberTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 24ull);
        }
    }
    return object;
}

void* RouterMemberTableDeallocators::Deleteae4800(RouterMemberTableDeallocatorsMemberObject10* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member10);
    object->table = TableTarget1820b98;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 24 : tagged;
            RouterMemberTableDeallocatorsMemoryRouter* router = static_cast<RouterMemberTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 24ull);
        }
    }
    return object;
}

void* RouterMemberTableDeallocators::Deleteae4890(RouterMemberTableDeallocatorsMemberObject10* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member10);
    object->table = TableTarget1820b98;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 32 : tagged;
            RouterMemberTableDeallocatorsMemoryRouter* router = static_cast<RouterMemberTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 32ull);
        }
    }
    return object;
}

void* RouterMemberTableDeallocators::Deleteae4920(RouterMemberTableDeallocatorsMemberObject10* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member10);
    object->table = TableTarget1820b98;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 32 : tagged;
            RouterMemberTableDeallocatorsMemoryRouter* router = static_cast<RouterMemberTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 32ull);
        }
    }
    return object;
}

void* RouterMemberTableDeallocators::Deleteae55e0(RouterMemberTableDeallocatorsMemberObject10* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member10);
    object->table = TableTarget1820b98;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 24 : tagged;
            RouterMemberTableDeallocatorsMemoryRouter* router = static_cast<RouterMemberTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 24ull);
        }
    }
    return object;
}

void* RouterMemberTableDeallocators::Deleteae5670(RouterMemberTableDeallocatorsMemberObject10* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member10);
    object->table = TableTarget1820b98;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 24 : tagged;
            RouterMemberTableDeallocatorsMemoryRouter* router = static_cast<RouterMemberTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 24ull);
        }
    }
    return object;
}

void* RouterMemberTableDeallocators::Deleteb2e460(RouterMemberTableDeallocatorsMemberObject18* object, unsigned int flags)
{
    CleanupTargetab55b0(object->member18);
    object->table = TableTarget1820b98;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 48 : tagged;
            RouterMemberTableDeallocatorsMemoryRouter* router = static_cast<RouterMemberTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 48ull);
        }
    }
    return object;
}

void* RouterMemberTableDeallocators::Deleteb2e700(RouterMemberTableDeallocatorsMemberObject18* object, unsigned int flags)
{
    CleanupTargetab55b0(object->member18);
    object->table = TableTarget1820b98;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 56 : tagged;
            RouterMemberTableDeallocatorsMemoryRouter* router = static_cast<RouterMemberTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 56ull);
        }
    }
    return object;
}

void* RouterMemberTableDeallocators::Deleteb2eb20(RouterMemberTableDeallocatorsMemberObject10* object, unsigned int flags)
{
    CleanupTargetab55b0(object->member10);
    object->table = TableTarget1820b98;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 48 : tagged;
            RouterMemberTableDeallocatorsMemoryRouter* router = static_cast<RouterMemberTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 48ull);
        }
    }
    return object;
}

void* RouterMemberTableDeallocators::Deleteca1d40(RouterMemberTableDeallocatorsMemberObject20* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member20);
    object->table = TableTarget1820b98;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 40 : tagged;
            RouterMemberTableDeallocatorsMemoryRouter* router = static_cast<RouterMemberTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 40ull);
        }
    }
    return object;
}

void* RouterMemberTableDeallocators::Deletecc8180(RouterMemberTableDeallocatorsMemberObject10* object, unsigned int flags)
{
    CleanupTargetcc08a0(object->member10);
    object->table = TableTarget1820b98;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 88 : tagged;
            RouterMemberTableDeallocatorsMemoryRouter* router = static_cast<RouterMemberTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 88ull);
        }
    }
    return object;
}

void* RouterMemberTableDeallocators::Delete10d1d00(RouterMemberTableDeallocatorsMemberObject18* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member18);
    object->table = TableTarget1820b98;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 48 : tagged;
            RouterMemberTableDeallocatorsMemoryRouter* router = static_cast<RouterMemberTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 48ull);
        }
    }
    return object;
}

void* RouterMemberTableDeallocators::Delete10d2320(RouterMemberTableDeallocatorsMemberObject18* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member18);
    object->table = TableTarget1820b98;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 32 : tagged;
            RouterMemberTableDeallocatorsMemoryRouter* router = static_cast<RouterMemberTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 32ull);
        }
    }
    return object;
}
