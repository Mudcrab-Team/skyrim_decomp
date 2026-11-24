// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original custom-allocator deleting-destructor template.
// HeapFiveTableDeallocators, types, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
// 0xddd7c0 HeapFiveTableDeallocators::Deleteddd7c0
// 0xddd930 HeapFiveTableDeallocators::Deleteddd930
// 0xdde7d0 HeapFiveTableDeallocators::Deletedde7d0
// 0xdde940 HeapFiveTableDeallocators::Deletedde940
// 0xde0620 HeapFiveTableDeallocators::Deletede0620
// 0xde0790 HeapFiveTableDeallocators::Deletede0790
// 0xde1fe0 HeapFiveTableDeallocators::Deletede1fe0
// 0xde2150 HeapFiveTableDeallocators::Deletede2150
// 0xde3300 HeapFiveTableDeallocators::Deletede3300
// 0xde3470 HeapFiveTableDeallocators::Deletede3470
// 0xde52e0 HeapFiveTableDeallocators::Deletede52e0
// 0xde5450 HeapFiveTableDeallocators::Deletede5450
#include "HeapFiveTableDeallocators.h"

void* HeapFiveTableDeallocators::Deleteddd7c0(HeapFiveTableDeallocatorsTripleTableObject20_108* object, unsigned int flags)
{
    object->table0 = TableTarget1a39a98;
    object->table1 = TableTarget1a39ae0;
    object->table2 = TableTarget1a39b88;
    CleanupTargetd11840(&object->table2);
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
            GlobalDeallocTarget1177a80(object, 328ull);
        }
    }
    return object;
}

void* HeapFiveTableDeallocators::Deleteddd930(HeapFiveTableDeallocatorsTripleTableObject20_108* object, unsigned int flags)
{
    object->table0 = TableTarget1a39a98;
    object->table1 = TableTarget1a39ae0;
    object->table2 = TableTarget1a39b88;
    CleanupTargetd11840(&object->table2);
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
            GlobalDeallocTarget1177a80(object, 328ull);
        }
    }
    return object;
}

void* HeapFiveTableDeallocators::Deletedde7d0(HeapFiveTableDeallocatorsTripleTableObject20_108* object, unsigned int flags)
{
    object->table0 = TableTarget1a39ec8;
    object->table1 = TableTarget1a39f10;
    object->table2 = TableTarget1a39fb8;
    CleanupTargetd11840(&object->table2);
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
            GlobalDeallocTarget1177a80(object, 328ull);
        }
    }
    return object;
}

void* HeapFiveTableDeallocators::Deletedde940(HeapFiveTableDeallocatorsTripleTableObject20_108* object, unsigned int flags)
{
    object->table0 = TableTarget1a39ec8;
    object->table1 = TableTarget1a39f10;
    object->table2 = TableTarget1a39fb8;
    CleanupTargetd11840(&object->table2);
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
            GlobalDeallocTarget1177a80(object, 328ull);
        }
    }
    return object;
}

void* HeapFiveTableDeallocators::Deletede0620(HeapFiveTableDeallocatorsTripleTableObject20_108* object, unsigned int flags)
{
    object->table0 = TableTarget1a3a338;
    object->table1 = TableTarget1a3a380;
    object->table2 = TableTarget1a3a428;
    CleanupTargetd11840(&object->table2);
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
            GlobalDeallocTarget1177a80(object, 328ull);
        }
    }
    return object;
}

void* HeapFiveTableDeallocators::Deletede0790(HeapFiveTableDeallocatorsTripleTableObject20_108* object, unsigned int flags)
{
    object->table0 = TableTarget1a3a338;
    object->table1 = TableTarget1a3a380;
    object->table2 = TableTarget1a3a428;
    CleanupTargetd11840(&object->table2);
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
            GlobalDeallocTarget1177a80(object, 328ull);
        }
    }
    return object;
}

void* HeapFiveTableDeallocators::Deletede1fe0(HeapFiveTableDeallocatorsTripleTableObject20_108* object, unsigned int flags)
{
    object->table0 = TableTarget1a3a768;
    object->table1 = TableTarget1a3a7b0;
    object->table2 = TableTarget1a3a858;
    CleanupTargetd11840(&object->table2);
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
            GlobalDeallocTarget1177a80(object, 328ull);
        }
    }
    return object;
}

void* HeapFiveTableDeallocators::Deletede2150(HeapFiveTableDeallocatorsTripleTableObject20_108* object, unsigned int flags)
{
    object->table0 = TableTarget1a3a768;
    object->table1 = TableTarget1a3a7b0;
    object->table2 = TableTarget1a3a858;
    CleanupTargetd11840(&object->table2);
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
            GlobalDeallocTarget1177a80(object, 328ull);
        }
    }
    return object;
}

void* HeapFiveTableDeallocators::Deletede3300(HeapFiveTableDeallocatorsTripleTableObject20_108* object, unsigned int flags)
{
    object->table0 = TableTarget1a3ab98;
    object->table1 = TableTarget1a3abe0;
    object->table2 = TableTarget1a3ac88;
    CleanupTargetd11840(&object->table2);
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
            GlobalDeallocTarget1177a80(object, 328ull);
        }
    }
    return object;
}

void* HeapFiveTableDeallocators::Deletede3470(HeapFiveTableDeallocatorsTripleTableObject20_108* object, unsigned int flags)
{
    object->table0 = TableTarget1a3ab98;
    object->table1 = TableTarget1a3abe0;
    object->table2 = TableTarget1a3ac88;
    CleanupTargetd11840(&object->table2);
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
            GlobalDeallocTarget1177a80(object, 328ull);
        }
    }
    return object;
}

void* HeapFiveTableDeallocators::Deletede52e0(HeapFiveTableDeallocatorsTripleTableObject20_108* object, unsigned int flags)
{
    object->table0 = TableTarget1a3aff0;
    object->table1 = TableTarget1a3b038;
    object->table2 = TableTarget1a3b0e0;
    CleanupTargetd11840(&object->table2);
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
            GlobalDeallocTarget1177a80(object, 328ull);
        }
    }
    return object;
}

void* HeapFiveTableDeallocators::Deletede5450(HeapFiveTableDeallocatorsTripleTableObject20_108* object, unsigned int flags)
{
    object->table0 = TableTarget1a3aff0;
    object->table1 = TableTarget1a3b038;
    object->table2 = TableTarget1a3b0e0;
    CleanupTargetd11840(&object->table2);
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
            GlobalDeallocTarget1177a80(object, 328ull);
        }
    }
    return object;
}
