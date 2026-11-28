// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Factory1e3540, Form1e3540, Unit1e3540, g_tableInitialized1e3540, g_factoryTable1e3540, g_defaultName1e3540, GetFormTypeName1e3540, Slot0, Slot1, GetName, unk00, formType, kTableCount: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

constexpr std::size_t kTableCount = 138;

class Factory1e3540
{
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual const char* GetName() const;
};

struct Form1e3540
{
    std::uint8_t unk00[0x1A];  // 00
    std::uint8_t formType;     // 1A
};
static_assert(offsetof(Form1e3540, formType) == 0x1A, "Form1e3540::formType offset");

extern bool g_tableInitialized1e3540;
extern Factory1e3540* g_factoryTable1e3540[kTableCount];
extern const char g_defaultName1e3540[];

struct Unit1e3540
{
    static const char* GetFormTypeName1e3540(const Form1e3540* a_form);  // compared: 0x1e3540
};
