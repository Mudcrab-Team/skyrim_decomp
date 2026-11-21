// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSSoundMessage; size 0x40
#pragma once

#include "NiPointer_RE__NiAVObject_9e3aa701.h"
#include "SOUND_MSG.h"
struct BSSoundMessage {
    SOUND_MSG message;
    unsigned int id;
    int iData;
    unsigned char pad0C[4];
    void* pData;
    NiPointer_RE__NiAVObject_9e3aa701 spData;
    unsigned char curveValue_raw[12];
    unsigned char pad2C[4];
    BSSoundMessage* next;
    BSSoundMessage* prev;
};
static_assert(sizeof(BSSoundMessage) == 64, "BSSoundMessage layout differs from the PDB");
