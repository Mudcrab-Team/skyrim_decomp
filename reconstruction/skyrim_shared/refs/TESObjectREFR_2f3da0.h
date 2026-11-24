// Source exposure: mixed (community declarations and the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectREFR, TESObjectCELL, TESWorldSpace: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// parentCell, cellFlags, worldSpace, IsInteriorCell, GetSaveParentCell: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectREFR::IsInInteriorOrOutsideWorld, unk20, unk41: GUESS(low)
// unk3B..unk96: GUESS(low); unused virtual slots between the base and GetSaveParentCell
#pragma once

#include "declarations/TESForm.h"

class TESWorldSpace;

class TESObjectCELL : public TESForm
{
public:
    bool IsInteriorCell() const { return (cellFlags & 1) != 0; }

    std::uint8_t unk20[0x20];
    std::uint8_t cellFlags;
    std::uint8_t unk41[0xE7];
    TESWorldSpace* worldSpace;
};

class TESObjectREFR : public TESForm
{
public:
    bool IsInInteriorOrOutsideWorld() const;

    virtual void unk3B();
    virtual void unk3C();
    virtual void unk3D();
    virtual void unk3E();
    virtual void unk3F();
    virtual void unk40();
    virtual void unk41();
    virtual void unk42();
    virtual void unk43();
    virtual void unk44();
    virtual void unk45();
    virtual void unk46();
    virtual void unk47();
    virtual void unk48();
    virtual void unk49();
    virtual void unk4A();
    virtual void unk4B();
    virtual void unk4C();
    virtual void unk4D();
    virtual void unk4E();
    virtual void unk4F();
    virtual void unk50();
    virtual void unk51();
    virtual void unk52();
    virtual void unk53();
    virtual void unk54();
    virtual void unk55();
    virtual void unk56();
    virtual void unk57();
    virtual void unk58();
    virtual void unk59();
    virtual void unk5A();
    virtual void unk5B();
    virtual void unk5C();
    virtual void unk5D();
    virtual void unk5E();
    virtual void unk5F();
    virtual void unk60();
    virtual void unk61();
    virtual void unk62();
    virtual void unk63();
    virtual void unk64();
    virtual void unk65();
    virtual void unk66();
    virtual void unk67();
    virtual void unk68();
    virtual void unk69();
    virtual void unk6A();
    virtual void unk6B();
    virtual void unk6C();
    virtual void unk6D();
    virtual void unk6E();
    virtual void unk6F();
    virtual void unk70();
    virtual void unk71();
    virtual void unk72();
    virtual void unk73();
    virtual void unk74();
    virtual void unk75();
    virtual void unk76();
    virtual void unk77();
    virtual void unk78();
    virtual void unk79();
    virtual void unk7A();
    virtual void unk7B();
    virtual void unk7C();
    virtual void unk7D();
    virtual void unk7E();
    virtual void unk7F();
    virtual void unk80();
    virtual void unk81();
    virtual void unk82();
    virtual void unk83();
    virtual void unk84();
    virtual void unk85();
    virtual void unk86();
    virtual void unk87();
    virtual void unk88();
    virtual void unk89();
    virtual void unk8A();
    virtual void unk8B();
    virtual void unk8C();
    virtual void unk8D();
    virtual void unk8E();
    virtual void unk8F();
    virtual void unk90();
    virtual void unk91();
    virtual void unk92();
    virtual void unk93();
    virtual void unk94();
    virtual void unk95();
    virtual void unk96();
    virtual TESObjectCELL* GetSaveParentCell() const;

    std::uint8_t unk20[0x40];
    TESObjectCELL* parentCell;
};
