// Source exposure: mixed (pinned image and labelled name/declaration sources).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Code origin: original hand-written reconstruction.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSXAudio2Audio: CRASHLOGGER_PDB(59818@2026.10.24)
// ReleaseGameSound: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// AudioMemoryScope, previous: GUESS(low); restores the allocation context during unwinding.
// Cookbook: 21
// 0xcd7a60 BSXAudio2Audio::ReleaseGameSound
#include "BSXAudio2Audio_cd7a60.h"

class AudioMemoryScope {
public:
    AudioMemoryScope() : previous(audioMemoryContext)
    {
        audioMemoryContext = 0x2C;
    }
    ~AudioMemoryScope() { audioMemoryContext = previous; }
private:
    std::uint32_t previous;
};

void BSXAudio2Audio::ReleaseGameSound(BSGameSound* sound)
{
    AudioMemoryScope scope;
    if (sound) {
        sound->Unk_12();
    }
}
