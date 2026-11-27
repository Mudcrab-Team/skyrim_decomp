// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing; names as labelled below
// Adapted bodies: none
// PolymorphicBase, ValueEntry44e990, CopyFrom, unknown08, field10: GUESS(low) STANDIN
// Projectile::GetCurrentAmmo: CRASHLOGGER_PDB(59818@2026.10.24) GUESS(low); that name does not fit the dynamic_cast and 32-bit field copy used here, so the class and method use stand-in names.
#pragma once

#include <cstddef>
#include <cstdint>

class PolymorphicBase
{
public:
    virtual ~PolymorphicBase();
};

class ValueEntry44e990 : public PolymorphicBase
{
public:
    void CopyFrom(PolymorphicBase* other);  // compared: 0x44e990

    std::uint8_t  unknown08[0x08];  // 08
    std::uint32_t field10;          // 10
};
static_assert(offsetof(ValueEntry44e990, field10) == 0x10, "field10 offset");
