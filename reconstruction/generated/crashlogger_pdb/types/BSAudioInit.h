// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSAudioInit; size 0x58
#pragma once

#include "BSAudioCallbacks.h"
#include "BSFixedString_char_83b572b4.h"
struct ExternalIOInterface;
struct HWND;
struct BSAudioInit {
    BSFixedString_char_83b572b4 audioAPI;
    HWND* wnd;
    bool disableAudio;
    bool enableAudioCache;
    unsigned char pad12[2];
    unsigned int initialCacheSize;
    unsigned int maxAudioCacheSize;
    unsigned int maxSizeForCachedSound;
    unsigned int audioHWThread;
    unsigned int streamingThreshold;
    float defaultMasterVolume;
    unsigned char pad2C[4];
    ExternalIOInterface* externalAudioIO;
    BSFixedString_char_83b572b4 missingAssetSoundFile;
    BSAudioCallbacks audioCallbacks;
};
static_assert(sizeof(BSAudioInit) == 88, "BSAudioInit layout differs from the PDB");
