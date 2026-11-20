// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BIPOBJECT; size 0x78
#pragma once

#include "BSTObjectArena_RE__BSResource__RHandleType_RE__BSResource__Entry_RE__NiPointer_RE__NiNo_79a8f4fc.h"
#include "BSTSmartPointer_RE__WeaponAnimationGraphManagerHolder_6a25477e.h"
#include "NiPointer_RE__NiAVObject_9e3aa701.h"
#include "RHandleType_RE__BSResource__Entry_RE__NiPointer_RE__NiNode_RE__BSResource__EntryDBTrait_03dfb265.h"
struct BGSTextureSet;
struct TESForm;
struct TESModel_c52655e4;
struct TESObjectARMA_acbaea74;
struct BIPOBJECT {
    TESForm* item;
    TESObjectARMA_acbaea74* addon;
    TESModel_c52655e4* part;
    BGSTextureSet* skinTexture;
    NiPointer_RE__NiAVObject_9e3aa701 partClone;
    BSTObjectArena_RE__BSResource__RHandleType_RE__BSResource__Entry_RE__NiPointer_RE__NiNo_79a8f4fc handleList;
    BSTSmartPointer_RE__WeaponAnimationGraphManagerHolder_6a25477e weaponManager;
    bool skinned;
    unsigned char undefined_69[7];
    RHandleType_RE__BSResource__Entry_RE__NiPointer_RE__NiNode_RE__BSResource__EntryDBTrait_03dfb265 partHandle;
};
static_assert(sizeof(BIPOBJECT) == 120, "BIPOBJECT layout differs from the PDB");
