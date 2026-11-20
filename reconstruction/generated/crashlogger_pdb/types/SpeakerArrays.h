// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SpeakerArrays; size 0x18
#pragma once
struct SpeakerArrays {
    unsigned char channels_raw[24];
};
static_assert(sizeof(SpeakerArrays) == 24, "SpeakerArrays layout differs from the PDB");
