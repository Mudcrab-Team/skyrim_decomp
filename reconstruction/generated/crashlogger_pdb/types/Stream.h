// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Stream; size 0x18
// one of 3 different PDB types sharing this name; the fullest
#pragma once

#include "StreamBase.h"
struct Stream {
    StreamBase _base;
};
static_assert(sizeof(Stream) == 24, "Stream layout differs from the PDB");
