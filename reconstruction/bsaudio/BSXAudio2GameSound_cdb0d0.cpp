// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSXAudio2GameSound: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSXAudio2GameSound::Functioncdb0d0: GUESS(low)
// 0xcdb0d0 BSXAudio2GameSound::Functioncdb0d0
#include "BSXAudio2GameSound_cdb0d0.h"

// Record the current sample count and stop the XAudio2 source voice.
std::int32_t BSXAudio2GameSound::Functioncdb0d0()
{
    if (sourceVoice) {
        VoiceState state;
        sourceVoice->GetState(&state);
        samplesPlayed = static_cast<std::uint32_t>(state.samplesPlayed);
        return sourceVoice->Stop(0, 0);
    }
    return static_cast<std::int32_t>(0x80004005u);
}
