// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectARMA: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESObject: STANDIN EXE_RTTI
// TESObjectARMA::~TESObjectARMA: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
#pragma once

#include <cstdint>
#include "TESForm.h"

class TESObject : public TESForm
{
public:
};

// TESRaceForm: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class TESRaceForm : public BaseFormComponent
{
public:
    virtual ~TESRaceForm();
    void* race;
};

// BGSBipedObjectForm: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class BGSBipedObjectForm : public BaseFormComponent
{
public:
    virtual ~BGSBipedObjectForm();
    std::uint64_t bipedModelData;
};

class TESObjectARMA : public TESObject, public TESRaceForm, public BGSBipedObjectForm
{
public:
    TESObjectARMA();
    virtual ~TESObjectARMA();  // compared: 0x27d3f8
};
