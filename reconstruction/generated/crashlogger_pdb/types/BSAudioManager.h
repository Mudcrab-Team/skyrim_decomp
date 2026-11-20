// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSAudioManager; size 0x190
#pragma once

#include "BSAudioCallbacks.h"
#include "BSAudioInit.h"
#include "BSTList_RE__BSGameSound_ef0b5286.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_36119647.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_477d9998.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_f3937019.h"
#include "Flags_fa7f7281.h"
#include "RE__BSTScatterTable_RE__BSCRC32_RE__NiAVObject_std__equal_to_RE__NiAVObject_RE__BSTScat_6462ddca.h"
struct BSAudioManagerThread;
struct SoundMessageList;
struct SoundMessageStack;
struct BSAudioManager {
    unsigned int frontQueue;
    unsigned int backQueue;
    SoundMessageList* messageQueues[2];
    SoundMessageStack* freeMessages;
    SoundMessageStack* processedMessages;
    BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_f3937019 activeSounds;
    BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_477d9998 stateMap;
    BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_36119647 movingSounds;
    RE__BSTScatterTable_RE__BSCRC32_RE__NiAVObject_std__equal_to_RE__NiAVObject_RE__BSTScat_6462ddca objectOutputOverrides;
    BSTList_RE__BSGameSound_ef0b5286 audioCache;
    unsigned int audioCacheSize;
    unsigned int ownerThreadID;
    BSAudioManagerThread* ownerThread;
    unsigned int unk100;
    unsigned int audioHWThread;
    BSAudioInit initSettings;
    unsigned int maxCacheSize;
    unsigned int maxAudioCacheSize;
    unsigned int maxSizeForCachedSound;
    Flags_fa7f7281 flags;
    float masterVolume;
    unsigned int asyncReadPriorityThreshold;
    BSAudioCallbacks audioCallbacks;
};
static_assert(sizeof(BSAudioManager) == 400, "BSAudioManager layout differs from the PDB");
