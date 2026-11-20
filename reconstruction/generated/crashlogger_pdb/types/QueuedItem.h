// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: QueuedItem; size 0x48
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "NiPointer_RE__QueuedFile_61648701.h"
#include "ObjectEquipParams.h"
struct TESBoundObject_fc790793;
struct QueuedItem {
    QueuedItem* next;
    TESBoundObject_fc790793* object;
    ObjectEquipParams equipParams;
    NiPointer_RE__QueuedFile_61648701 queuedFiles;
    bool equip;
    unsigned char pad41;
    unsigned short pad42;
    unsigned int pad44;
};
static_assert(sizeof(QueuedItem) == 72, "QueuedItem layout differs from the PDB");
