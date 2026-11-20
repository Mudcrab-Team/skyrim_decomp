// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MagicCaster_vtbl; size 0xe8
#pragma once

#include "CannotCastReason.h"
#include "CastingSource.h"
#include "SoundID.h"
struct MagicCaster_vtbl {
    void (*_dtor_MagicCaster)(void);
    void (*CastSpellImmediate)(char32_t* , bool, char32_t* , float, bool, float, char32_t* );
    void (*FindTouchTarget)(void);
    void (*RequestCastImpl)(void);
    bool (*StartChargeImpl)(void);
    void (*StartReadyImpl)(void);
    void (*StartCastImpl)(void);
    void (*FinishCastImpl)(void);
    void (*InterruptCastImpl)(bool);
    void (*SpellCast)(bool, unsigned int, char32_t* );
    bool (*CheckCast)(char32_t* , bool, CannotCastReason* );
    char32_t*(*GetCasterStatsObject)(void);
    char32_t*(*GetCasterAsActor)(void);
    char32_t*(*GetCasterObjectReference)(char32_t** );
    char32_t*(*GetMagicNode)(void);
    void (*ClearMagicNode)(void);
    void (*SetCurrentSpellImpl)(char32_t* );
    void (*SelectSpellImpl)(void);
    void (*DeselectSpellImpl)(void);
    void (*SetSkipCheckCast)(void);
    void (*SetCastingTimerForCharge)(void);
    CastingSource (*GetCastingSource)(void);
    bool (*GetIsDualCasting)(void);
    void (*SetDualCasting)(bool);
    void (*SaveGame)(char32_t* );
    void (*LoadGame)(char32_t* );
    void (*FinishLoadGame)(char32_t* );
    void (*PrepareSound)(SoundID, char32_t* );
    void (*AdjustActiveEffect)(char32_t* , float, bool);
};
static_assert(sizeof(MagicCaster_vtbl) == 232, "MagicCaster_vtbl layout differs from the PDB");
