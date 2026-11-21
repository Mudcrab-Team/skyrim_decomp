// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESCameraState__VFTable; size 0x48
#pragma once

struct TESCameraState_b107d5ca;
struct TESCameraState__VFTable {
    unsigned long long*(*dtor_0)(TESCameraState_b107d5ca* , char);
    void (*OnEnterState_8)(void);
    void (*OnExitState_10)(void);
    int (*Update_18)(TESCameraState_b107d5ca* , long long* );
    void (*GetCurrentRotation_20)(TESCameraState_b107d5ca* , unsigned long long* );
    void (*GetCurrentPosition_28)(TESCameraState_b107d5ca* , long long);
    void (*WriteToStream_30)(void);
    void (*ReadFromStream_38)(void);
    void (*Reset_40)(void);
};
static_assert(sizeof(TESCameraState__VFTable) == 72, "TESCameraState__VFTable layout differs from the PDB");
