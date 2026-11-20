// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the observed procedure cleanup.
// BGSProcedureUseIdleMarker: EXE_RTTI
// unknownProcedureData: GUESS(low)
#pragma once

#include "BGSProcedureBase_45cc90.h"
#include <cstdint>

class BGSProcedureUseIdleMarker : public BGSProcedureBase
{
public:
    BGSProcedureUseIdleMarker();
    ~BGSProcedureUseIdleMarker() override;

private:
    std::uint8_t unknownProcedureData[0x30];
};
static_assert(sizeof(BGSProcedureUseIdleMarker) == 0x38, "observed allocation size");
