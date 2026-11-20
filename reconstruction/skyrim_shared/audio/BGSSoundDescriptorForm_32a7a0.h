// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: the partial form, interface, and legacy sound layouts follow the cited public declarations.
// BGSSoundDescriptorForm, BGSSoundDescriptor, BSISoundDescriptor, TESSound, TESSound::descriptor, soundDescriptor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetDescriptorType, GetType, InitSound, LoadSound, Unk_06: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SoundDescription, PopulateSound, Function declarations, FunctionSlot02, padding: STANDIN GUESS(low)
#pragma once

#include <cstdint>
#include "skyrim_shared/forms/TESForm.h"

struct SoundDescription
{
    std::uint8_t padding00[0xC];
    std::uint32_t formID;
};

class BSISoundDescriptor
{
public:
    virtual ~BSISoundDescriptor();
    virtual bool PopulateSound(SoundDescription& output) = 0;
    virtual void FunctionSlot02() = 0;
};

class BGSSoundDescriptor : public BSISoundDescriptor
{
public:
    virtual void InitSound(TESForm* source);
    virtual bool LoadSound(TESFile* file);
    virtual std::uint32_t GetType() const = 0;
    virtual float Unk_06() const = 0;
};

class BGSSoundDescriptorForm : public TESForm, public BSISoundDescriptor
{
public:
    float Function32a7a0() const;
    virtual std::uint32_t GetDescriptorType();
    static BGSSoundDescriptorForm* Function559a10(std::uint32_t id);
    static BGSSoundDescriptorForm* Function559a70(const char* editorID);

private:
    BGSSoundDescriptor* soundDescriptor;
};
static_assert(sizeof(BGSSoundDescriptorForm) == 0x30, "sound descriptor form size");

class TESSound : public TESForm
{
public:
    std::uint8_t padding20[0x10];
    BGSSoundDescriptorForm* descriptor;
};
static_assert(sizeof(TESSound) == 0x38, "legacy sound prefix size");
