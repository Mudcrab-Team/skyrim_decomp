// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original polymorphic table-reset wrapper template.
// TableCleanupDeallocators, PolymorphicObject, methods and targets: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

struct PolymorphicObject
{
    const void* table;
};

extern "C" const unsigned char TableTarget190c8a8;
extern "C" const unsigned char TableTarget1ad92b8;
extern "C" void CleanupTarget63cab0(PolymorphicObject* object);
extern "C" void CleanupTarget12b3560(PolymorphicObject* object);
extern "C" void DeallocatorTarget15a743c(void* object, unsigned long long size);

struct TableCleanupDeallocators
{
    static void* Delete63cce0(PolymorphicObject* object, unsigned int flags);
    static void* Delete12b3a80(PolymorphicObject* object, unsigned int flags);
};
