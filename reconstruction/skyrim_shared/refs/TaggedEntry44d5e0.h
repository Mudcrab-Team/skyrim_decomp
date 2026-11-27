// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing; names as labelled below
// Adapted bodies: none
// PolymorphicBase, TaggedEntry44d5e0, DiffersFrom, field08: GUESS(low) STANDIN
// Projectile::RemoveItem: CRASHLOGGER_PDB(59818@2026.10.24) GUESS(low); that name does not fit the dynamic_cast and 64-bit tagged-value comparison used here, so the class and method use stand-in names.
#pragma once

#include <cstddef>
#include <cstdint>

class PolymorphicBase
{
public:
    virtual ~PolymorphicBase();
};

class TaggedEntry44d5e0 : public PolymorphicBase
{
public:
    bool DiffersFrom(PolymorphicBase* other) const;  // compared: 0x44d5e0

    std::uint64_t field08;  // 08
};
static_assert(offsetof(TaggedEntry44d5e0, field08) == 0x08, "field08 offset");
