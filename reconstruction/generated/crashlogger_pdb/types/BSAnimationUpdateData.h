// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSAnimationUpdateData; size 0x30
#pragma once

struct IPostAnimationChannelUpdateFunctor_d63ea43c;
struct NiPoint3;
struct TESObjectREFR_b225f218;
struct BSAnimationUpdateData {
    float deltaTime;
    unsigned int pad04;
    void* unkFunctionPtr;
    TESObjectREFR_b225f218* refr;
    NiPoint3* optionalEyePosition;
    IPostAnimationChannelUpdateFunctor_d63ea43c* updateFunctor;
    unsigned short flags;
    bool unk2A;
    bool unk2B;
    bool unk2C;
    bool unk2D;
    bool unk2E;
    bool unk2F;
};
static_assert(sizeof(BSAnimationUpdateData) == 48, "BSAnimationUpdateData layout differs from the PDB");
