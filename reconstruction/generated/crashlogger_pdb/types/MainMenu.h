// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MainMenu; size 0x60
#pragma once

#include "BSScaleformExternalTexture.h"
#include "BSTEventSink_RE__BSSaveDataEvent_771b90b5.h"
#include "BSTEventSink_RE__BSSystemEvent_a1441324.h"
#include "IMenu_09c1ffe2.h"
struct MainMenu {
    IMenu_09c1ffe2 _base;
    BSTEventSink_RE__BSSystemEvent_a1441324 _base_BSTEventSink_RE_BSSystemEvent_;
    BSTEventSink_RE__BSSaveDataEvent_771b90b5 _base_BSTEventSink_RE_BSSaveDataEvent_;
    BSScaleformExternalTexture gamerIconTexture;
    unsigned int unk68;
    unsigned char unk6C;
    unsigned char unk6D;
    unsigned char unk6E;
    unsigned char pad6F;
};
static_assert(sizeof(MainMenu) == 96, "MainMenu layout differs from the PDB");
