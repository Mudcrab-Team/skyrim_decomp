// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing; names as labelled below
// Adapted bodies: none
// PolymorphicBase, TaggedBase44e700, FloatEntry44e700, IsBaseDifferent, DiffersFrom, field08, field10: GUESS(low) STANDIN
// Projectile::PopulateGraphProjectsToLoad: CRASHLOGGER_PDB(59818@2026.10.24) GUESS(low); that name does not fit the two dynamic_cast checks and float field comparison used here, so the classes and methods use stand-in names.
#pragma once

#include <cstddef>
#include <cstdint>

class PolymorphicBase
{
public:
    virtual ~PolymorphicBase();
};

class TaggedBase44e700 : public PolymorphicBase
{
public:
    bool IsBaseDifferent(PolymorphicBase* other) const
    {
        auto* rhs = dynamic_cast<TaggedBase44e700*>(other);
        if (!rhs) {
            return true;
        }
        if (((rhs->field08 ^ field08) & ~3ull) != 0) {
            return true;
        }
        return false;
    }

    std::uint64_t field08;  // 08
};
static_assert(offsetof(TaggedBase44e700, field08) == 0x08, "field08 offset");

class FloatEntry44e700 : public TaggedBase44e700
{
public:
    bool DiffersFrom(PolymorphicBase* other) const;  // compared: 0x44e700

    float field10;  // 10
};
static_assert(offsetof(FloatEntry44e700, field10) == 0x10, "field10 offset");
