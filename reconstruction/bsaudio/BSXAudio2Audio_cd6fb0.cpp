// Source exposure: binary-analysis.
// Code origin: original reconstruction; no external body copied.
// Original body using the observed allocation-category lifetime and virtual cleanup.
// BSXAudio2Audio, ReleaseGameSound: CRASHLOGGER_PDB(59818@2026.10.24)
// AudioAllocationScope: GUESS(low); inline allocation-category lifetime guard.
// Cookbook: 21
// 0xcd6fb0 BSXAudio2Audio::ReleaseGameSound
#include "BSXAudio2Audio_cd6fb0.h"

void BSXAudio2Audio::ReleaseGameSound(BSGameSound* sound)
{
    struct AudioAllocationScope {
        std::uint32_t savedTag;
        AudioAllocationScope() : savedTag(activeAudioAllocationTag) { activeAudioAllocationTag = 44; }
        ~AudioAllocationScope() { activeAudioAllocationTag = savedTag; }
    } allocationScope;
    delete sound;
}
