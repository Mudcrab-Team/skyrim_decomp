// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpEntityActivationListener__VFTable; size 0x18
#pragma once

struct hkpEntityActivationListener;
struct hkpEntity_b3bc9432;
struct hkpEntityActivationListener__VFTable {
    void (*dtor_0)(hkpEntityActivationListener* );
    void (*entityDeactivatedCallback_8)(hkpEntityActivationListener* , hkpEntity_b3bc9432* );
    void (*entityActivatedCallback_10)(hkpEntityActivationListener* , hkpEntity_b3bc9432* );
};
static_assert(sizeof(hkpEntityActivationListener__VFTable) == 24, "hkpEntityActivationListener__VFTable layout differs from the PDB");
