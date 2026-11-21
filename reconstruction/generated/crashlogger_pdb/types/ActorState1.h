// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ActorState1; size 0x4
#pragma once
struct ActorState1 {
    unsigned int movingBack : 1;
    unsigned int movingForward : 1;
    unsigned int movingRight : 1;
    unsigned int movingLeft : 1;
    unsigned int unk04 : 2;
    unsigned int walking : 1;
    unsigned int running : 1;
    unsigned int sprinting : 1;
    unsigned int sneaking : 1;
    unsigned int swimming : 1;
    unsigned int unk11 : 3;
    unsigned int sitSleepState : 4;
    unsigned int flyState : 3;
    unsigned int lifeState : 4;
    unsigned int knockState : 3;
    unsigned int meleeAttackState : 4;
};
static_assert(sizeof(ActorState1) == 4, "ActorState1 layout differs from the PDB");
