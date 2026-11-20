// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the observed procedure cleanup.
// BGSProcedureDialogue: EXE_RTTI
// unknownProcedureData: GUESS(low)
#pragma once

#include "BGSProcedureBase_45cc90.h"
#include <cstdint>

class BGSProcedureDialogue : public BGSProcedureBase
{
public:
    BGSProcedureDialogue();
    ~BGSProcedureDialogue() override;

private:
    std::uint8_t unknownProcedureData[0x30];
};
static_assert(sizeof(BGSProcedureDialogue) == 0x38, "observed allocation size");
