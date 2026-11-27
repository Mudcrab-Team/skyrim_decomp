// CI hash: 0xcd53d0 ?Functioncd53d0@BSXAudio2GameSound@@QEAAI_N@Z
// Source exposure: mixed.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSXAudio2GameSound: STANDIN COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// BSXAudio2GameSound::Functioncd53d0: GUESS(low)
// BSXAudio2GameSound::flags, BSXAudio2GameSound::state: GUESS(low)
// 0xcd53d0 BSXAudio2GameSound::Functioncd53d0
#include "BSXAudio2GameSound_cd53d0.h"

// Read or update the stored values.
std::uint32_t BSXAudio2GameSound::Functioncd53d0(bool enabled)
{
    if (enabled) {
        flags = (flags & ~(1u << 12)) | 257;
    } else {
        state = 1;
        flags = (flags & 0xffffeeff) | 17;
    }
    return enabled;
}
