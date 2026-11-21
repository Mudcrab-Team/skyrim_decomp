// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the observed procedure cleanup.
// BGSProcedureFlightGrab: EXE_RTTI
// unknownProcedureData: GUESS(low)
#pragma once

#include "BGSProcedureBase_45cc90.h"
#include <cstdint>

class BGSProcedureFlightGrab : public BGSProcedureBase
{
public:
    BGSProcedureFlightGrab();
    ~BGSProcedureFlightGrab() override;

private:
    std::uint8_t unknownProcedureData[0x30];
};
static_assert(sizeof(BGSProcedureFlightGrab) == 0x38, "observed allocation size");
