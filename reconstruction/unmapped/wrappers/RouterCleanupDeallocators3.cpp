// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original custom-allocator deleting-destructor template.
// RouterCleanupDeallocators3, types, methods and referenced symbols: GUESS(low) STANDIN
// Adapted bodies: none
// 0xbafb10 RouterCleanupDeallocators3::Deletebafb10
// 0xbb54b0 RouterCleanupDeallocators3::Deletebb54b0
// CI hash: 0xbafb10 ?Deletebafb10@RouterCleanupDeallocators3@@SAPEAXPEAURouterCleanupDeallocators3TaggedObject@@I@Z
// CI hash: 0xbb54b0 ?Deletebb54b0@RouterCleanupDeallocators3@@SAPEAXPEAURouterCleanupDeallocators3TaggedObject@@I@Z
#include "RouterCleanupDeallocators3.h"

void* RouterCleanupDeallocators3::Deletebafb10(RouterCleanupDeallocators3TaggedObject* object, unsigned int flags)
{
    CleanupTargetbaf420(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 112 : tagged;
            RouterCleanupDeallocators3MemoryRouter* router = static_cast<RouterCleanupDeallocators3MemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 112ull);
        }
    }
    return object;
}

void* RouterCleanupDeallocators3::Deletebb54b0(RouterCleanupDeallocators3TaggedObject* object, unsigned int flags)
{
    CleanupTargetbb5400(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            unsigned short tagged = object->memSizeAndFlags;
            int allocSize = (tagged == 0xffffu) ? 176 : tagged;
            RouterCleanupDeallocators3MemoryRouter* router = static_cast<RouterCleanupDeallocators3MemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 176ull);
        }
    }
    return object;
}
