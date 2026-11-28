// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BGSStoryEvent: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x532760 BGSStoryEvent::BGSStoryEvent
// CI hash: 0x532760 ??0BGSStoryEvent@@QEAA@XZ
#include "BGSStoryEvent_532760.h"

// Initializes a story event with sentinel header and cleared fields.
BGSStoryEvent::BGSStoryEvent()
    : unk00(~0ULL)
    , unk08(0)
    , unk10(0)
    , unk18(0)
    , unk20(0)
    , unk28(0)
    , unk30(0)
{
}
