// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSXAudio2GameSound: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSXAudio2GameSound::Functioncd94c0: GUESS(low)
// 0xcd94c0 BSXAudio2GameSound::Functioncd94c0
#include "BSXAudio2GameSound_cd94c0.h"

// Query the underlying audio stream and return whether the call succeeds.
bool BSXAudio2GameSound::Functioncd94c0()
{
    if (src) {
        std::uint32_t status = 1;
        if (src->stream) {
            std::uint32_t out;
            status = src->stream->Unk_0A(&out, 0);
        }
        return status == 0;
    }
    return false;
}
