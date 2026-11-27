// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: original implementations based on the pinned game build, with the cited declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Base form: local stand-ins; GASObjectInterface from this directory's GASObject.h.
// GFxASCharacter, GFxCharacter, GFxASCharacter::~GFxASCharacter, GFxCharacter::~GFxCharacter, GFxCharacter::unk96, GFxASCharacter::unk0B0: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GRefCountBaseWeakSupport, GFxLogBase: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GFxASCharacter::Functiond35d50, GRefCountBaseWeakSupport::refCount, GRefCountBaseWeakSupport::weakProxy, GFxLogBase::~GFxLogBase, GFxCharacter::unk20: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include "GASObject.h"

class GRefCountBaseWeakSupport
{
public:
    virtual ~GRefCountBaseWeakSupport();  // 00

    std::int32_t refCount;  // 08
    void* weakProxy;  // 10
};
static_assert(sizeof(GRefCountBaseWeakSupport) == 0x18, "GRefCountBaseWeakSupport size");

class GFxLogBase
{
public:
    virtual ~GFxLogBase();  // 00
};

class GFxCharacter : public GRefCountBaseWeakSupport, public GFxLogBase
{
public:
    ~GFxCharacter() override;  // 00

    std::uint8_t unk20[0x76];  // 20 - not used by this unit
    std::uint16_t unk96;  // 96
};
static_assert(offsetof(GFxCharacter, unk96) == 0x96, "GFxCharacter::unk96 offset");
static_assert(sizeof(GFxCharacter) == 0x98, "GFxCharacter size");

class GFxASCharacter : public GFxCharacter, public GASObjectInterface
{
public:
    ~GFxASCharacter() override;  // 00

    void Functiond35d50();

    std::uint64_t unk0B0[12];  // 0B0 - not used by this unit
};
static_assert(sizeof(GFxASCharacter) == 0x110, "GFxASCharacter size");
