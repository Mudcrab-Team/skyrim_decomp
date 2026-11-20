// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the observed procedure cleanup.
// BGSProcedureFind: EXE_RTTI
// unknownProcedureData: GUESS(low)
#pragma once

#include "BGSProcedureBase_45cc90.h"
#include <cstdint>

class BGSProcedureFind : public BGSProcedureBase
{
public:
    BGSProcedureFind();
    ~BGSProcedureFind() override;

private:
    std::uint8_t unknownProcedureData[0x30];
};
static_assert(sizeof(BGSProcedureFind) == 0x38, "observed allocation size");
