// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSGameSound; size 0xc8
#pragma once

#include "BSTArray_RE__BSAudioMonitor__Request_RE__BSTSmallArrayHeapAllocator_8_7b120cd0.h"
#include "Flags_fa7f7281.h"
#include "ID.h"
#include "NiPoint3.h"
#include "SoundMessageList.h"
#include "SoundType.h"
struct BSGameSound_vtbl;
struct BSISoundCategory;
struct BSISoundOutputModel;
struct BSGameSound {
    BSGameSound_vtbl* __vftable;
    BSTArray_RE__BSAudioMonitor__Request_RE__BSTSmallArrayHeapAllocator_8_7b120cd0 requests;
    NiPoint3 beamEnd;
    unsigned char pad2C[4];
    SoundMessageList soundMessageList;
    ID resourceID;
    unsigned int unk4C;
    SoundType soundType;
    unsigned int unk54;
    unsigned int unk58;
    Flags_fa7f7281 flags;
    unsigned int durationMilliseconds;
    unsigned short staticAttenuation;
    unsigned short unk66;
    unsigned short systemAttenuation;
    unsigned short unk6A;
    unsigned short unk6C;
    unsigned char pad6E[2];
    float volume;
    float unk74;
    float unk78;
    unsigned int unk7C;
    float listenerDistance;
    unsigned int unk84;
    unsigned long long unk88;
    unsigned char unk90_raw[8];
    unsigned long long unk98;
    unsigned long long unkA0;
    unsigned int priority;
    unsigned int unkAC;
    BSISoundCategory* category;
    BSISoundOutputModel* outputModel;
    unsigned char frequency;
    unsigned char freqVariance;
    unsigned char padC2[6];
};
static_assert(sizeof(BSGameSound) == 200, "BSGameSound layout differs from the PDB");
