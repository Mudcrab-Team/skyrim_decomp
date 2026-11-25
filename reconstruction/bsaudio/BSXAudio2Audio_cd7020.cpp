// Source exposure: binary-analysis.
// Code origin: original reconstruction; no external body copied.
// Original constructor using observed member initialization and partial type evidence.
// BSAudio, BSXAudio2Audio: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xcd7020 BSXAudio2Audio::BSXAudio2Audio
#include "BSXAudio2Audio_cd7020.h"

BSXAudio2Audio::BSXAudio2Audio() : unk40(false), XAudio(nullptr), masteringVoice(nullptr), speakerChannels(6)
{
    formatWords[0] = 0;
    formatWords[1] = 0;
    formatWords[2] = 0;
    formatWords[3] = 0;
    formatWords[4] = 0;
}
