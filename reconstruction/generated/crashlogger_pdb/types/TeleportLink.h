// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TeleportLink; size 0x18
#pragma once

struct TESObjectREFR;
struct TeleportLink {
    TESObjectREFR* ref;
    unsigned char teleportLocation_raw[16];
};
static_assert(sizeof(TeleportLink) == 24, "TeleportLink layout differs from the PDB");
