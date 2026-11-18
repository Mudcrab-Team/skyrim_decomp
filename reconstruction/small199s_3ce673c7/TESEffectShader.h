// Inferred names: GUESS(low)
// Origin: declarations adapted from CommonLibSSE-NG b93280e, MIT; bodies original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESEffectShader, TESForm, BaseFormComponent, EffectShaderData, Color: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// sourceFiles, formFlags, formID, inGameFormFlags, formType, pad1B, pad1C, data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk00, membraneShaderSourceBlendMode, membraneShaderBlendOperation, membraneShaderZTestFunction, fillTextureEffectColorKey1, fillTextureEffectAlphaFadeInTime, fillTextureEffectFullAlphaTime, fillTextureEffectAlphaFadeOutTime, fillTextureEffectPersistentAlphaRatio, fillTextureEffectAlphaPulseAmplitude, fillTextureEffectAlphaPulseFrequency, fillTextureEffectTextureAnimationSpeedU, fillTextureEffectTextureAnimationSpeedV, edgeEffectFallOff, edgeEffectColor, edgeEffectAlphaFadeInTime, edgeEffectFullAlphaTime, edgeEffectAlphaFadeOutTime, edgeEffectPersistentAlphaRatio, edgeEffectAlphaPulseAmplitude, edgeEffectAlphaPulseFrequency: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function26cf70, Function26cfa0, radiansPerCycle: GUESS(low)
#pragma once
#include <cstdint>
class BaseFormComponent { public: virtual ~BaseFormComponent(); };
class TESForm : public BaseFormComponent { public: void* sourceFiles; std::uint32_t formFlags; std::uint32_t formID; std::uint16_t inGameFormFlags; std::uint8_t formType; std::uint8_t pad1B; std::uint32_t pad1C; };
struct Color { std::uint8_t red, green, blue, alpha; };
struct EffectShaderData {
 std::uint32_t unk00; std::uint32_t membraneShaderSourceBlendMode, membraneShaderBlendOperation, membraneShaderZTestFunction;
 Color fillTextureEffectColorKey1;
 float fillTextureEffectAlphaFadeInTime, fillTextureEffectFullAlphaTime, fillTextureEffectAlphaFadeOutTime, fillTextureEffectPersistentAlphaRatio, fillTextureEffectAlphaPulseAmplitude, fillTextureEffectAlphaPulseFrequency, fillTextureEffectTextureAnimationSpeedU, fillTextureEffectTextureAnimationSpeedV;
 float edgeEffectFallOff; Color edgeEffectColor;
 float edgeEffectAlphaFadeInTime, edgeEffectFullAlphaTime, edgeEffectAlphaFadeOutTime, edgeEffectPersistentAlphaRatio, edgeEffectAlphaPulseAmplitude, edgeEffectAlphaPulseFrequency;
};
constexpr float radiansPerCycle = 6.2831854820251465f;
class TESEffectShader : public TESForm { public: float Function26cf70(float); float Function26cfa0(float); EffectShaderData data; };
