// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: AnimationFileInfo; size 0xc
#pragma once
struct AnimationFileInfo {
    unsigned int crc32Filename;
    unsigned char extension[4];
    unsigned int crc32Path;
};
static_assert(sizeof(AnimationFileInfo) == 12, "AnimationFileInfo layout differs from the PDB");
