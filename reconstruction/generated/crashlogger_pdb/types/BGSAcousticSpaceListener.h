// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSAcousticSpaceListener; size 0x50
#pragma once

#include "hkpEntityListener.h"
struct Entry;
struct BGSAcousticSpaceListener {
    hkpEntityListener _base;
    void* unk08;
    unsigned int count;
    unsigned int capacity;
    unsigned int numBuckets;
    unsigned int pad1C;
    Entry* entries;
    unsigned char unk28[40];
};
static_assert(sizeof(BGSAcousticSpaceListener) == 80, "BGSAcousticSpaceListener layout differs from the PDB");
