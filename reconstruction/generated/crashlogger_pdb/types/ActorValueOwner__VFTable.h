// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ActorValueOwner__VFTable; size 0x48
#pragma once

struct ActorValueOwner_a5cb15e5;
struct ActorValueOwner__VFTable {
    unsigned long long*(*dtor_0)(ActorValueOwner_a5cb15e5* , char);
    float (*GetActorValue_8)(ActorValueOwner_a5cb15e5* , int);
    float (*GetActorValueMax_10)(ActorValueOwner_a5cb15e5* , int);
    float (*GetBaseActorValue_18)(ActorValueOwner_a5cb15e5* , int);
    void (*SetBaseActorValue_20)(void);
    void (*ModifyActorValue_28)(void);
    void (*ModActorValue_30)(ActorValueOwner_a5cb15e5* , int, int, float);
    void (*SetActorValue_38)(ActorValueOwner_a5cb15e5* , int, float);
    char (*IsPlayerOwner_40)(void);
};
static_assert(sizeof(ActorValueOwner__VFTable) == 72, "ActorValueOwner__VFTable layout differs from the PDB");
