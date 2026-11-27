// Source exposure: mixed.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSXAudio2GameSound: STANDIN COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// BSXAudio2GameSound::Functioncd53d0: GUESS(low)
// BSXAudio2GameSound::flags, BSXAudio2GameSound::state: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>



class BSXAudio2GameSound
{
public:
    std::uint32_t Functioncd53d0(bool enabled);
    std::uint8_t unknown0[92];
    std::uint32_t flags;
    std::uint32_t state;
};
static_assert(offsetof(BSXAudio2GameSound, flags) == 92, "field offset");
static_assert(offsetof(BSXAudio2GameSound, state) == 96, "field offset");
