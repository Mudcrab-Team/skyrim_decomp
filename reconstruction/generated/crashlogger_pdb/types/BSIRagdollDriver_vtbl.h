// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSIRagdollDriver_vtbl; size 0x70
#pragma once

#include "MotionType.h"
struct BSIRagdollDriver_vtbl {
    void (*_dtor_BSIRagdollDriver)(void);
    bool (*HasRagdoll)(void);
    bool (*AddRagdollToWorld)(void);
    bool (*RemoveRagdollFromWorld)(void);
    void (*SetWorld)(char32_t* );
    void (*ResetRagdoll)(void);
    void (*Unk_06)(void);
    void (*SetRagdollConstraintsFromBhkConstraints)(void);
    void (*SetMotionType)(MotionType);
    void (*Unk_09)(void);
    void (*ToggleSyncOnUpdate)(bool);
    void (*Unk_0B)(void);
    void (*ToggleConstraints)(bool);
    void (*Unk_0D)(void);
};
static_assert(sizeof(BSIRagdollDriver_vtbl) == 112, "BSIRagdollDriver_vtbl layout differs from the PDB");
