// Source exposure: mixed (CrashLogger name, sibling shape and the pinned image listing).
// Code origin: adapted from the cited sibling shape; layout checked against the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// BuildInstructionOffsetMapFunctor: CRASHLOGGER_PDB(59818@2026.10.24); the class owning the deleting destructor, read from the PDB's destructor name
// FunctorBase, FunctorMember, member, unknown20: GUESS(low); stand-ins for a base with an out-of-line destructor and a member with one
#pragma once

#include <cstdint>

class FunctorBase
{
public:
    virtual ~FunctorBase();  // 00

    std::uint8_t unknown08[0x10];  // 08
};
static_assert(sizeof(FunctorBase) == 0x18, "FunctorBase size");

struct FunctorMember
{
    ~FunctorMember();

    void* data;  // 00
};

class BuildInstructionOffsetMapFunctor : public FunctorBase
{
public:
    BuildInstructionOffsetMapFunctor();

    FunctorMember member;  // 18
    std::uint8_t unknown20[0x20];  // 20
};
static_assert(sizeof(BuildInstructionOffsetMapFunctor) == 0x40, "BuildInstructionOffsetMapFunctor size");
