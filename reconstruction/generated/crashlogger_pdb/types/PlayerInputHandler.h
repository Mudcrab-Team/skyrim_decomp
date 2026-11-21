// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PlayerInputHandler; size 0x10
#pragma once

struct PlayerInputHandler_vtbl;
struct PlayerInputHandler {
    PlayerInputHandler_vtbl* __vftable;
    bool inputEventHandlingEnabled;
    unsigned char pad09;
    unsigned short pad0A;
    unsigned int pad0C;
};
static_assert(sizeof(PlayerInputHandler) == 16, "PlayerInputHandler layout differs from the PDB");
