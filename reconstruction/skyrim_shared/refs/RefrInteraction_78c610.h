// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// RefrInteraction, RefrInteraction::actor, RefrInteraction::targetRefr: CRASHLOGGER_PDB(59818@2026.10.24)
// Unk_01, Unk_02, GetType: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class RefrInteraction
{
public:
    virtual ~RefrInteraction();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual std::uint32_t GetType() const;

    bool operator==(const RefrInteraction* const& a_rhs) const;

    std::uint8_t unk08[0x08];
    std::uint32_t actor;
    std::uint32_t targetRefr;
};

static_assert(offsetof(RefrInteraction, actor) == 0x10, "actor offset");
static_assert(offsetof(RefrInteraction, targetRefr) == 0x14, "targetRefr offset");
