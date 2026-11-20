// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial layouts follow the cited class declarations and the pinned secondary interface.
// BGSSoundCategory, TESFullName, BSISoundCategory, parentCategory, flags, unk3C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// attenuation, staticMult, defaultMenuValue, volumeMult, frequencyMult: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Matches, GetCategoryVolume, SetCategoryVolume, GetCategoryFrequency, SetCategoryFrequency, GetCategoryAttenuation, SetCategoryAttenuation: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function declarations, categoryStateFlags, FunctionSlot declarations, fullNameStorage: STANDIN GUESS(low)
#pragma once

#include <cstdint>
#include "skyrim_shared/forms/TESForm.h"

class TESFullName
{
public:
    virtual ~TESFullName();

private:
    void* fullNameStorage;
};

class BSISoundCategory
{
public:
    virtual ~BSISoundCategory();
    virtual bool Matches(const BSISoundCategory* category) const = 0;
    virtual float GetCategoryVolume() const = 0;
    virtual void SetCategoryVolume(float value) = 0;
    virtual float GetCategoryFrequency() const = 0;
    virtual void SetCategoryFrequency(float value) = 0;
    virtual std::uint16_t GetCategoryAttenuation() const = 0;
    virtual void SetCategoryAttenuation(std::uint16_t value) = 0;
    virtual void FunctionSlot08() = 0;
    virtual void Function329a70(bool enabled) = 0;
    virtual bool Function329a30() const = 0;
    virtual void Function329aa0(bool enabled) = 0;
};

class BGSSoundCategory : public TESForm, public TESFullName, public BSISoundCategory
{
public:
    void SetCategoryFrequency(float value) override;
    void SetCategoryAttenuation(std::uint16_t value) override;
    bool Matches(const BSISoundCategory* category) const override;
    float GetCategoryVolume() const override;
    float GetCategoryFrequency() const override;
    bool Function329a30() const override;
    void Function329a70(bool enabled) override;
    void Function329aa0(bool enabled) override;

private:
    std::uint32_t flags;
    std::uint32_t unk3C;
    BGSSoundCategory* parentCategory;
    std::uint16_t categoryStateFlags;
    std::uint16_t attenuation;
    std::uint16_t staticMult;
    std::uint16_t defaultMenuValue;
    float volumeMult;
    float frequencyMult;
};
static_assert(sizeof(BGSSoundCategory) == 0x58, "sound category size");
