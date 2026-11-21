// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PackageSchedule; size 0xc
#pragma once

#include "PACK_SCHED_DATA.h"
struct PackageSchedule {
    PACK_SCHED_DATA psData;
};
static_assert(sizeof(PackageSchedule) == 12, "PackageSchedule layout differs from the PDB");
