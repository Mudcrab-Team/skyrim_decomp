// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSXAudio2GameSound: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSXAudio2GameSound::Functioncd5830: GUESS(low)
// 0xcd5830 BSXAudio2GameSound::Functioncd5830
#include "BSXAudio2GameSound_cd5830.h"

// Return the output model's check when present, otherwise bit 0 of soundType.
bool BSXAudio2GameSound::Functioncd5830()
{
    bool result = (soundType & 1u) != 0;
    if (outputModel) {
        result = outputModel->Unk_04() && outputModel->Unk_01();
    }
    return result;
}
