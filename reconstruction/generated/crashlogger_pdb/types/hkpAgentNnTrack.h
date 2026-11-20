// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpAgentNnTrack; size 0x20
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkInplaceArray_RE__hkpAgentNnSector_1_b89bb282.h"
struct hkpAgentNnTrack {
    unsigned short bytesUsedInLastSector;
    unsigned char nnTrackType;  // hkpAgentNnTrackType in the PDB is wider than this slot
    unsigned char padding;
    unsigned int pad04;
    hkInplaceArray_RE__hkpAgentNnSector_1_b89bb282 sectors;
};
static_assert(sizeof(hkpAgentNnTrack) == 32, "hkpAgentNnTrack layout differs from the PDB");
