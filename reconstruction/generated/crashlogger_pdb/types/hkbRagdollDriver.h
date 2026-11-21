// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkbRagdollDriver; size 0xd0
#pragma once

#include "hkArray_int_16774380.h"
#include "hkReferencedObject.h"
struct hkaRagdollInstance;
struct hkbCharacter_b1920be0;
struct hkbRagdollDriver {
    hkReferencedObject _base;
    unsigned long long unk10;
    unsigned long long unk18;
    unsigned long long unk20;
    unsigned long long unk28;
    unsigned long long unk30;
    unsigned long long unk38;
    unsigned long long unk40;
    unsigned long long unk48;
    unsigned long long unk50;
    hkArray_int_16774380 reportingWhenKeyframed;
    unsigned long long unk68;
    unsigned long long unk70;
    unsigned long long unk78;
    hkbCharacter_b1920be0* character;
    hkaRagdollInstance* ragdoll;
    unsigned long long unk90;
    unsigned long long unk98;
    unsigned long long unkA0;
    unsigned long long unkA8;
    unsigned long long unkB0;
    unsigned int unkB8;
    float unkBC;
    float unkC0;
    unsigned int unkC4;
    unsigned long long unkC8;
};
static_assert(sizeof(hkbRagdollDriver) == 208, "hkbRagdollDriver layout differs from the PDB");
