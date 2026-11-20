// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IAnimationGraphManagerHolder_vtbl; size 0x98
#pragma once
struct IAnimationGraphManagerHolder_vtbl {
    void (*_dtor_IAnimationGraphManagerHolder)(void);
    bool (*NotifyAnimationGraph)(char32_t* );
    bool (*GetAnimationGraphManagerImpl)(char32_t* );
    bool (*SetAnimationGraphManagerImpl)(char32_t* );
    bool (*PopulateGraphNodesToTarget)(char32_t* );
    bool (*ConstructAnimationGraph)(char32_t* );
    void (*Unk_06)(void);
    void (*Unk_07)(void);
    bool (*SetupAnimEventSinks)(char32_t* );
    void (*Unk_09)(void);
    bool (*CreateAnimationChannels)(char32_t* );
    void (*PostCreateAnimationGraphManager)(char32_t* );
    void (*Unk_0C)(void);
    void (*PostChangeAnimationManager)(char32_t* , char32_t* );
    void (*Unk_0E)(void);
    unsigned int (*GetGraphVariableCacheSize)(void);
    bool (*GetGraphVariableImpl1)(char32_t* , float* );
    bool (*GetGraphVariableImpl2)(char32_t* , int* );
    bool (*GetGraphVariableImpl3)(char32_t* , bool* );
};
static_assert(sizeof(IAnimationGraphManagerHolder_vtbl) == 152, "IAnimationGraphManagerHolder_vtbl layout differs from the PDB");
