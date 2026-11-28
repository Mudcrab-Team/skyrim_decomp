// Source exposure: binary-analysis (pinned image listing; CrashLogger PDB name hint).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Factory1e81b0, ObjectTypeFinder1e81b0, Slot0, Slot1, Slot2, Slot3, Slot4, GetTypeId, targetType, foundFactory: GUESS(low)
// VisitFactory: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include <cstddef>
#include <cstdint>

class Factory1e81b0
{
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual std::int32_t GetTypeId() const;
};

class ObjectTypeFinder1e81b0
{
public:
    virtual ~ObjectTypeFinder1e81b0();
    virtual std::uint32_t VisitFactory(Factory1e81b0* a_factory);  // compared: 0x1e81b0

    std::int32_t targetType;       // 08
    Factory1e81b0* foundFactory;   // 10
};
static_assert(offsetof(ObjectTypeFinder1e81b0, targetType) == 0x08, "ObjectTypeFinder1e81b0::targetType offset");
static_assert(offsetof(ObjectTypeFinder1e81b0, foundFactory) == 0x10, "ObjectTypeFinder1e81b0::foundFactory offset");
