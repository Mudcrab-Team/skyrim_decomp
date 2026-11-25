// Source exposure: binary-analysis.
// Code origin: original reconstruction; no external body copied.
// BSXAudio2Audio, ReleaseGameSound, BSGameSound, OutputModelChangedImpl: CRASHLOGGER_PDB(59818@2026.10.24)
// BSGameSound: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// activeAudioAllocationTag: GUESS(low); thread-local allocation category.
// 0xcd6fb0 BSXAudio2Audio::ReleaseGameSound
#pragma once
#include <cstdint>

extern __declspec(thread) std::uint32_t activeAudioAllocationTag;
class BSGameSound {
public:
    virtual void OutputModelChangedImpl();
    virtual ~BSGameSound();
};
class BSXAudio2Audio {
public:
    void ReleaseGameSound(BSGameSound* sound);
};
