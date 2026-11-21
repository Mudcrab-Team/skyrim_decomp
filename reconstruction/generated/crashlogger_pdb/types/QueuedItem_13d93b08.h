// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: QueuedItem; size 0x48
// one of 2 different PDB types sharing this name
#pragma once

#include "NiPointer_QueuedFile_14ac7c8f.h"
#include "ObjectEquipParams_3100cf69.h"
struct TESBoundObject;
struct QueuedItem_13d93b08 {
    QueuedItem_13d93b08* Next_0;
    TESBoundObject* Object_8;
    ObjectEquipParams_3100cf69 EquipParams_10;
    NiPointer_QueuedFile_14ac7c8f QueuedFiles_38;
    bool Equip_40;
    char _pad_41[7];
};
static_assert(sizeof(QueuedItem_13d93b08) == 72, "QueuedItem_13d93b08 layout differs from the PDB");
