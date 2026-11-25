// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original polymorphic table-reset wrapper template.
// TableCleanupDeallocators, PolymorphicObject, methods and targets: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
// 0x63cce0 TableCleanupDeallocators::Delete63cce0
// 0x12b3a80 TableCleanupDeallocators::Delete12b3a80
#include "TableCleanupDeallocators.h"

void* TableCleanupDeallocators::Delete63cce0(PolymorphicObject* object, unsigned int flags)
{
    object->table = &TableTarget190c8a8;
    CleanupTarget63cab0(object);
    if ((flags & 1u) != 0u)
    {
        DeallocatorTarget15a743c(object, 72ull);
    }
    return object;
}

void* TableCleanupDeallocators::Delete12b3a80(PolymorphicObject* object, unsigned int flags)
{
    object->table = &TableTarget1ad92b8;
    CleanupTarget12b3560(object);
    if ((flags & 1u) != 0u)
    {
        DeallocatorTarget15a743c(object, 160ull);
    }
    return object;
}
