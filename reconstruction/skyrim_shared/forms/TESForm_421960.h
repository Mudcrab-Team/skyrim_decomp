// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESForm: EXE_RTTI
// TESForm::GetTemperedFormSkillAdvanceAmount: CRASHLOGGER_PDB(59818@2026.10.24)
// TESForm::GetGoldValue: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// g_temperSkillExp, g_temperSkillMult, g_temperSkillOffset, g_temperHealthMult: GUESS(low); game-setting floats observed in listing
#pragma once

#include <cstdint>

extern float g_temperSkillExp;
extern float g_temperSkillMult;
extern float g_temperSkillOffset;
extern float g_temperHealthMult;

class TESForm
{
public:
    std::int32_t GetGoldValue() const;
    float        GetTemperedFormSkillAdvanceAmount(float a_newHealth, float a_oldHealth) const;
};
