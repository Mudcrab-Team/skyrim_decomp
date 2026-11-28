// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSAnimNoteReceiver: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x221470 BSAnimNoteReceiver::dtor_deleting
// CI hash: 0x221470 ??_GBSAnimNoteReceiver@@UEAAPEAXI@Z
#include "BSAnimNoteReceiver_221470.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BSAnimNoteReceiver::BSAnimNoteReceiver()
{
}

// Deletes all remaining note entries before destroying the array and base extra data.
BSAnimNoteReceiver::~BSAnimNoteReceiver()
{
    std::uint16_t count = notes.size;
    for (std::uint16_t i = 0; i < count; ++i)
    {
        delete notes.RemoveEnd();
    }
}
