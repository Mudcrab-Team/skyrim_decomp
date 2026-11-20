// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: LengthCharacteristics; size 0x4
#pragma once
struct LengthCharacteristics {
    unsigned char unk0;
    unsigned char looping;  // Looping in the PDB is wider than this slot
    unsigned char unk2;
    unsigned char rumbleSendValue;
};
static_assert(sizeof(LengthCharacteristics) == 4, "LengthCharacteristics layout differs from the PDB");
