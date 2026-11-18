// Code origin: hand-written class layouts and declarations adapted from the CharmedBaryon/CommonLibSSE-NG headers named below; the compared body is written from the local listing.
// Source exposure: mixed (community declarations and the contributor-owned pack;
// bases, sizes and slots are community hypotheses).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiSourceTexture, NiSourceTexture::Unk_25, NiSourceTexture::~NiSourceTexture, NiSourceTexture::GetRTTI, NiSourceTexture::Unk_26, NiSourceTexture::Unk_27, NiSourceTexture::Unk_28, NiSourceTexture::Unk_29, NiSourceTexture::Unk_2A, NiTexture::GetRTTI, NiTexture::Unk_25, NiTexture::Unk_26, NiTexture::Unk_27, NiTexture::Unk_28, NiTexture::Unk_29, NiTexture::Unk_2A: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiTexture: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// FormatPrefs, BSFixedString, NiTexture::formatPrefs, name, unk28, unk2C, prev, next, NiSourceTexture::unk40, rendererTexture, flags, pad51, pad52, pad54: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>
#include "declarations/NiObject.h"

class BSResourceStream;
class BSGraphicsTexture;

struct NiTextureFormatPrefs
{
    std::uint32_t pixelLayout;  // 00
    std::uint32_t alphaFormat;  // 04
    std::uint32_t mipMapped;  // 08
    std::uint32_t pad0C;  // 0C
};
static_assert(sizeof(NiTextureFormatPrefs) == 0x10, "FormatPrefs size");

struct BSFixedString
{
    const char* data;  // 00
};

class NiTexture : public NiObject
{
public:
    const NiRTTI* GetRTTI() const override;  // 02
    virtual std::uint64_t Unk_25(void);  // 25 (result type is a low-confidence guess)
    virtual void Unk_26(void);  // 26
    virtual void Unk_27(void);  // 27
    virtual void Unk_28(void);  // 28
    virtual void Unk_29(void);  // 29
    virtual void Unk_2A(void);  // 2A
    NiTextureFormatPrefs formatPrefs;  // 10
    BSFixedString name;  // 20
    std::uint32_t unk28;  // 28
    std::uint32_t unk2C;  // 2C
    NiTexture* prev;  // 30
    NiTexture* next;  // 38
};
static_assert(sizeof(NiTexture) == 0x40, "NiTexture size");

class NiSourceTexture : public NiTexture
{
public:
    ~NiSourceTexture() override;  // 00
    const NiRTTI* GetRTTI() const override;  // 02
    std::uint64_t Unk_25();  // compared: 0xef3500  // slot 25
    void Unk_26(void) override;  // 26
    void Unk_27(void) override;  // 27
    void Unk_28(void) override;  // 28
    void Unk_29(void) override;  // 29
    void Unk_2A(void) override;  // 2A

    BSResourceStream* unk40;  // 40
    BSGraphicsTexture* rendererTexture;  // 48
    std::uint8_t flags;  // 50
    std::uint8_t pad51;  // 51
    std::uint16_t pad52;  // 52
    std::uint32_t pad54;  // 54
};
static_assert(sizeof(NiSourceTexture) == 0x58, "NiSourceTexture size");
static_assert(offsetof(NiSourceTexture, rendererTexture) == 0x48, "NiSourceTexture members");
