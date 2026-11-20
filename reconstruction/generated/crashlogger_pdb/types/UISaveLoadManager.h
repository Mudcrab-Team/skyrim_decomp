// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: UISaveLoadManager; size 0x68
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "BSScaleformExternalTexture.h"
#include "BSTEventSink_RE__BGSSaveLoadManagerEvent_dc6c2090.h"
#include "BSTEventSink_RE__BSSaveDataEvent_771b90b5.h"
#include "BSTSingletonSDM_RE__UISaveLoadManager_140c296d.h"
#include "GFxValue.h"
struct UISaveLoadManager {
    BSTEventSink_RE__BSSaveDataEvent_771b90b5 _base;
    BSTEventSink_RE__BGSSaveLoadManagerEvent_dc6c2090 _base_BSTEventSink_RE_BGSSaveLoadManagerEvent_;
    BSTSingletonSDM_RE__UISaveLoadManager_140c296d _base_BSTSingletonSDM_RE_UISaveLoadManager_;
    unsigned char undefined_11[7];
    BSScaleformExternalTexture screenshotTexture;
    GFxValue entryList;
    BSFixedString_char_83b572b4 menuName;
    unsigned long long unk50;
    unsigned long long unk58;
    unsigned char batchSize;
    bool unk61;
    unsigned short pad62;
    unsigned char undefined_64[4];
};
static_assert(sizeof(UISaveLoadManager) == 104, "UISaveLoadManager layout differs from the PDB");
