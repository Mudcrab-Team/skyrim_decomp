// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original custom-allocator deleting-destructor template.
// RouterCleanupDeallocators2, types, methods and referenced symbols: GUESS(low) STANDIN
// Adapted bodies: none
// 0xb98560 RouterCleanupDeallocators2::Deleteb98560
// 0xb99940 RouterCleanupDeallocators2::Deleteb99940
// 0xba15c0 RouterCleanupDeallocators2::Deleteba15c0
// CI hash: 0xb98560 ?Deleteb98560@RouterCleanupDeallocators2@@SAPEAXPEAURouterCleanupDeallocators2TaggedObject@@I@Z
// CI hash: 0xb99940 ?Deleteb99940@RouterCleanupDeallocators2@@SAPEAXPEAURouterCleanupDeallocators2TaggedObject@@I@Z
// CI hash: 0xba15c0 ?Deleteba15c0@RouterCleanupDeallocators2@@SAPEAXPEAURouterCleanupDeallocators2TaggedObject@@I@Z
#include "RouterCleanupDeallocators2.h"

void* RouterCleanupDeallocators2::Deleteb98560(RouterCleanupDeallocators2TaggedObject* object, unsigned int flags)
{
    CleanupTargetb98490(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 104 : tagged;
            RouterCleanupDeallocators2MemoryRouter* router = static_cast<RouterCleanupDeallocators2MemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 104ull);
        }
    }
    return object;
}

void* RouterCleanupDeallocators2::Deleteb99940(RouterCleanupDeallocators2TaggedObject* object, unsigned int flags)
{
    CleanupTargetb987a0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 144 : tagged;
            RouterCleanupDeallocators2MemoryRouter* router = static_cast<RouterCleanupDeallocators2MemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 144ull);
        }
    }
    return object;
}

void* RouterCleanupDeallocators2::Deleteba15c0(RouterCleanupDeallocators2TaggedObject* object, unsigned int flags)
{
    CleanupTargetb9cb80(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 240 : tagged;
            RouterCleanupDeallocators2MemoryRouter* router = static_cast<RouterCleanupDeallocators2MemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 240ull);
        }
    }
    return object;
}
