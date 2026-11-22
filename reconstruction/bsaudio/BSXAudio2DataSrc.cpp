// Source exposure: mixed (community headers and pinned image).
// Code origin: existing unit plus original reconstruction of format and rate helpers.
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none
// 0xcdc8e0 BSXAudio2DataSrc::~BSXAudio2DataSrc
// 0xcdc210 BSXAudio2DataSrc::Functioncdc210
// 0xcdc240 BSXAudio2DataSrc::Functioncdc240
// 0xcdc280 BSXAudio2DataSrc::Functioncdc280
// 0xcdc2b0 BSXAudio2DataSrc::Functioncdc2b0
#include "BSXAudio2DataSrc.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BSXAudio2DataSrc::BSXAudio2DataSrc()
{
}

std::uint32_t BSXAudio2DataSrc::Functioncdc210() const
{
    switch (formatTag) {
    case 0x0001:
    case 0x0161:
        return 0u;
    case 0x0166:
        return field40;
    default:
        return 0u;
    }
}

std::uint32_t BSXAudio2DataSrc::Functioncdc240(std::uint32_t a_samples) const
{
    return static_cast<std::uint32_t>((1000.0f / static_cast<float>(sampleRate)) * static_cast<float>(a_samples));
}

std::uint32_t BSXAudio2DataSrc::Functioncdc280(std::uint32_t a_milliseconds) const
{
    return static_cast<std::uint32_t>((static_cast<float>(sampleRate) * 0.001f) * static_cast<float>(a_milliseconds));
}

void BSXAudio2DataSrc::Functioncdc2b0(std::uint32_t* a_samples) const
{
    std::uint32_t align = 0u;
    switch (formatTag) {
    case 0x0001:
        align = 1u;
        break;
    case 0x0161:
        align = 1u;
        break;
    case 0x0166:
        align = 128u;
        break;
    default:
        return;
    }
    if (align > 1u) {
        *a_samples &= ~(align - 1u);
    }
}
