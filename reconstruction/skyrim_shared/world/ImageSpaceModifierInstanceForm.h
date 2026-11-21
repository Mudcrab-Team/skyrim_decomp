// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ImageSpaceModifierInstance, ImageSpaceModifierInstance::unk10, ::strength, ::target, ::age, ::flags: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// ImageSpaceModifierInstanceForm, ImageSpaceModifierInstanceForm::Unk_25, ImageSpaceModifierInstanceForm::~ImageSpaceModifierInstanceForm, ImageSpaceModifierInstanceForm::Apply, ImageSpaceModifierInstanceForm::IsForm, ImageSpaceModifierInstanceForm::PrintInfo: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ImageSpaceModifierInstanceForm::imod, TESImageSpaceModifier: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown30, TESImageSpaceModifier::Function2a7630, a_arg1: GUESS(low); the callee at 0x2a7630 takes the instance age and returns a bool
#pragma once

#include <cstdint>
#include <cstddef>

class ImageSpaceModifierInstanceForm;

class ImageSpaceModifierInstance
{
public:
    virtual ~ImageSpaceModifierInstance();
    virtual void Apply();
    virtual ImageSpaceModifierInstanceForm* IsForm();
    virtual void PrintInfo(char* a_dstBuf);

    std::uint8_t unknown08[0x8];  // 08
    std::uint32_t unk10;  // 10
    float strength;  // 14
    void* target;  // 18
    float age;  // 20
    std::uint32_t flags;  // 24
};
static_assert(sizeof(ImageSpaceModifierInstance) == 0x28, "ImageSpaceModifierInstance size");

class TESImageSpaceModifier { public: bool Function2a7630(float a_arg1); };

class ImageSpaceModifierInstanceForm : public ImageSpaceModifierInstance
{
public:
    ~ImageSpaceModifierInstanceForm() override;  // 00
    virtual bool Unk_25();  // compared: 0x2a3650  // slot 25
    void Apply() override;  // 26
    ImageSpaceModifierInstanceForm* IsForm() override;  // 27
    void PrintInfo(char* a_dstBuf) override;  // 28

    TESImageSpaceModifier* imod;  // 28
    std::uint8_t unknown30[0x20];  // 30
};
static_assert(sizeof(ImageSpaceModifierInstanceForm) == 0x50, "ImageSpaceModifierInstanceForm size");
