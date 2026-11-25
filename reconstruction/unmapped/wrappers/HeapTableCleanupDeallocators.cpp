// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original custom-allocator deleting-destructor template.
// HeapTableCleanupDeallocators, types, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
// 0xd41670 HeapTableCleanupDeallocators::Deleted41670
// 0xd7d7a0 HeapTableCleanupDeallocators::Deleted7d7a0
// 0xd8eab0 HeapTableCleanupDeallocators::Deleted8eab0
// 0xdf2620 HeapTableCleanupDeallocators::Deletedf2620
// 0xdf3d30 HeapTableCleanupDeallocators::Deletedf3d30
// 0xe18880 HeapTableCleanupDeallocators::Deletee18880
// 0xe55b20 HeapTableCleanupDeallocators::Deletee55b20
// 0xe9bf70 HeapTableCleanupDeallocators::Deletee9bf70
// 0x1180ae0 HeapTableCleanupDeallocators::Delete1180ae0
// CI hash: 0xd8eab0 ?Deleted8eab0@HeapTableCleanupDeallocators@@SAPEAXPEAUHeapTableCleanupDeallocatorsTableObject@@I@Z
#include "HeapTableCleanupDeallocators.h"

void* HeapTableCleanupDeallocators::Deleted41670(HeapTableCleanupDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1a2aa40;
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 24ull);
        }
    }
    return object;
}

void* HeapTableCleanupDeallocators::Deleted7d7a0(HeapTableCleanupDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1a2dc50;
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* HeapTableCleanupDeallocators::Deleted8eab0(HeapTableCleanupDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1a9a998;
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 24ull);
        }
    }
    return object;
}

void* HeapTableCleanupDeallocators::Deletedf2620(HeapTableCleanupDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1a9a998;
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 32ull);
        }
    }
    return object;
}

void* HeapTableCleanupDeallocators::Deletedf3d30(HeapTableCleanupDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1a9a998;
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 32ull);
        }
    }
    return object;
}

void* HeapTableCleanupDeallocators::Deletee18880(HeapTableCleanupDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1a3de90;
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 32ull);
        }
    }
    return object;
}

void* HeapTableCleanupDeallocators::Deletee55b20(HeapTableCleanupDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1a3f538;
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* HeapTableCleanupDeallocators::Deletee9bf70(HeapTableCleanupDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1a40808;
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* HeapTableCleanupDeallocators::Delete1180ae0(HeapTableCleanupDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1a9c8b0;
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}
