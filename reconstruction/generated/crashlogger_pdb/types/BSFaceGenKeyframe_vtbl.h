// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSFaceGenKeyframe_vtbl; size 0x70
#pragma once
struct BSFaceGenKeyframe_vtbl {
    void (*_dtor_BSFaceGenKeyframe)(void);
    void (*Unk_01)(void);
    bool (*Interpolate)(char32_t* , char32_t* , float);
    bool (*Interpolate_2)(char32_t* , char32_t* , float);
    void (*Reset)(void);
    char32_t*(*Clone)(char32_t* , char32_t* );
    void (*Copy)(char32_t* );
    bool (*NotEqual)(char32_t* );
    float (*GetMaxValue)(void);
    bool (*IsZero)(void);
    bool (*TransitionUpdate)(float, char32_t* );
    bool (*NotZero)(void);
    bool (*IsKeyframeMultiple)(void);
    bool (*IsKeyframeExclusive)(void);
};
static_assert(sizeof(BSFaceGenKeyframe_vtbl) == 112, "BSFaceGenKeyframe_vtbl layout differs from the PDB");
