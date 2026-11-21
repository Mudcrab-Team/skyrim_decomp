// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: tWAVEFORMATEX; size 0x12
#pragma once
#pragma pack(push, 2)
struct tWAVEFORMATEX {
    unsigned short wFormatTag;
    unsigned short nChannels;
    unsigned int nSamplesPerSec;
    unsigned int nAvgBytesPerSec;
    unsigned short nBlockAlign;
    unsigned short wBitsPerSample;
    unsigned short cbSize;
};
#pragma pack(pop)
static_assert(sizeof(tWAVEFORMATEX) == 18, "tWAVEFORMATEX layout differs from the PDB");
