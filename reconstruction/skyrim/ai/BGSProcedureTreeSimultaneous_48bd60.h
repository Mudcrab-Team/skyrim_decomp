// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the pinned procedure code.
// BGSProcedureTreeSimultaneous: EXE_RTTI
// ReplaceOptions, options, unknown00: GUESS(low)
#pragma once

#include "BGSProcedureBase_45bfe0.h"

class BGSProcedureTreeSimultaneous
{
public:
    void ReplaceOptions(ProcedureOptions* replacement);

private:
    std::uint8_t unknown00[0x30];
    ProcedureOptions* options;
};
