// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// TESPackage, ActorProcess, Actor, Actor::currentProcess, Actor::IsFollowing: CRASHLOGGER_PDB(59818@2026.10.24)
// BSPointerHandle, BSHandleRefObject, HandleEntry, g_handleTable, TESPackage::type, TESPackage::IsInactive, ActorProcess::GetCurrentPackage, ActorProcess::GetFollowTarget, Actor::unk00: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct BSPointerHandle
{
    std::uint32_t nativeHandle;
};

struct BSHandleRefObject
{
    std::uint8_t  unk00[0x8];
    std::uint32_t handleRefCount;  // 0x08
};

struct HandleEntry
{
    std::uint32_t      flags;  // 0x00
    std::uint32_t      unk04;  // 0x04
    BSHandleRefObject* ptr;    // 0x08
};
static_assert(sizeof(HandleEntry) == 0x10, "HandleEntry size");

extern HandleEntry g_handleTable[];

class TESPackage
{
public:
    bool IsInactive() const;

    std::uint8_t unk00[0x24];
    std::uint8_t type;  // 0x24
};
static_assert(offsetof(TESPackage, type) == 0x24, "TESPackage::type offset");

class ActorProcess
{
public:
    TESPackage*      GetCurrentPackage() const;
    BSPointerHandle& GetFollowTarget(BSPointerHandle& a_out) const;
};

class Actor
{
public:
    bool IsFollowing() const;

    std::uint8_t  unk00[0xf8];
    ActorProcess* currentProcess;  // 0xf8
};
static_assert(offsetof(Actor, currentProcess) == 0xf8, "Actor::currentProcess offset");
