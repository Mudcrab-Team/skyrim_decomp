// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original polymorphic table-reset wrapper template.
// TableCleanupDeallocators, PolymorphicObject, methods and targets: GUESS(low) STANDIN
// Adapted bodies: none
#pragma once

struct PolymorphicObject
{
    const void* table;
};

extern "C" const unsigned char TableTarget18dd9d8;
extern "C" const unsigned char TableTarget1944790;
extern "C" const unsigned char TableTarget1a23ca8;
extern "C" const unsigned char TableTarget1b2f5d0;
extern "C" void CleanupTarget854f30(PolymorphicObject* object);
extern "C" void CleanupTargetd028f0(PolymorphicObject* object);
extern "C" void CleanupTarget11cb9c0(PolymorphicObject* object);
extern "C" void CleanupTarget14e5e90(PolymorphicObject* object);
extern "C" void DeallocatorTarget15a743c(void* object, unsigned long long size);

struct TableCleanupDeallocators
{
    static void* Delete4e35f0(PolymorphicObject* object, unsigned int flags);
    static void* Delete80f8f0(PolymorphicObject* object, unsigned int flags);
    static void* Delete80f970(PolymorphicObject* object, unsigned int flags);
    static void* Deletecfad30(PolymorphicObject* object, unsigned int flags);
    static void* Delete14e8af0(PolymorphicObject* object, unsigned int flags);
};
