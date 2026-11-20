// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PackageEventAction; size 0x20
#pragma once

#include "PACK_EVENT_ACTION_TYPE.h"
#include "TopicData.h"
struct TESIdleForm_2b3518b0;
struct PackageEventAction {
    TESIdleForm_2b3518b0* idle;
    PACK_EVENT_ACTION_TYPE type;
    unsigned int pad0C;
    TopicData topic;
};
static_assert(sizeof(PackageEventAction) == 32, "PackageEventAction layout differs from the PDB");
