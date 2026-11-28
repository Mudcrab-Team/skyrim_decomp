// Source exposure: binary-analysis (pinned image listing; CrashLogger PDB name hint).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Factory1e8160, InnerVisitor1e8160, ObjectFactoryVisitor1e8160, Slot0, Slot1, Slot2, Slot3, Slot4, GetTypeId, Visit, innerVisitor: GUESS(low)
// VisitFactory: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include <cstddef>
#include <cstdint>

class Factory1e8160
{
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual std::int32_t GetTypeId() const;
};

class InnerVisitor1e8160
{
public:
    virtual void Slot0();
    virtual std::uint32_t Visit(Factory1e8160* a_factory);
};

class ObjectFactoryVisitor1e8160
{
public:
    virtual ~ObjectFactoryVisitor1e8160();
    virtual std::uint32_t VisitFactory(Factory1e8160* a_factory);  // compared: 0x1e8160

    InnerVisitor1e8160* innerVisitor;  // 08
};
static_assert(offsetof(ObjectFactoryVisitor1e8160, innerVisitor) == 0x08, "ObjectFactoryVisitor1e8160::innerVisitor offset");
