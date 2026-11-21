// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSSceneAction_vtbl; size 0xa0
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "EmotionType.h"
#include "FunctorType.h"
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct TESFile_8388152d;
struct BGSSceneAction_vtbl {
    void (*_dtor_BGSSceneAction)(void);
    bool (*LoadSceneAction)(TESFile_8388152d* );
    void (*Unk_02)(void);
    void (*Unk_03)(void);
    void (*ClearFlags)(void);
    bool (*Loops)(void);
    bool (*FacesTarget)(void);
    FunctorType (*GetType)(void);
    void (*Unk_08)(void);
    void (*LoadBuffer)(BGSLoadFormBuffer* );
    void (*SaveBuffer)(BGSSaveFormBuffer* );
    void (*ClearActiveFlags)(void);
    void (*Unk_0C)(void);
    void (*Unk_0D)(void);
    EmotionType (*GetEmotionType)(void);
    unsigned int (*GetEmotionValue)(void);
    void (*Unk_10)(void);
    void (*Unk_11)(void);
    void (*Unk_12)(void);
    void (*Unk_13)(void);
};
static_assert(sizeof(BGSSceneAction_vtbl) == 160, "BGSSceneAction_vtbl layout differs from the PDB");
