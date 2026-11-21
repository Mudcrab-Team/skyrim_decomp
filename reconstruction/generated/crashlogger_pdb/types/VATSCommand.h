// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: VATSCommand; size 0xb8
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "ActorValue_a2156ae9.h"
#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
#include "HitData_e932ff94.h"
struct VATSCommand {
    unsigned int actionPoints;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned char unk08;
    unsigned char unk09;
    unsigned short unk0A;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 targetHandle;
    ActorValue_a2156ae9 bodyPartAV;
    unsigned int pad14;
    HitData_e932ff94 hitData;
    unsigned long long unkA8;
    unsigned int unkB0;
    unsigned char undefined_b4[4];
};
static_assert(sizeof(VATSCommand) == 184, "VATSCommand layout differs from the PDB");
