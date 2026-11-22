// Source exposure: mixed (community headers and pinned image).
// Code origin: existing unit plus original reconstruction of format and rate helpers.
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// BSXAudio2DataSrc, BSXAudio2DataSrc::~BSXAudio2DataSrc: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0) EXE_RTTI
// BSAudioDataSrc_VBSXAudio2DataSrc: STANDIN EXE_RTTI
// BSAudioDataSrc_VBSXAudio2DataSrc::~BSAudioDataSrc_VBSXAudio2DataSrc, unknown08, unknown18, formatTag, pad22, sampleRate, unknown28, field40, unknown44, Functioncdc210, Functioncdc240, Functioncdc280, Functioncdc2b0: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BSAudioDataSrc_VBSXAudio2DataSrc
{
public:
    virtual ~BSAudioDataSrc_VBSXAudio2DataSrc() = default;
    std::uint8_t unknown08[0x10];  // 08
};
static_assert(sizeof(BSAudioDataSrc_VBSXAudio2DataSrc) == 0x18, "BSAudioDataSrc_VBSXAudio2DataSrc size");

class BSXAudio2DataSrc : public BSAudioDataSrc_VBSXAudio2DataSrc
{
public:
    BSXAudio2DataSrc();
    virtual ~BSXAudio2DataSrc();  // compared: 0xcdc8e0 (scalar deleting destructor)

    std::uint32_t Functioncdc210() const;
    std::uint32_t Functioncdc240(std::uint32_t a_samples) const;
    std::uint32_t Functioncdc280(std::uint32_t a_milliseconds) const;
    void Functioncdc2b0(std::uint32_t* a_samples) const;

    std::uint8_t unknown18[0x8];  // 18
    std::uint16_t formatTag;  // 20
    std::uint16_t pad22;  // 22
    std::uint32_t sampleRate;  // 24
    std::uint8_t unknown28[0x18];  // 28
    std::uint32_t field40;  // 40
    std::uint8_t unknown44[0x7C];  // 44
};
static_assert(sizeof(BSXAudio2DataSrc) == 0xC0, "BSXAudio2DataSrc size");
