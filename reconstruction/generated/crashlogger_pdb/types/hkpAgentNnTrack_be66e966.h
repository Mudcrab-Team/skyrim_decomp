// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpAgentNnTrack; size 0x20
// one of 2 different PDB types sharing this name
#pragma once

#include "EnumSet_RE__hkpAgentNnTrackType_unsigned_char_c3be840a.h"
#include "hkInplaceArray_RE__hkpAgentNnSector_1_b89bb282.h"
struct hkpAgentNnTrack_be66e966 {
    unsigned short bytesUsedInLastSector;
    EnumSet_RE__hkpAgentNnTrackType_unsigned_char_c3be840a nnTrackType;
    unsigned char padding;
    unsigned int pad04;
    hkInplaceArray_RE__hkpAgentNnSector_1_b89bb282 sectors;
};
static_assert(sizeof(hkpAgentNnTrack_be66e966) == 32, "hkpAgentNnTrack_be66e966 layout differs from the PDB");
