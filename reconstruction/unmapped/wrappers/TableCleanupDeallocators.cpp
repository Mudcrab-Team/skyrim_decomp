// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original polymorphic table-reset wrapper template.
// TableCleanupDeallocators, PolymorphicObject, methods and targets: GUESS(low) STANDIN
// Adapted bodies: none
// 0x4e35f0 TableCleanupDeallocators::Delete4e35f0
// 0x80f8f0 TableCleanupDeallocators::Delete80f8f0
// 0x80f970 TableCleanupDeallocators::Delete80f970
// 0xcfad30 TableCleanupDeallocators::Deletecfad30
// 0x14e8af0 TableCleanupDeallocators::Delete14e8af0
#include "TableCleanupDeallocators.h"

void* TableCleanupDeallocators::Delete4e35f0(PolymorphicObject* object, unsigned int flags)
{
    object->table = &TableTarget18dd9d8;
    CleanupTarget11cb9c0(object);
    if ((flags & 1u) != 0u)
    {
        DeallocatorTarget15a743c(object, 256ull);
    }
    return object;
}

void* TableCleanupDeallocators::Delete80f8f0(PolymorphicObject* object, unsigned int flags)
{
    object->table = &TableTarget1944790;
    CleanupTarget854f30(object);
    if ((flags & 1u) != 0u)
    {
        DeallocatorTarget15a743c(object, 96ull);
    }
    return object;
}

void* TableCleanupDeallocators::Delete80f970(PolymorphicObject* object, unsigned int flags)
{
    object->table = &TableTarget1944790;
    CleanupTarget854f30(object);
    if ((flags & 1u) != 0u)
    {
        DeallocatorTarget15a743c(object, 96ull);
    }
    return object;
}

void* TableCleanupDeallocators::Deletecfad30(PolymorphicObject* object, unsigned int flags)
{
    object->table = &TableTarget1a23ca8;
    CleanupTargetd028f0(object);
    if ((flags & 1u) != 0u)
    {
        DeallocatorTarget15a743c(object, 200ull);
    }
    return object;
}

void* TableCleanupDeallocators::Delete14e8af0(PolymorphicObject* object, unsigned int flags)
{
    object->table = &TableTarget1b2f5d0;
    CleanupTarget14e5e90(object);
    if ((flags & 1u) != 0u)
    {
        DeallocatorTarget15a743c(object, 368ull);
    }
    return object;
}
