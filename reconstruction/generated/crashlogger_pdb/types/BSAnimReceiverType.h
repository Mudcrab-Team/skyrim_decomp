// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSAnimReceiverType; size 0x10
#pragma once

#include "AnimNoteType.h"
struct IBSAnimNoteReceiver;
struct BSAnimReceiverType {
    AnimNoteType noteType;
    unsigned int pad04;
    IBSAnimNoteReceiver* receiver;
};
static_assert(sizeof(BSAnimReceiverType) == 16, "BSAnimReceiverType layout differs from the PDB");
