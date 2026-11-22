// Source exposure: mixed (community names and the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSIdleMarker, BGSIdleMarker::GetIgnoredBySandbox: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// Base0, Base1, Base2: GUESS(low) STANDIN; sizes and offsets from the community layout
#pragma once

#include <cstdint>

struct Base0 {
    virtual ~Base0();
    std::uint8_t pad[0x28];
};
static_assert(sizeof(Base0) == 0x30, "Base0 size");

struct Base1 {
    virtual ~Base1();
    std::uint8_t pad[0x20];
};
static_assert(sizeof(Base1) == 0x28, "Base1 size");

struct Base2 {
    virtual ~Base2();
    std::uint8_t unknown60;  // 08
    std::uint8_t pad[0x17];
};
static_assert(sizeof(Base2) == 0x20, "Base2 size");

class BGSIdleMarker : public Base0, public Base1, public Base2
{
public:
    ~BGSIdleMarker();  // compared: 0x391b00
    bool GetIgnoredBySandbox() const;  // compared: 0x391b80
};
static_assert(sizeof(BGSIdleMarker) == 0x78, "BGSIdleMarker size");
