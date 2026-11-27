// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSXAudio2GameSound: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSXAudio2GameSound::Functioncd5a40: GUESS(low)
// 0xcd5a40 BSXAudio2GameSound::Functioncd5a40
#include "BSXAudio2GameSound_cd5a40.h"

// Invoke and clear the stored callback before forwarding to virtual cleanup.
void BSXAudio2GameSound::Functioncd5a40()
{
    if (callback) {
        callback(callbackArg, durationMilliseconds);
        callbackArg = nullptr;
        callback = nullptr;
    }
    Unk_15();
}
