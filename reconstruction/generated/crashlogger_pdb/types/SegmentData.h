// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SegmentData; size 0x14
#pragma once
struct SegmentData {
    unsigned int index;
    unsigned int unkTriCount;
    unsigned char unkFlags;
    unsigned char undefined_9[3];
    unsigned int numTris;
    unsigned char flags;
    unsigned char undefined_11[3];
};
static_assert(sizeof(SegmentData) == 20, "SegmentData layout differs from the PDB");
