// Source exposure: binary-analysis (pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// ExtraAttachedArrows3D, ArrowHolder, ArrowTarget, holder, Get28, flags0F4, flags109, value130: GUESS(low)
// ExtraAttachedArrows3D::Function18a980: CRASHLOGGER_PDB(59818@2026.10.24); size only
#pragma once

#include <cstdint>
#include <cstddef>

struct ArrowTarget
{
    std::uint8_t pad00[0xF4];
    std::uint32_t flags0F4;  // 0xF4
    std::uint8_t padF8[0x109 - 0xF8];
    std::uint8_t flags109;  // 0x109
    std::uint8_t pad10A[0x130 - 0x10A];
    float value130;  // 0x130
};

struct ArrowHolder
{
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual ArrowTarget* Get28();  // slot 5
};

class ExtraAttachedArrows3D
{
public:
    void Function18a980();  // compared: 0x18a980

    ArrowHolder* holder;  // 0x00
};
