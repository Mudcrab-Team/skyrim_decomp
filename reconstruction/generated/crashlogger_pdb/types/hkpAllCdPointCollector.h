// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpAllCdPointCollector; size 0x220
#pragma once

#include "hkInplaceArray_RE__hkpRootCdPoint_8_4c88b675.h"
#include "hkpCdPointCollector.h"
struct hkpAllCdPointCollector {
    hkpCdPointCollector _base;
    hkInplaceArray_RE__hkpRootCdPoint_8_4c88b675 hits;
};
static_assert(sizeof(hkpAllCdPointCollector) == 544, "hkpAllCdPointCollector layout differs from the PDB");
