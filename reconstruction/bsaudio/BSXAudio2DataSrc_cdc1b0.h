// Source exposure: mixed (pinned image and CrashLogger names/layout leads).
// Code origin: original reconstruction with minimal layout declarations.
// BSXAudio2DataSrc, format, sourceBytes, unk38, unk6C, decodedPacketCumulativeBytes, wFormatTag, nChannels, nSamplesPerSec, nAvgBytesPerSec, nBlockAlign, wBitsPerSample, cbSize: CRASHLOGGER_PDB(59818@2026.10.24)
// AudioWaveFormat: STANDIN GUESS(low); wave-format record at the observed offset.
// unk18, unk32, unk34, unk3C, unk40, unk48, unk50, unk58, unk60, unk68, unk70, unk78, unk80, unk88, unk90, unk98, unkA0: CRASHLOGGER_PDB(59818@2026.10.24)
// GetSampleCount, unk00, unk08, unk10: GUESS(low); base storage fields are not accessed.
// 0xcdc1b0 BSXAudio2DataSrc::GetSampleCount
#pragma once
#include <cstddef>
#include <cstdint>

#pragma pack(push, 2)
struct AudioWaveFormat {
    std::uint16_t wFormatTag;
    std::uint16_t nChannels;
    std::uint32_t nSamplesPerSec;
    std::uint32_t nAvgBytesPerSec;
    std::uint16_t nBlockAlign;
    std::uint16_t wBitsPerSample;
    std::uint16_t cbSize;
};
#pragma pack(pop)

class BSXAudio2DataSrc {
public:
    std::uint32_t GetSampleCount() const;

    std::uint64_t unk00;
    std::uint64_t unk08;
    std::uint64_t unk10;
    std::uint64_t unk18;
    AudioWaveFormat format;
    std::uint16_t unk32;
    std::uint32_t unk34;
    std::uint32_t unk38;
    std::uint32_t unk3C;
    std::uint64_t unk40;
    std::uint64_t unk48;
    std::uint64_t unk50;
    std::uint64_t unk58;
    std::uint32_t unk60;
    std::uint32_t sourceBytes;
    std::uint32_t unk68;
    std::uint32_t unk6C;
    std::uint64_t unk70;
    std::uint64_t unk78;
    std::uint64_t unk80;
    std::uint64_t unk88;
    std::uint64_t unk90;
    std::uint64_t unk98;
    std::uint64_t unkA0;
    std::uint32_t* decodedPacketCumulativeBytes;
};
static_assert(offsetof(BSXAudio2DataSrc, format) == 0x20, "wave format offset");
static_assert(offsetof(BSXAudio2DataSrc, unk38) == 0x38, "encoded sample count offset");
static_assert(offsetof(BSXAudio2DataSrc, sourceBytes) == 0x64, "source byte count offset");
static_assert(offsetof(BSXAudio2DataSrc, unk6C) == 0x6C, "packet count offset");
static_assert(offsetof(BSXAudio2DataSrc, decodedPacketCumulativeBytes) == 0xA8, "packet table offset");
