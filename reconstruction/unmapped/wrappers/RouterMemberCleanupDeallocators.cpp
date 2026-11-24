// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original custom-allocator deleting-destructor template.
// RouterMemberCleanupDeallocators, types, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
// 0xad1d70 RouterMemberCleanupDeallocators::Deletead1d70
// 0xad1e00 RouterMemberCleanupDeallocators::Deletead1e00
// 0xae2240 RouterMemberCleanupDeallocators::Deleteae2240
// 0xae2530 RouterMemberCleanupDeallocators::Deleteae2530
// 0xae26d0 RouterMemberCleanupDeallocators::Deleteae26d0
// 0xae27f0 RouterMemberCleanupDeallocators::Deleteae27f0
// 0xae2910 RouterMemberCleanupDeallocators::Deleteae2910
// 0xae2ac0 RouterMemberCleanupDeallocators::Deleteae2ac0
// 0xae3630 RouterMemberCleanupDeallocators::Deleteae3630
// 0xae3a70 RouterMemberCleanupDeallocators::Deleteae3a70
// 0xae3b90 RouterMemberCleanupDeallocators::Deleteae3b90
// 0xae40f0 RouterMemberCleanupDeallocators::Deleteae40f0
// 0xae4320 RouterMemberCleanupDeallocators::Deleteae4320
// 0xae4470 RouterMemberCleanupDeallocators::Deleteae4470
// 0xae46e0 RouterMemberCleanupDeallocators::Deleteae46e0
// 0xae4eb0 RouterMemberCleanupDeallocators::Deleteae4eb0
// 0xae5090 RouterMemberCleanupDeallocators::Deleteae5090
// 0xae5440 RouterMemberCleanupDeallocators::Deleteae5440
// 0xae5830 RouterMemberCleanupDeallocators::Deleteae5830
// 0xae5950 RouterMemberCleanupDeallocators::Deleteae5950
// 0xbb5920 RouterMemberCleanupDeallocators::Deletebb5920
// 0xbb6280 RouterMemberCleanupDeallocators::Deletebb6280
// 0xbb64e0 RouterMemberCleanupDeallocators::Deletebb64e0
// 0xbb8130 RouterMemberCleanupDeallocators::Deletebb8130
// 0xbb83e0 RouterMemberCleanupDeallocators::Deletebb83e0
// 0xbb86c0 RouterMemberCleanupDeallocators::Deletebb86c0
// 0xbb9b20 RouterMemberCleanupDeallocators::Deletebb9b20
// 0xbbbb40 RouterMemberCleanupDeallocators::Deletebbbb40
// 0xbbc4c0 RouterMemberCleanupDeallocators::Deletebbc4c0
#include "RouterMemberCleanupDeallocators.h"

void* RouterMemberCleanupDeallocators::Deletead1d70(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 72 : tagged;
            RouterMemberCleanupDeallocatorsMemoryRouter* router = static_cast<RouterMemberCleanupDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 72ull);
        }
    }
    return object;
}

void* RouterMemberCleanupDeallocators::Deletead1e00(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 72 : tagged;
            RouterMemberCleanupDeallocatorsMemoryRouter* router = static_cast<RouterMemberCleanupDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 72ull);
        }
    }
    return object;
}

void* RouterMemberCleanupDeallocators::Deleteae2240(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 176 : tagged;
            RouterMemberCleanupDeallocatorsMemoryRouter* router = static_cast<RouterMemberCleanupDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 176ull);
        }
    }
    return object;
}

void* RouterMemberCleanupDeallocators::Deleteae2530(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 192 : tagged;
            RouterMemberCleanupDeallocatorsMemoryRouter* router = static_cast<RouterMemberCleanupDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 192ull);
        }
    }
    return object;
}

void* RouterMemberCleanupDeallocators::Deleteae26d0(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 144 : tagged;
            RouterMemberCleanupDeallocatorsMemoryRouter* router = static_cast<RouterMemberCleanupDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 144ull);
        }
    }
    return object;
}

void* RouterMemberCleanupDeallocators::Deleteae27f0(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 128 : tagged;
            RouterMemberCleanupDeallocatorsMemoryRouter* router = static_cast<RouterMemberCleanupDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 128ull);
        }
    }
    return object;
}

void* RouterMemberCleanupDeallocators::Deleteae2910(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 192 : tagged;
            RouterMemberCleanupDeallocatorsMemoryRouter* router = static_cast<RouterMemberCleanupDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 192ull);
        }
    }
    return object;
}

void* RouterMemberCleanupDeallocators::Deleteae2ac0(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 192 : tagged;
            RouterMemberCleanupDeallocatorsMemoryRouter* router = static_cast<RouterMemberCleanupDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 192ull);
        }
    }
    return object;
}

void* RouterMemberCleanupDeallocators::Deleteae3630(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 88 : tagged;
            RouterMemberCleanupDeallocatorsMemoryRouter* router = static_cast<RouterMemberCleanupDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 88ull);
        }
    }
    return object;
}

