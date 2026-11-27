// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: original implementations based on the pinned game build, with the cited declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Base form: local stand-ins; GASObjectInterface from this directory's GASObject.h.
// GFxASCharacter, GFxCharacter, GFxASCharacter::~GFxASCharacter, GFxCharacter::~GFxCharacter: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GRefCountBaseWeakSupport, GFxLogBase, GFxMovieDef: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GFxCharacter::resourceID, GFxCharacter::createdFrame, GFxCharacter::parentClip, GFxCharacter::colorTransform, GFxCharacter::matrix, GFxCharacter::unk96, GFxASCharacter::movieDef: CRASHLOGGER_PDB(59818@2026.10.24)
// GFxASCharacter::Functiond35d50, GRefCountBaseWeakSupport::refCount, GRefCountBaseWeakSupport::weakProxy, GFxLogBase::~GFxLogBase: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include "GASObject.h"

class GFxMovieDef;

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

    std::uint32_t resourceID;  // 20
    std::int64_t createdFrame;  // 28
    GFxSprite* parentClip;  // 30
    float colorTransform[2][4];  // 38
    float matrix[3][2];  // 58
    std::uint64_t unk70;  // 70
    std::uint64_t unk78;  // 78
    std::uint64_t unk80;  // 80
    std::uint32_t unk88;  // 88
    std::uint32_t unk8C;  // 8C
    std::uint32_t unk90;  // 90
    std::uint16_t unk94;  // 94
    std::uint16_t unk96;  // 96 - flags
};
static_assert(sizeof(GFxCharacter) == 0x98, "GFxCharacter size");

class GFxASCharacter : public GFxCharacter, public GASObjectInterface
{
public:
    ~GFxASCharacter() override;  // 00

    void Functiond35d50();

    std::uint64_t unk0B0;  // 0B0
    std::uint64_t unk0B8;  // 0B8
    std::uint64_t unk0C0;  // 0C0
    GFxMovieDef* movieDef;  // 0C8
    std::uint64_t unk0D0[8];  // 0D0
};
static_assert(sizeof(GFxASCharacter) == 0x110, "GFxASCharacter size");
