// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// Adapted bodies: none
// BGSProcedureGuardExecState, BGSProcedureGuardExecState::BGSProcedureGuardExecState: CRASHLOGGER_PDB(59818@2026.10.24)
// BGSProcedureExecStateBase, unk08, unk10, unk18, unk20, unk28, unk30: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

class BGSProcedureExecStateBase
{
public:
    virtual ~BGSProcedureExecStateBase();
};

class BGSProcedureGuardExecState : public BGSProcedureExecStateBase
{
public:
    BGSProcedureGuardExecState();

    std::uint64_t unk08;
    std::uint64_t unk10;
    std::uint64_t unk18;
    std::uint64_t unk20;
    std::uint64_t unk28;
    std::uint64_t unk30;
};
static_assert(offsetof(BGSProcedureGuardExecState, unk08) == 0x08, "unk08 offset");
static_assert(offsetof(BGSProcedureGuardExecState, unk30) == 0x30, "unk30 offset");