void* RouterMemberCleanupDeallocators::Deleteae3a70(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 128 : tagged;
            RouterMemberCleanupDeallocatorsMemoryRouter* router = static_cast<RouterMemberCleanupDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 128ull);
        }
    }
    return object;
}

void* RouterMemberCleanupDeallocators::Deleteae3b90(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 112 : tagged;
            RouterMemberCleanupDeallocatorsMemoryRouter* router = static_cast<RouterMemberCleanupDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 112ull);
        }
    }
    return object;
}

void* RouterMemberCleanupDeallocators::Deleteae40f0(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 240 : tagged;
            RouterMemberCleanupDeallocatorsMemoryRouter* router = static_cast<RouterMemberCleanupDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 240ull);
        }
    }
    return object;
}

void* RouterMemberCleanupDeallocators::Deleteae4320(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 88 : tagged;
            RouterMemberCleanupDeallocatorsMemoryRouter* router = static_cast<RouterMemberCleanupDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 88ull);
        }
    }
    return object;
}

void* RouterMemberCleanupDeallocators::Deleteae4470(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 80 : tagged;
            RouterMemberCleanupDeallocatorsMemoryRouter* router = static_cast<RouterMemberCleanupDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 80ull);
        }
    }
    return object;
}

void* RouterMemberCleanupDeallocators::Deleteae46e0(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 112 : tagged;
            RouterMemberCleanupDeallocatorsMemoryRouter* router = static_cast<RouterMemberCleanupDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 112ull);
        }
    }
    return object;
}

void* RouterMemberCleanupDeallocators::Deleteae4eb0(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 80 : tagged;
            RouterMemberCleanupDeallocatorsMemoryRouter* router = static_cast<RouterMemberCleanupDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 80ull);
        }
    }
    return object;
}

void* RouterMemberCleanupDeallocators::Deleteae5090(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 128 : tagged;
            RouterMemberCleanupDeallocatorsMemoryRouter* router = static_cast<RouterMemberCleanupDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 128ull);
        }
    }
    return object;
}

void* RouterMemberCleanupDeallocators::Deleteae5440(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 128 : tagged;
            RouterMemberCleanupDeallocatorsMemoryRouter* router = static_cast<RouterMemberCleanupDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 128ull);
        }
    }
    return object;
}

void* RouterMemberCleanupDeallocators::Deleteae5830(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 160 : tagged;
            RouterMemberCleanupDeallocatorsMemoryRouter* router = static_cast<RouterMemberCleanupDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 160ull);
        }
    }
    return object;
}

void* RouterMemberCleanupDeallocators::Deleteae5950(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 80 : tagged;
            RouterMemberCleanupDeallocatorsMemoryRouter* router = static_cast<RouterMemberCleanupDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 80ull);
        }
    }
    return object;
}

void* RouterMemberCleanupDeallocators::Deletebb5920(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 96 : tagged;
            RouterMemberCleanupDeallocatorsMemoryRouter* router = static_cast<RouterMemberCleanupDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 96ull);
        }
    }
    return object;
}

void* RouterMemberCleanupDeallocators::Deletebb6280(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 160 : tagged;
            RouterMemberCleanupDeallocatorsMemoryRouter* router = static_cast<RouterMemberCleanupDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 160ull);
        }
    }
    return object;
}

void* RouterMemberCleanupDeallocators::Deletebb64e0(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 112 : tagged;
            RouterMemberCleanupDeallocatorsMemoryRouter* router = static_cast<RouterMemberCleanupDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 112ull);
        }
    }
    return object;
}

void* RouterMemberCleanupDeallocators::Deletebb8130(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 88 : tagged;
            RouterMemberCleanupDeallocatorsMemoryRouter* router = static_cast<RouterMemberCleanupDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 88ull);
        }
    }
    return object;
}

void* RouterMemberCleanupDeallocators::Deletebb83e0(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 104 : tagged;
            RouterMemberCleanupDeallocatorsMemoryRouter* router = static_cast<RouterMemberCleanupDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 104ull);
        }
    }
    return object;
}

void* RouterMemberCleanupDeallocators::Deletebb86c0(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 96 : tagged;
            RouterMemberCleanupDeallocatorsMemoryRouter* router = static_cast<RouterMemberCleanupDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 96ull);
        }
    }
    return object;
}

void* RouterMemberCleanupDeallocators::Deletebb9b20(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 120 : tagged;
            RouterMemberCleanupDeallocatorsMemoryRouter* router = static_cast<RouterMemberCleanupDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 120ull);
        }
    }
    return object;
}

void* RouterMemberCleanupDeallocators::Deletebbbb40(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 96 : tagged;
            RouterMemberCleanupDeallocatorsMemoryRouter* router = static_cast<RouterMemberCleanupDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 96ull);
        }
    }
    return object;
}

void* RouterMemberCleanupDeallocators::Deletebbc4c0(RouterMemberCleanupDeallocatorsMemberObject38* object, unsigned int flags)
{
    CleanupTargetaa77d0(object->member38);
    CleanupTargetad1a70(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 208 : tagged;
            RouterMemberCleanupDeallocatorsMemoryRouter* router = static_cast<RouterMemberCleanupDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 208ull);
        }
    }
    return object;
}
