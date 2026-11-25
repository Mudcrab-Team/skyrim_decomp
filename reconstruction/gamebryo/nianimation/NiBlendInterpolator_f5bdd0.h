// Source exposure: mixed (local target observations; community declarations).
// Code origin: original reconstruction.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiBlendInterpolator, NiBlendInterpolator::RegisterStreamables: CRASHLOGGER_PDB(59818@2026.10.24)
// NiInterpolator, NiInterpolator::RegisterStreamables, lastTime: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BlendEntry, interpolator, flags, arraySize, interpArray: GUESS(low); names describe observed blend storage.
#pragma once
#include <cstdint>
#include <cstddef>
#include "declarations/NiObject.h"

class NiInterpolator : public NiObject
{
public:
    bool RegisterStreamables(NiStream& stream) override;
    float lastTime;
};
struct BlendEntry
{
    NiInterpolator* interpolator;
    std::uint8_t unknown08[24];
};
class NiBlendInterpolator : public NiInterpolator
{
public:
    bool RegisterStreamables(NiStream& stream) override;
    std::uint8_t flags;
    std::uint8_t arraySize;
    std::uint8_t unknown1a[6];
    BlendEntry* interpArray;
};
static_assert(sizeof(BlendEntry) == 0x20, "blend entry stride");
static_assert(offsetof(NiBlendInterpolator, flags) == 0x18, "blend flags offset");
static_assert(offsetof(NiBlendInterpolator, interpArray) == 0x20, "blend array offset");
