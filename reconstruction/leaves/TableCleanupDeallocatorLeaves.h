// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original polymorphic table-reset wrapper template.
// TableCleanupDeallocatorLeaves, PolymorphicObject, methods and targets: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

struct PolymorphicObject
{
    const void* table;
};

extern "C" const unsigned char TableTarget191b448;
extern "C" void CleanupTarget1215fa0(PolymorphicObject* object);
extern "C" void DeallocatorTarget15a743c(void* object, unsigned long long size);

struct TableCleanupDeallocatorLeaves
{
    static void* Delete6e1ad0(PolymorphicObject* object, unsigned int flags);
};
