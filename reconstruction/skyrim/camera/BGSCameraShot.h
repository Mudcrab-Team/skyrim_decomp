// Code origin: written from the instruction listing of the pinned image; class layout and names from community declarations.
// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Bodies adapted from community sources: none; tools/check_origin.py reports none above its threshold at the pinned checkouts.
// BGSCameraShot, BGSCameraShot::InitializeData, BGSCameraShot::~BGSCameraShot, BGSCameraShot::data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSCameraShot::Function319330: GUESS(low); the listing at RVA 0x319330 tests a zoom camera action, a model name and a pointer at 0xA0, with no community name for it
// CAMERA_SHOT_DATA: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NG's enum types are plain integers here
// TESModel: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NG slots 04 to 06 (GetModel, SetModel, GetAsModelTextureSwap) as placeholders; size 0x28
// TESModel::model, ::textures, ::addons, ::numTextures, ::numAddons: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESModel::unknown24: GUESS(low); the 4 bytes at 0x24 that the listing of this unit never reads (NG's pad24)
// TESImageSpaceModifiableForm, TESImageSpaceModifiableForm::imageSpaceModifying: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); BaseFormComponent base and one pointer, size 0x10
// BSFixedString, BSFixedString::_data: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); reduced to the data pointer this unit reads
// BSFixedString::HasValue: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission); the callee at address 0xeb1380 returns an int that the listing tests for non-zero
// BGSCameraShot::unknown84, ::unknown98, ::unknown9C, ::unknownB2, ::unknownB4: GUESS(low); members whose meaning no permitted source names, kept at their listed offsets
// BGSCameraShot::unknown88, ::unknown90, ::unknownA0, ::unknownA8, ::unknownB0, ::unknownB1, ::unknownB8: GUESS(low); NG names the same eight offsets only as unk88 to unkB8, so the names here are invented
// BGSCameraShot::BGSCameraShot: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence); name only, defined only so the unit emits the vftables and the deleting destructor
#pragma once

#include <cstdint>

#include "skyrim_shared/forms/TESForm.h"

class TESImageSpaceModifier;

class BSFixedString
{
public:
    std::int32_t HasValue() const;  // address 0xeb1380
    const char*  _data;             // 00
};
static_assert(sizeof(BSFixedString) == 0x8, "BSFixedString size");

class TESModel : public BaseFormComponent {
public:
    ~TESModel() override;                                    // 00
    void InitializeDataComponent() override;                 // 01
    void ClearDataComponent() override;                      // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;   // 03
    virtual const char* GetModel() const;                    // 04
    virtual void        SetModel(const char* a_model);       // 05
    virtual void*       GetAsModelTextureSwap();             // 06

    BSFixedString model;         // 08 - MODL
    void*         textures;      // 10 - MODT
    void*         addons;        // 18
    std::uint16_t numTextures;   // 20
    std::uint16_t numAddons;     // 22
    std::uint32_t unknown24;     // 24
};
static_assert(sizeof(TESModel) == 0x28, "layout");

class TESImageSpaceModifiableForm : public BaseFormComponent {
public:
    ~TESImageSpaceModifiableForm() override;                  // 00
    void InitializeDataComponent() override;                  // 01
    void ClearDataComponent() override;                       // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;    // 03

    TESImageSpaceModifier* imageSpaceModifying;  // 08
};
static_assert(sizeof(TESImageSpaceModifiableForm) == 0x10, "layout");

struct CAMERA_SHOT_DATA {
    std::uint32_t cameraAction;                // 00
    std::uint32_t location;                    // 04
    std::uint32_t target;                      // 08
    std::uint32_t flags;                       // 0C
    float         playerTimeMult;              // 10
    float         targetTimeMult;              // 14
    float         globalTimeMult;              // 18
    float         maxTime;                     // 1C
    float         minTime;                     // 20
    float         targetPercentBetweenActors;  // 24
    float         nearTargetDistance;          // 28
};
static_assert(sizeof(CAMERA_SHOT_DATA) == 0x2C, "layout");

class BGSCameraShot;

// ResetImageSpaceModifier: GUESS(low); the function at 0x1e8670 that InitItemImpl calls with the image-space base and the shot
void ResetImageSpaceModifier(TESImageSpaceModifiableForm* a_mod, BGSCameraShot* a_owner);

class BGSCameraShot :
    public TESForm,                      // 00
    public TESModel,                     // 20
    public TESImageSpaceModifiableForm   // 48
{
public:
    BGSCameraShot();
    ~BGSCameraShot() override;  // 00

    void InitializeData() override;  // 04
    // InitItemImpl: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); vtable slot 13, compared 0x318c50
    void InitItemImpl() override;  // 13
    // SetInitialized: GUESS(low); the TESForm member at 0x1e60b0 that marks the form initialised, not declared in TESForm.h
    void SetInitialized(bool a_set);
    bool Function319330();

    CAMERA_SHOT_DATA data;       // 58
    std::uint32_t    unknown84;  // 84
    void*            unknown88;  // 88
    void*            unknown90;  // 90
    std::uint32_t    unknown98;  // 98
    std::uint32_t    unknown9C;  // 9C
    void*            unknownA0;  // A0
    void*            unknownA8;  // A8
    std::uint8_t     unknownB0;  // B0
    bool             unknownB1;  // B1
    std::uint16_t    unknownB2;  // B2
    std::uint32_t    unknownB4;  // B4
    void*            unknownB8;  // B8
};
static_assert(sizeof(BGSCameraShot) == 0xC0, "layout");
