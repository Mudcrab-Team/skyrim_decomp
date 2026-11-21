// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TextureAnimInfo; size 0x8
#pragma once
struct TextureAnimInfo {
    float currentFrame;
    unsigned int totalFrames;
};
static_assert(sizeof(TextureAnimInfo) == 8, "TextureAnimInfo layout differs from the PDB");
