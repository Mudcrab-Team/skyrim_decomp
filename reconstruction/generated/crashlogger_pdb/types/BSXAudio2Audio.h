// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSXAudio2Audio; size 0x78
#pragma once

#include "BSAudio.h"
#include "WAVEFORMATEXTENSIBLE.h"
struct IXAudio2;
struct IXAudio2MasteringVoice;
struct BSXAudio2Audio {
    BSAudio _base;
    WAVEFORMATEXTENSIBLE outputFormat;
    unsigned int unk44;
    unsigned char undefined_44[4];
    unsigned long long unk48;
    IXAudio2* XAudio;
    IXAudio2MasteringVoice* masteringVoice;
    unsigned char X3DAudioHandle[20];
    unsigned int speakerChannels;
};
static_assert(sizeof(BSXAudio2Audio) == 120, "BSXAudio2Audio layout differs from the PDB");
