// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ImpactSoundData; size 0x38
#pragma once

struct BGSImpactData;
struct BSSoundHandle;
struct NiAVObject;
struct NiPoint3;
struct SoundHandlePool;
struct ImpactSoundData {
    BGSImpactData* impactData;
    NiPoint3* position;
    NiAVObject* objectToFollow;
    BSSoundHandle* sound1;
    BSSoundHandle* sound2;
    bool playSound1;
    bool playSound2;
    bool lowPriority;
    unsigned char undefined_2b[5];
    SoundHandlePool* pool;
};
static_assert(sizeof(ImpactSoundData) == 56, "ImpactSoundData layout differs from the PDB");
