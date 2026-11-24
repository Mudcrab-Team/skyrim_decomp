// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// CombatUtilities_ComputeProjectileTime: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0); sibling name, identity with this function unproven
// Actor: GUESS(low); placeholder name
#pragma once

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;

#define __local_vftable_ctor_closure FNVLocalVftableCtorClosure
class BGSSaveFormBuffer;
class BGSLoadFormBuffer;

class CombatCoverPointData_combatutilities
{
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;

    void Copy(void*);
    void SaveGame(BGSSaveFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    bool IsHideCover();
    bool IsCrouchCover();
    bool IsStandCover();
    bool IsLedgeCover();
    bool IsValidCover();
    unsigned char GetCoverHeight();
    bool IsReserved();
    void SetReserved(bool);
    bool IsDirty();
    void SetDirty(bool);
    void* __vecDelDtor(unsigned int);
};
#undef __local_vftable_ctor_closure

struct CombatPoint3
{
    float x, y, z;
};


extern "C" float NiCos(float);

struct Actor
{
};
