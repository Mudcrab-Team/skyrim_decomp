// Source exposure: binary-analysis.
// Code origin: original reconstruction; no external body copied.
// BSAudio, BSXAudio2Audio, XAudio, masteringVoice, speakerChannels, X3DAudioHandle, unk48: CRASHLOGGER_PDB(59818@2026.10.24)
// BSAudio: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// baseStorage, formatWords, unk40, padding41: GUESS(low); partial storage and unknown flag.
// 0xcd7020 BSXAudio2Audio::BSXAudio2Audio
#pragma once
#include <cstddef>
#include <cstdint>

class BSAudio {
public:
    BSAudio();
    virtual ~BSAudio();
    std::uint8_t baseStorage[0x10];
};
class BSXAudio2Audio : public BSAudio {
public:
    BSXAudio2Audio();
    ~BSXAudio2Audio() override;
    std::uint64_t formatWords[5];
    bool unk40;
    std::uint8_t padding41[7];
    std::uint64_t unk48;
    void* XAudio;
    void* masteringVoice;
    std::uint8_t X3DAudioHandle[20];
    std::uint32_t speakerChannels;
};
static_assert(sizeof(BSAudio) == 0x18, "audio base size");
static_assert(sizeof(BSXAudio2Audio) == 0x78, "audio device size");
static_assert(offsetof(BSXAudio2Audio, unk40) == 0x40, "device flag offset");
static_assert(offsetof(BSXAudio2Audio, XAudio) == 0x50, "audio interface offset");
static_assert(offsetof(BSXAudio2Audio, masteringVoice) == 0x58, "master voice offset");
static_assert(offsetof(BSXAudio2Audio, speakerChannels) == 0x74, "channel count offset");
