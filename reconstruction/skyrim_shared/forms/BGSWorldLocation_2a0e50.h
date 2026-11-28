// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BGSWorldLocation, BGSWorldLocation::GetCellOrWorld, TESForm: CRASHLOGGER_PDB(59818@2026.10.24)
// TESObjectCELL, TESWorldSpace, formType, location: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

struct TESForm
{
    std::uint8_t unk00[0x1A];
    std::uint8_t formType;
};

struct TESObjectCELL : public TESForm {};
struct TESWorldSpace : public TESForm {};

class BGSWorldLocation
{
public:
    bool GetCellOrWorld(TESObjectCELL** a_outCell, TESWorldSpace** a_outWorld) const;

    std::uint8_t unk00[0x10];
    TESForm* location;
};

static_assert(offsetof(TESForm, formType) == 0x1A, "formType offset");
static_assert(offsetof(BGSWorldLocation, location) == 0x10, "location offset");
