// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj27d040::Function27d040, treated as adapted: shaped like TESBipedModelForm::GetBipedModel and the same fallback in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesbipedmodelform.cpp:200
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00440000_o2.cpp:1092
// SPDX-License-Identifier: CC0-1.0
// ModelSlot27d040, Obj27d040, Obj27d040::Function27d040: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct ModelSlot27d040
{
    void* vtable;             // 0x00
    const char* modelPath;    // 0x08
    std::uint8_t unk10[0x28]; // 0x10

    static std::uint32_t HasModelPath(const char* const* a_path);
};

class Obj27d040
{
public:
    ModelSlot27d040* Function27d040(std::int32_t a_index);

    std::uint8_t unk00[0x50];   // 0x00
    ModelSlot27d040 models[2];  // 0x50
};

static_assert(sizeof(ModelSlot27d040) == 0x38, "ModelSlot27d040 size");
static_assert(offsetof(Obj27d040, models) == 0x50, "models offset");
