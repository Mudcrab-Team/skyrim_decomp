// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: StreamPacket; size 0x10130
#pragma once
struct StreamPacket {
    unsigned int size;
    unsigned int dataOffset;
    unsigned int unk00008[64];
    unsigned char data[65536];
    unsigned long long unk10108;
    unsigned int unk10110;
    unsigned int unk10114;
    unsigned long long unk10118;
    unsigned long long unk10120;
    unsigned char* unk10128;
};
static_assert(sizeof(StreamPacket) == 65840, "StreamPacket layout differs from the PDB");
