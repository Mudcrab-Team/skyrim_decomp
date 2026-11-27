// Source exposure: binary-analysis (pinned-image observations and image RTTI).
// Code origin: original polymorphic reconstruction with provisional method signatures.
// SPDX-License-Identifier: CC0-1.0
// BSTask: STANDIN EXE_RTTI
// BSTask::~BSTask, BSTask::Unk_01, BSTask::Unk_02, BSTask::Unk_03, BSTask::Unk_04, BSTask::~BSTask: GUESS(low)
#pragma once
#include <cstdint>
#include <cstddef>
#include <intrin.h>
#include <Windows.h>

// gTaskCount: GUESS(low)
extern volatile long gTaskCount;
class BSTask
{
public:
    virtual ~BSTask();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    std::uint8_t unknown8[16];
};
static_assert(sizeof(BSTask) == 24, "observed class size");
