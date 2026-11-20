// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the observed procedure cleanup.
// BGSProcedureUseWeapon: EXE_RTTI
// unknownProcedureData: GUESS(low)
#pragma once

#include "BGSProcedureBase_45cc90.h"
#include <cstdint>

class BGSProcedureUseWeapon : public BGSProcedureBase
{
public:
    BGSProcedureUseWeapon();
    ~BGSProcedureUseWeapon() override;

private:
    std::uint8_t unknownProcedureData[0x30];
};
static_assert(sizeof(BGSProcedureUseWeapon) == 0x38, "observed allocation size");
