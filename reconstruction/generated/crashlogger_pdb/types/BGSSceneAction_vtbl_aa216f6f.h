// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSSceneAction_vtbl; size 0xa0
// one of 2 different PDB types sharing this name
#pragma once

#include "EmotionType.h"
#include "hkpPhantomType.h"
struct BGSSceneAction_vtbl_aa216f6f {
    void (*_dtor_BGSSceneAction)(void);
    bool (*LoadSceneAction)(char32_t* );
    void (*Unk_02)(void);
    void (*Unk_03)(void);
    void (*ClearFlags)(void);
    bool (*Loops)(void);
    bool (*FacesTarget)(void);
    hkpPhantomType (*GetType)(void);
    void (*Unk_08)(void);
    void (*LoadBuffer)(char32_t* );
    void (*SaveBuffer)(char32_t* );
    void (*ClearActiveFlags)(void);
    void (*Unk_0C)(void);
    void (*Unk_0D)(void);
    EmotionType (*GetEmotionType)(void);
    unsigned int (*GetEmotionValue)(void);
    unsigned int (*Unk_10)(void);
    void (*Unk_11)(void);
    void (*Unk_12)(void);
    void (*Unk_13)(void);
};
static_assert(sizeof(BGSSceneAction_vtbl_aa216f6f) == 160, "BGSSceneAction_vtbl_aa216f6f layout differs from the PDB");
