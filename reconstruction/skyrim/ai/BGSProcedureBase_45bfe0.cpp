// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the pinned procedure code.
// Adapted bodies: none
// 0x45bfe0 BGSProcedureBase::HasStateName
// 0x45c020 BGSProcedureBase::CreateExecutionState
// 0x45c240 BGSProcedureBase::ReplaceOptions
// 0x45d110 BGSProcedureBase::CopyDefaultStateValue
// 0x45d5c0 BGSProcedureBase::SetFlag
#include "BGSProcedureBase_45bfe0.h"

extern std::uint32_t gDefaultStateValue;

bool BGSProcedureBase::HasStateName(const ProcedureExecutionState& state) const
{
    const auto& other = state.GetStateName();
    return GetStateName().text == other.text;
}

ProcedureExecutionState* BGSProcedureBase::CreateExecutionState()
{
    const auto& name = GetStateName();
    auto* factory = GetProcedureStateRegistry().FindFactory(name);
    return factory ? factory->CreateState() : nullptr;
}

void BGSProcedureBase::ReplaceOptions(ProcedureOptions* replacement)
{
    if (options) {
        delete options;
    }
    options = replacement;
}

std::uint32_t& BGSProcedureBase::CopyDefaultStateValue(std::uint32_t& value) const
{
    value = gDefaultStateValue;
    return value;
}

void BGSProcedureBase::SetFlag(bool enabled)
{
    flags = enabled ? flags | 1u : flags & ~1u;
}
