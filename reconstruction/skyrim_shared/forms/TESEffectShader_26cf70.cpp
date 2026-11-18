// Inferred names: GUESS(low)
// Origin: declarations adapted from CommonLibSSE-NG b93280e, MIT; bodies original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x26cf70 TESEffectShader::Function26cf70
// 0x26cfa0 TESEffectShader::Function26cfa0
#include "TESEffectShader_26cf70.h"
extern "C" float sinf(float);
float TESEffectShader::Function26cf70(float time) { return sinf(time * radiansPerCycle * data.edgeEffectAlphaPulseFrequency) * data.edgeEffectAlphaPulseAmplitude; }
float TESEffectShader::Function26cfa0(float time) { return sinf(time * radiansPerCycle * data.fillTextureEffectAlphaPulseFrequency) * data.fillTextureEffectAlphaPulseAmplitude; }
