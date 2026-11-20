// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ActorState2; size 0x4
#pragma once
struct ActorState2 {
    unsigned int talkingToPlayer : 1;
    unsigned int forceRun : 1;
    unsigned int forceSneak : 1;
    unsigned int headTracking : 1;
    unsigned int reanimating : 1;
    unsigned int weaponState : 3;
    unsigned int wantBlocking : 1;
    unsigned int flightBlocked : 1;
    unsigned int recoil : 2;
    unsigned int allowFlying : 1;
    unsigned int staggered : 1;
    unsigned int unk14 : 18;
};
static_assert(sizeof(ActorState2) == 4, "ActorState2 layout differs from the PDB");
