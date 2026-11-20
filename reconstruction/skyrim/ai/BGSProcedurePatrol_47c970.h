// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the observed procedure cleanup.
// BGSProcedurePatrol: EXE_RTTI
// unknownProcedureData: GUESS(low)
#pragma once

#include "BGSProcedureBase_45cc90.h"
#include <cstdint>

class BGSProcedurePatrol : public BGSProcedureBase
{
public:
    BGSProcedurePatrol();
    ~BGSProcedurePatrol() override;

private:
    std::uint8_t unknownProcedureData[0x30];
};
static_assert(sizeof(BGSProcedurePatrol) == 0x38, "observed allocation size");
