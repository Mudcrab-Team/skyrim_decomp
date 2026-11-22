// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectREFR, NiAVObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the virtual slots this unit needs
// TESObjectREFR::Get3D2, TESObjectREFR::Is3rdPersonVisible: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// PlayerCharacter::GetCurrent3D: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) SYMBOLS(fo4-pdb)
// PlayerCharacter::firstPerson3D: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG declares NiPointer<NiNode>, read here as a raw pointer at +0x900
// Sibling source: fo4-private@1b765c70 src/Game/AI/PlayerCharacter.cpp:589
#pragma once

class NiAVObject;

class TESObjectREFR
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual void unk08();
    virtual void unk09();
    virtual void unk0A();
    virtual void unk0B();
    virtual void unk0C();
    virtual void unk0D();
    virtual void unk0E();
    virtual void unk0F();
    virtual void unk10();
    virtual void unk11();
    virtual void unk12();
    virtual void unk13();
    virtual void unk14();
    virtual void unk15();
    virtual void unk16();
    virtual void unk17();
    virtual void unk18();
    virtual void unk19();
    virtual void unk1A();
    virtual void unk1B();
    virtual void unk1C();
    virtual void unk1D();
    virtual void unk1E();
    virtual void unk1F();
    virtual void unk20();
    virtual void unk21();
    virtual void unk22();
    virtual void unk23();
    virtual void unk24();
    virtual void unk25();
    virtual void unk26();
    virtual void unk27();
    virtual void unk28();
    virtual void unk29();
    virtual void unk2A();
    virtual void unk2B();
    virtual void unk2C();
    virtual void unk2D();
    virtual void unk2E();
    virtual void unk2F();
    virtual void unk30();
    virtual void unk31();
    virtual void unk32();
    virtual void unk33();
    virtual void unk34();
    virtual void unk35();
    virtual void unk36();
    virtual void unk37();
    virtual void unk38();
    virtual void unk39();
    virtual void unk3A();
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
    virtual NiAVObject* Get3D2() const;
    virtual bool Is3rdPersonVisible() const;
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
    virtual NiAVObject* GetCurrent3D() const;
};

class PlayerCharacter : public TESObjectREFR
{
public:
    virtual NiAVObject* GetCurrent3D() const override;

    unsigned char pad08[0x900 - 8];
    NiAVObject* firstPerson3D;
};
