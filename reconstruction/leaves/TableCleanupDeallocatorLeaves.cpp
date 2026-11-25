// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original polymorphic table-reset wrapper template.
// TableCleanupDeallocatorLeaves, PolymorphicObject, methods and targets: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
// 0x6e1ad0 TableCleanupDeallocatorLeaves::Delete6e1ad0
// CI hash: 0x6e1ad0 ?Delete6e1ad0@TableCleanupDeallocatorLeaves@@SAPEAXPEAUPolymorphicObject@@I@Z
#include "TableCleanupDeallocatorLeaves.h"

void* TableCleanupDeallocatorLeaves::Delete6e1ad0(PolymorphicObject* object, unsigned int flags)
{
    object->table = &TableTarget191b448;
    CleanupTarget1215fa0(object);
    if ((flags & 1u) != 0u)
    {
        DeallocatorTarget15a743c(object, 16ull);
    }
    return object;
}
