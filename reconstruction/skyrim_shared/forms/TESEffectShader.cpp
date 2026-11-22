// Source exposure: mixed. Drafted from local instruction listings of the pinned image.
// Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT) unless labelled in the header.
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x26b3e0 TESEffectShader::InitializeData
// 0x26b760 TESEffectShader::InitItemImpl
// 0x26cfd0 TESEffectShader::GetTotalDuration
// 0x26d000 TESEffectShader::GetFadeInAndFullDuration
#include "TESEffectShader.h"

void TESEffectShader::InitializeData()
{
    data.Initialize();
}

// TestBit: GUESS(low); tests one bit of a word by value.
static bool TestBit(std::uint32_t a_word, std::uint32_t a_bit)
{
    return ((a_word >> a_bit) & 1) != 0;
}

// BGSDebris: GUESS(low); stand-in for the record type the dynamic cast in InitItemImpl targets.
class BGSDebris {};

// TESEffectShader::InitItemImpl, RVA 0x26b760, 180 bytes. Resolves the two stored form IDs (at 0x118 and
// 0x160) into object pointers, after adding the compile index to each.
void TESEffectShader::InitItemImpl()
{
    auto* base = reinterpret_cast<std::uint8_t*>(this);
    if (!TestBit(formFlags, 3)) {
        std::uint32_t formID = *reinterpret_cast<std::uint32_t*>(base + 0x118);
        if (formID != 0) {
            RecordFlags_AddCompileIndex(&formID, GetCompileIndexForOwner(this, 0xffffffff));
            *reinterpret_cast<BGSDebris**>(base + 0x118) = dynamic_cast<BGSDebris*>(GetFormForID(formID));
        }
        formID = *reinterpret_cast<std::uint32_t*>(base + 0x160);
        if (formID != 0) {
            RecordFlags_AddCompileIndex(&formID, GetCompileIndexForOwner(this, 0xffffffff));
            *reinterpret_cast<void**>(base + 0x160) = LoadFormForID(formID);
        }
        FinishInitItem(this, true);
    }
}

float TESEffectShader::GetTotalDuration() const
{
    const float edge = data.edgeEffectAlphaFadeInTime + data.edgeEffectFullAlphaTime + data.edgeEffectAlphaFadeOutTime;
    const float fill = data.fillTextureEffectAlphaFadeInTime + data.fillTextureEffectFullAlphaTime + data.fillTextureEffectAlphaFadeOutTime;
    return edge > fill ? edge : fill;
}

float TESEffectShader::GetFadeInAndFullDuration() const
{
    const float edge = data.edgeEffectAlphaFadeInTime + data.edgeEffectFullAlphaTime;
    const float fill = data.fillTextureEffectAlphaFadeInTime + data.fillTextureEffectFullAlphaTime;
    return edge > fill ? edge : fill;
}
