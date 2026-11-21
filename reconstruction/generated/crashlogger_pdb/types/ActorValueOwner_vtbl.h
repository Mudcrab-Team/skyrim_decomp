// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ActorValueOwner_vtbl; size 0x48
#pragma once

#include "ACTOR_VALUE_MODIFIER.h"
#include "ActorValue_a2156ae9.h"
struct ActorValueOwner_vtbl {
    void (*_dtor_ActorValueOwner)(void);
    float (*GetActorValue)(ActorValue_a2156ae9);
    float (*GetPermanentActorValue)(ActorValue_a2156ae9);
    float (*GetBaseActorValue)(ActorValue_a2156ae9);
    void (*SetBaseActorValue)(ActorValue_a2156ae9, float);
    void (*ModBaseActorValue)(ActorValue_a2156ae9, float);
    void (*ModActorValue)(ACTOR_VALUE_MODIFIER, ActorValue_a2156ae9, float);
    void (*SetActorValue)(ActorValue_a2156ae9);
    bool (*GetIsPlayerOwner)(void);
};
static_assert(sizeof(ActorValueOwner_vtbl) == 72, "ActorValueOwner_vtbl layout differs from the PDB");
