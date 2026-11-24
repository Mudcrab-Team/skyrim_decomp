// Source exposure: mixed (community declarations and binary analysis).
// Code origin: reconstruction from the pinned image listing, shaped after the sibling function.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESClimate, TESClimate::~TESClimate, TESClimate::nightSky, TESClimate::weatherList, TESClimate::skyObjects, TESModel, BSSimpleList, WeatherType, TESTexture, BaseFormComponent::InitializeDataComponent, BaseFormComponent::ClearDataComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk08, unk78: GUESS(low)
// Adapted bodies: TESClimate::~TESClimate follows momusdigital/fnv_decomp@91e1b6e8 src/tesclimate.cpp
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESClimate.cpp:20 (destructor similarity).
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/tesclimate.cpp:182
#pragma once

#include <cstdint>
#include "declarations/TESForm.h"

class TESModel : public BaseFormComponent
{
public:
    ~TESModel() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    std::uint8_t unk08[0x20];
};

class WeatherType;

template <class T>
struct BSSimpleList
{
    ~BSSimpleList();
    T item;
    BSSimpleList* next;
};

class TESTexture : public BaseFormComponent
{
public:
    ~TESTexture() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    std::uint8_t unk08[8];
};

class TESClimate : public TESForm
{
public:
    TESClimate();
    ~TESClimate() override;

    TESModel nightSky;
    BSSimpleList<WeatherType*> weatherList;
    TESTexture skyObjects[2];
    std::uint8_t unk78[8];
};
static_assert(sizeof(TESClimate) == 0x80, "TESClimate size");
