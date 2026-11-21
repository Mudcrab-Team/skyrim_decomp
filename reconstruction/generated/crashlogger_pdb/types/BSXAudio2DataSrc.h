// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSXAudio2DataSrc; size 0xc0
#pragma once

#include "BSAudioDataSrc_RE__BSXAudio2DataSrc_451b692c.h"
#include "tWAVEFORMATEX.h"
struct BSXAudio2DataSrc {
    BSAudioDataSrc_RE__BSXAudio2DataSrc_451b692c _base;
    unsigned long long unk18;
    tWAVEFORMATEX format;
    unsigned short unk32;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned long long unk48;
    unsigned long long unk50;
    unsigned long long unk58;
    unsigned int unk60;
    unsigned int sourceBytes;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned long long unk70;
    unsigned int unk78;
    unsigned char pad7C[4];
    unsigned long long unk80;
    unsigned int unk88;
    unsigned int pad8C;
    unsigned long long unk90;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned long long unkA0;
    unsigned int* decodedPacketCumulativeBytes;
    unsigned int audioBytes;
    unsigned char padB4[4];
    unsigned char* audioData;
};
static_assert(sizeof(BSXAudio2DataSrc) == 192, "BSXAudio2DataSrc layout differs from the PDB");
