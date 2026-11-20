// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GFxResourceKey; size 0x10
#pragma once

struct KeyInterface;
struct GFxResourceKey {
    KeyInterface* _keyInterface;
    void* _keyData;
};
static_assert(sizeof(GFxResourceKey) == 16, "GFxResourceKey layout differs from the PDB");
