// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IAnimationGraphManagerHolder__VFTable; size 0x98
#pragma once

struct IAnimationGraphManagerHolder;
struct PlayerCharacter;
struct IAnimationGraphManagerHolder__VFTable {
    long long (*dtor_0)(long long, char, long long);
    long long (*NotifyAnimationGraph_8)(IAnimationGraphManagerHolder* );
    long long (*GetAnimationGraphManagerImpl_10)(IAnimationGraphManagerHolder* , long long* );
    void (*SetAnimationGraphManagerImpl_18)(IAnimationGraphManagerHolder* , unsigned long long* );
    void*(*PopulateGraphNodesToTarget_20)(PlayerCharacter* , char* );
    void (*ConstructAnimationGraph_28)(IAnimationGraphManagerHolder* , long long* );
    char (*Func6_30)(void);
    char (*Func7_38)(void);
    char (*SetupAnimEventSinks_40)(IAnimationGraphManagerHolder* , long long* );
    void (*Func9_48)(void);
    char (*Func10_50)(void);
    void (*Func11_58)(void);
    void (*Func12_60)(void);
    char (*PostChangeAnimationManager_68)(IAnimationGraphManagerHolder* , unsigned long long* , long long);
    char (*Func14_70)(void);
    long long (*GetGraphVariableCacheSize_78)(void);
    int (*GetGraphVariableImplFloat_80)(void);
    int (*GetGraphVariableImplInt_88)(void);
    int (*GetGraphVariableImplBool_90)(void);
};
static_assert(sizeof(IAnimationGraphManagerHolder__VFTable) == 152, "IAnimationGraphManagerHolder__VFTable layout differs from the PDB");
