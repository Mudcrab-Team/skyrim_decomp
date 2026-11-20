// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DialogueResponse; size 0x40
#pragma once

#include "BSFixedString.h"
#include "BSString.h"
struct BGSSoundDescriptorForm_de361764;
struct TESIdleForm;
struct DialogueResponse {
    BSString ResponseText_0;
    int EmotionType_10;
    int EmotionValue_14;
    BSFixedString Voice_18;
    TESIdleForm* SpeakerIdle_20;
    TESIdleForm* ListenerIdle_28;
    BGSSoundDescriptorForm_de361764* VoiceSound_30;
    bool UseEmotion_38;
    bool SoundLip_39;
    char _pad_3A[6];
};
static_assert(sizeof(DialogueResponse) == 64, "DialogueResponse layout differs from the PDB");
