// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the observed procedure cleanup.
// BGSProcedureDialogueActivate: EXE_RTTI
// unknownProcedureData: GUESS(low)
#pragma once

#include "BGSProcedureBase_45cc90.h"
#include <cstdint>

class BGSProcedureDialogueActivate : public BGSProcedureBase
{
public:
    BGSProcedureDialogueActivate();
    ~BGSProcedureDialogueActivate() override;

private:
    std::uint8_t unknownProcedureData[0x30];
};
static_assert(sizeof(BGSProcedureDialogueActivate) == 0x38, "observed allocation size");
