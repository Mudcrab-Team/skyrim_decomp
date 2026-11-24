// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original custom-allocator deleting-destructor template.
// HeapTableDeallocators, types, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
// 0xd0c180 HeapTableDeallocators::Deleted0c180
// 0xd0c1d0 HeapTableDeallocators::Deleted0c1d0
// 0xd11c10 HeapTableDeallocators::Deleted11c10
// 0xd1ced0 HeapTableDeallocators::Deleted1ced0
// 0xd1d8d0 HeapTableDeallocators::Deleted1d8d0
// 0xd5b300 HeapTableDeallocators::Deleted5b300
// 0xd5b350 HeapTableDeallocators::Deleted5b350
// 0xd5b4d0 HeapTableDeallocators::Deleted5b4d0
// 0xd5b520 HeapTableDeallocators::Deleted5b520
// 0xd7d560 HeapTableDeallocators::Deleted7d560
// 0xdf1780 HeapTableDeallocators::Deletedf1780
// 0xdf17d0 HeapTableDeallocators::Deletedf17d0
// 0xe6e290 HeapTableDeallocators::Deletee6e290
// 0x11a3ef0 HeapTableDeallocators::Delete11a3ef0
// 0x11a4010 HeapTableDeallocators::Delete11a4010
#include "HeapTableDeallocators.h"

void* HeapTableDeallocators::Deleted0c180(HeapTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1a27c18;
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

void* HeapTableDeallocators::Deleted0c1d0(HeapTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1a27c18;
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

void* HeapTableDeallocators::Deleted11c10(HeapTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1a27c18;
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

void* HeapTableDeallocators::Deleted1ced0(HeapTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1a27c18;
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

void* HeapTableDeallocators::Deleted1d8d0(HeapTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1a27c18;
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

void* HeapTableDeallocators::Deleted5b300(HeapTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1a2b938;
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

void* HeapTableDeallocators::Deleted5b350(HeapTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1a2b938;
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

void* HeapTableDeallocators::Deleted5b4d0(HeapTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1a2b938;
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

void* HeapTableDeallocators::Deleted5b520(HeapTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1a2b938;
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

void* HeapTableDeallocators::Deleted7d560(HeapTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1a2b938;
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

void* HeapTableDeallocators::Deletedf1780(HeapTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1a3bc78;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 40ull);
        }
    }
    return object;
}

void* HeapTableDeallocators::Deletedf17d0(HeapTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1a3bc78;
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

void* HeapTableDeallocators::Deletee6e290(HeapTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1a3bc78;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 40ull);
        }
    }
    return object;
}

void* HeapTableDeallocators::Delete11a3ef0(HeapTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1ab9490;
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

void* HeapTableDeallocators::Delete11a4010(HeapTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1ab9430;
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
