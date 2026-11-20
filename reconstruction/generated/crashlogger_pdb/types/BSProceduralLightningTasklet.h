// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSProceduralLightningTasklet; size 0xb0
#pragma once
struct BSProceduralLightningTasklet {
    unsigned char _base[8];  // BSTaskletData is 16 bytes in the PDB, more than this slot
    bool unk08;
    unsigned char pad09[7];
    void* unk10;
    bool active;
    unsigned char pad19[3];
    unsigned int unk1C;
    unsigned char unk20[96];
    void* linkedObject;
    unsigned short unk88;
    unsigned char pad8A[2];
    unsigned short unk8C;
    unsigned char pad8E[2];
    float floatData[4];
    void* unkA0;
    unsigned int unkA8;
    bool unkAC;
    unsigned char padAD[3];
};
static_assert(sizeof(BSProceduralLightningTasklet) == 176, "BSProceduralLightningTasklet layout differs from the PDB");
