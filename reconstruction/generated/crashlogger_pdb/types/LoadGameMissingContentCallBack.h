// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: LoadGameMissingContentCallBack; size 0x20
#pragma once

#include "IMessageBoxCallback.h"
struct LoadGameMissingContentCallBack {
    IMessageBoxCallback _base;
    unsigned char undefined_10[16];
};
static_assert(sizeof(LoadGameMissingContentCallBack) == 32, "LoadGameMissingContentCallBack layout differs from the PDB");
