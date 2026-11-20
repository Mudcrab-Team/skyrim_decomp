// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the observed procedure cleanup.
// BGSProcedureFollowTo: EXE_RTTI
// unknownProcedureData: GUESS(low)
#pragma once

#include "BGSProcedureBase_45cc90.h"
#include <cstdint>

class BGSProcedureFollowTo : public BGSProcedureBase
{
public:
    BGSProcedureFollowTo();
    ~BGSProcedureFollowTo() override;

private:
    std::uint8_t unknownProcedureData[0x38];
};
static_assert(sizeof(BGSProcedureFollowTo) == 0x40, "observed allocation size");
