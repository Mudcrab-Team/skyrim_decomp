// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original custom-allocator deleting-destructor template.
// HeapDualTableDeallocators, types, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
// 0xd11cc0 HeapDualTableDeallocators::Deleted11cc0
// 0xd16530 HeapDualTableDeallocators::Deleted16530
// 0xd165a0 HeapDualTableDeallocators::Deleted165a0
// 0xd16610 HeapDualTableDeallocators::Deleted16610
// 0xd1d5a0 HeapDualTableDeallocators::Deleted1d5a0
// 0xddd8c0 HeapDualTableDeallocators::Deleteddd8c0
// 0xdde8d0 HeapDualTableDeallocators::Deletedde8d0
// 0xde0720 HeapDualTableDeallocators::Deletede0720
// 0xde20e0 HeapDualTableDeallocators::Deletede20e0
// 0xde3400 HeapDualTableDeallocators::Deletede3400
// 0xde53e0 HeapDualTableDeallocators::Deletede53e0
#include "HeapDualTableDeallocators.h"

void* HeapDualTableDeallocators::Deleted11cc0(HeapDualTableDeallocatorsDualTableObject20* object, unsigned int flags)
{
    object->table0 = TableTarget1a28010;
    object->table1 = TableTarget1a28098;
    CleanupTargetd163b0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 112ull);
        }
    }
    return object;
}

void* HeapDualTableDeallocators::Deleted16530(HeapDualTableDeallocatorsDualTableObject20* object, unsigned int flags)
{
    object->table0 = TableTarget1a28428;
    object->table1 = TableTarget1a284b0;
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 112ull);
        }
    }
    return object;
}

void* HeapDualTableDeallocators::Deleted165a0(HeapDualTableDeallocatorsDualTableObject20* object, unsigned int flags)
{
    object->table0 = TableTarget1a28428;
    object->table1 = TableTarget1a284b0;
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 112ull);
        }
    }
    return object;
}

void* HeapDualTableDeallocators::Deleted16610(HeapDualTableDeallocatorsDualTableObject20* object, unsigned int flags)
{
    object->table0 = TableTarget1a28428;
    object->table1 = TableTarget1a284b0;
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 104ull);
        }
    }
    return object;
}

void* HeapDualTableDeallocators::Deleted1d5a0(HeapDualTableDeallocatorsDualTableObject20* object, unsigned int flags)
{
    object->table0 = TableTarget1a290c0;
    object->table1 = TableTarget1a29108;
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 112ull);
        }
    }
    return object;
}

void* HeapDualTableDeallocators::Deleteddd8c0(HeapDualTableDeallocatorsDualTableObject20* object, unsigned int flags)
{
    object->table0 = TableTarget1a399a8;
    object->table1 = TableTarget1a399f0;
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 264ull);
        }
    }
    return object;
}

void* HeapDualTableDeallocators::Deletedde8d0(HeapDualTableDeallocatorsDualTableObject20* object, unsigned int flags)
{
    object->table0 = TableTarget1a39dd8;
    object->table1 = TableTarget1a39e20;
    CleanupTargetddd750(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 264ull);
        }
    }
    return object;
}

void* HeapDualTableDeallocators::Deletede0720(HeapDualTableDeallocatorsDualTableObject20* object, unsigned int flags)
{
    object->table0 = TableTarget1a3a248;
    object->table1 = TableTarget1a3a290;
    CleanupTargetddd750(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 264ull);
        }
    }
    return object;
}

void* HeapDualTableDeallocators::Deletede20e0(HeapDualTableDeallocatorsDualTableObject20* object, unsigned int flags)
{
    object->table0 = TableTarget1a3a678;
    object->table1 = TableTarget1a3a6c0;
    CleanupTargetddd750(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 264ull);
        }
    }
    return object;
}

void* HeapDualTableDeallocators::Deletede3400(HeapDualTableDeallocatorsDualTableObject20* object, unsigned int flags)
{
    object->table0 = TableTarget1a3aaa8;
    object->table1 = TableTarget1a3aaf0;
    CleanupTargetddd750(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 264ull);
        }
    }
    return object;
}

void* HeapDualTableDeallocators::Deletede53e0(HeapDualTableDeallocatorsDualTableObject20* object, unsigned int flags)
{
    object->table0 = TableTarget1a3af00;
    object->table1 = TableTarget1a3af48;
    CleanupTargetddd750(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 264ull);
        }
    }
    return object;
}
