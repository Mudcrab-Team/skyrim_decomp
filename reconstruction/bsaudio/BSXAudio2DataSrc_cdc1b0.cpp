// Source exposure: mixed (pinned image and CrashLogger names/layout leads).
// Code origin: original hand-written reconstruction.
// BSXAudio2DataSrc: CRASHLOGGER_PDB(59818@2026.10.24)
// GetSampleCount: GUESS(low); inferred sample count from format-specific storage.
// 0xcdc1b0 BSXAudio2DataSrc::GetSampleCount
#include "BSXAudio2DataSrc_cdc1b0.h"

std::uint32_t BSXAudio2DataSrc::GetSampleCount() const
{
    std::uint32_t samples = 0;
    switch (format.wFormatTag) {
    case 1:
        samples = sourceBytes / format.nBlockAlign;
        break;
    case 0x161:
        samples = (decodedPacketCumulativeBytes[unk6C - 1] * 8) /
                  (format.wBitsPerSample * format.nChannels);
        break;
    case 0x166:
        samples = unk38;
        break;
    }
    return samples;
}
