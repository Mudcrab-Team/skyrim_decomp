// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SoundMessageList; size 0x10
#pragma once

struct BSSoundMessage;
struct SoundMessageList {
    BSSoundMessage* head;
    BSSoundMessage* tail;
};
static_assert(sizeof(SoundMessageList) == 16, "SoundMessageList layout differs from the PDB");
