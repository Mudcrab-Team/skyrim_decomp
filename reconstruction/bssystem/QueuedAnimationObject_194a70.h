// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// QueuedAnimationObject, QueuedAnimationObject::sub_140146D60: CRASHLOGGER_PDB(59818@2026.10.24)
// AnimObjectHolder194a70, GetName, FormatTaskDesc, gQueuedAnimFormat, unk90: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class AnimObjectHolder194a70
{
public:
    virtual ~AnimObjectHolder194a70();  // 00
    virtual void Unk01();               // 08
    virtual void Unk02();               // 10
    virtual void Unk03();               // 18
    virtual const char* GetName();      // 20
};

int FormatTaskDesc(char* a_buf, std::size_t a_size, const char* a_fmt, ...);
extern const char gQueuedAnimFormat[];

class QueuedAnimationObject
{
public:
    bool sub_140146D60(char* a_buf, std::uint32_t a_size);  // compared: 0x194a70

    std::uint8_t            unk00[0x90];  // 00
    AnimObjectHolder194a70* unk90;        // 90
};
static_assert(offsetof(QueuedAnimationObject, unk90) == 0x90, "unk90 offset");
