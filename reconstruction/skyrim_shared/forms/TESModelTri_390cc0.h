// Origin: original reconstruction; declarations adapted from CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/T/TESModel.h and TESModelTri.h.
// Source exposure: mixed (binary-analysis and community headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESModelTri, TESModel, BaseFormComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESModelTri::TESModelTri, TESModel::TESModel: GUESS(low)
// TESModel, BaseFormComponent: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// model, textures, addons, numTextures, numAddons: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once
class BaseFormComponent {
public:
    virtual ~BaseFormComponent();
    virtual void InitializeDataComponent() = 0;
    virtual void ClearDataComponent() = 0;
    virtual void CopyComponent(BaseFormComponent*);
};
class TESModel : public BaseFormComponent {
public:
    TESModel();
    virtual ~TESModel();
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(BaseFormComponent*) override;
    virtual const char* GetModel() const;
    virtual void SetModel(const char*);
    virtual void* GetAsModelTextureSwap();
private:
    void* model;
    void* textures;
    unsigned int* addons;
    unsigned short numTextures;
    unsigned short numAddons;
};
class TESModelTri : public TESModel {
public:
    TESModelTri();
    virtual ~TESModelTri();
    void SetModel(const char*) override;
};
static_assert(sizeof(TESModel) == 0x28, "TESModel public member layout");
static_assert(sizeof(TESModelTri) == 0x28, "TESModelTri public size");
