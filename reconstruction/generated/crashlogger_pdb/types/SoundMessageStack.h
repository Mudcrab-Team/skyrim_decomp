// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SoundMessageStack; size 0x18
#pragma once

struct BSSoundMessage;
struct SoundMessageStack {
    unsigned int size;
    bool bottomless;
    unsigned char pad05[3];
    BSSoundMessage* top;
    unsigned int lastUpdateTime;
    unsigned char pad14[4];
};
static_assert(sizeof(SoundMessageStack) == 24, "SoundMessageStack layout differs from the PDB");
