// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSGameSound_vtbl; size 0xc8
#pragma once

#include "ErrorCode.h"
#include "SeekMode.h"
struct BSGameSound_vtbl {
    void (*OutputModelChangedImpl)(void);
    void (*_dtor_BSGameSound)(void);
    bool (*IsSoundFinished)(void);
    void (*SetSoundFinished)(bool);
    unsigned int (*GetCurrentPlaybackPosition)(void);
    bool (*PriorityTest)(char32_t* );
    bool (*SyncOpen)(void);
    bool (*StartAsyncOpen)(void);
    bool (*TestAsyncOpenReady)(void);
    bool (*FinishAsyncOpen)(void);
    bool (*HandleExternalOpen)(void);
    bool (*Prepare)(void);
    void (*Copy)(char32_t* );
    void (*UpdateEmitterPosition)(void);
    void (*Update)(char32_t* , char32_t* , char32_t* );
    void (*SetEmitterPositionImpl)(char32_t* );
    void (*GetEmitterPositionImpl)(char32_t* );
    void (*Unk_11)(void);
    void (*SetAttenuationCurve)(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short);
    void (*DoApplyFrequency)(void);
    ErrorCode (*Seek)(unsigned long long, SeekMode);
    void (*PlayImpl)(void);
    void (*PauseImpl)(void);
    void (*StopImpl)(void);
    void (*SetVolumeImpl)(void);
};
static_assert(sizeof(BSGameSound_vtbl) == 200, "BSGameSound_vtbl layout differs from the PDB");
