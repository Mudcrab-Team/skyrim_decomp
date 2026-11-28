// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj27d090::Function27d090, treated as adapted: shaped like TESBipedModelForm::GetWorldModel in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesbipedmodelform.cpp:218
// SPDX-License-Identifier: CC0-1.0
// ModelSlot27d090, Obj27d090, Obj27d090::Function27d090: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class ModelSlot27d090
{
public:
    virtual ~ModelSlot27d090();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual const char* GetModelPath() const;

    const char* modelPath;    // 0x08
    std::uint8_t unk10[0x28]; // 0x10

    static std::uint32_t HasModelPath(const char* const* a_path);
};

class Obj27d090
{
public:
    const char* Function27d090(std::int32_t a_index);

    std::uint8_t unk00[0x50];   // 0x00
    ModelSlot27d090 models[2];  // 0x50
};

static_assert(sizeof(ModelSlot27d090) == 0x38, "ModelSlot27d090 size");
static_assert(offsetof(Obj27d090, models) == 0x50, "models offset");
