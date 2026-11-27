// Source exposure: mixed (names and layout from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB layout.
// AIProcess, AIProcess::currentPackage, AIProcess::IsWandering, ActorPackage, ActorPackage::package, ActorPackage::currentProcedureIndex, TESPackage: CRASHLOGGER_PDB(59818@2026.10.24)
// TESPackage::procedureType, gPackageProcedureTables, AIProcess::GetRunOncePackage, AIProcess::GetRunOnceProcedureIndex: GUESS
#pragma once

#include <cstdint>

struct TESPackage
{
    std::uint8_t unk00[0xD8];
    std::int32_t procedureType;
};

struct ActorPackage
{
    std::uint64_t unk00;
    TESPackage* package;
    std::uint64_t unk10;
    std::uint32_t unk18;
    std::int32_t currentProcedureIndex;
    std::uint64_t unk20;
    std::uint64_t unk28;
};

static_assert(sizeof(ActorPackage) == 0x30, "ActorPackage size");

extern const std::int32_t* gPackageProcedureTables[];

class AIProcess
{
  public:
    bool IsWandering();

    TESPackage* GetRunOncePackage();
    std::int32_t GetRunOnceProcedureIndex();

    void* unk000;
    void* unk008;
    void* unk010;
    ActorPackage currentPackage;
};
