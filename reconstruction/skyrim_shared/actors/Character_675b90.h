// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Character: STANDIN GUESS(low); placeholder class, a view of the virtual table and the actor-state word only
// Character::UpdateWeaponDrawRequest: GUESS(low)
// Character::SlotPad00 to Character::SlotPadA5, pad08: GUESS(low); slot and padding placeholders
// DrawWeaponMagicHands, ActorState2, actorState2, weaponState, WEAPON_STATE, kSheathed, kWantToDraw, kDrawing, kDrawn, kWantToSheathe, kSheathing, GetWeaponState: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG's ActorState base sits 8 bytes later in this build, modelled as a member word
// ActorState2::bits00, ActorState2::rest: GUESS(low); the bit-fields around weaponState, unnamed here
#pragma once

#include <cstdint>
#include <cstddef>

enum class WEAPON_STATE : std::uint32_t
{
    kSheathed = 0,
    kWantToDraw = 1,
    kDrawing = 2,
    kDrawn = 3,
    kWantToSheathe = 4,
    kSheathing = 5
};

struct ActorState2
{
    std::uint32_t bits00 : 5;       // 0:00
    WEAPON_STATE  weaponState : 3;  // 0:05
    std::uint32_t rest : 24;        // 0:08
};

class Character
{
public:
    virtual void SlotPad00();
    virtual void SlotPad01();
    virtual void SlotPad02();
    virtual void SlotPad03();
    virtual void SlotPad04();
    virtual void SlotPad05();
    virtual void SlotPad06();
    virtual void SlotPad07();
    virtual void SlotPad08();
    virtual void SlotPad09();
    virtual void SlotPad0A();
    virtual void SlotPad0B();
    virtual void SlotPad0C();
    virtual void SlotPad0D();
    virtual void SlotPad0E();
    virtual void SlotPad0F();
    virtual void SlotPad10();
    virtual void SlotPad11();
    virtual void SlotPad12();
    virtual void SlotPad13();
    virtual void SlotPad14();
    virtual void SlotPad15();
    virtual void SlotPad16();
    virtual void SlotPad17();
    virtual void SlotPad18();
    virtual void SlotPad19();
    virtual void SlotPad1A();
    virtual void SlotPad1B();
    virtual void SlotPad1C();
    virtual void SlotPad1D();
    virtual void SlotPad1E();
    virtual void SlotPad1F();
    virtual void SlotPad20();
    virtual void SlotPad21();
    virtual void SlotPad22();
    virtual void SlotPad23();
    virtual void SlotPad24();
    virtual void SlotPad25();
    virtual void SlotPad26();
    virtual void SlotPad27();
    virtual void SlotPad28();
    virtual void SlotPad29();
    virtual void SlotPad2A();
    virtual void SlotPad2B();
    virtual void SlotPad2C();
    virtual void SlotPad2D();
    virtual void SlotPad2E();
    virtual void SlotPad2F();
    virtual void SlotPad30();
    virtual void SlotPad31();
    virtual void SlotPad32();
    virtual void SlotPad33();
    virtual void SlotPad34();
    virtual void SlotPad35();
    virtual void SlotPad36();
    virtual void SlotPad37();
    virtual void SlotPad38();
    virtual void SlotPad39();
    virtual void SlotPad3A();
    virtual void SlotPad3B();
    virtual void SlotPad3C();
    virtual void SlotPad3D();
    virtual void SlotPad3E();
    virtual void SlotPad3F();
    virtual void SlotPad40();
    virtual void SlotPad41();
    virtual void SlotPad42();
    virtual void SlotPad43();
    virtual void SlotPad44();
    virtual void SlotPad45();
    virtual void SlotPad46();
    virtual void SlotPad47();
    virtual void SlotPad48();
    virtual void SlotPad49();
    virtual void SlotPad4A();
    virtual void SlotPad4B();
    virtual void SlotPad4C();
    virtual void SlotPad4D();
    virtual void SlotPad4E();
    virtual void SlotPad4F();
    virtual void SlotPad50();
    virtual void SlotPad51();
    virtual void SlotPad52();
    virtual void SlotPad53();
    virtual void SlotPad54();
    virtual void SlotPad55();
    virtual void SlotPad56();
    virtual void SlotPad57();
    virtual void SlotPad58();
    virtual void SlotPad59();
    virtual void SlotPad5A();
    virtual void SlotPad5B();
    virtual void SlotPad5C();
    virtual void SlotPad5D();
    virtual void SlotPad5E();
    virtual void SlotPad5F();
    virtual void SlotPad60();
    virtual void SlotPad61();
    virtual void SlotPad62();
    virtual void SlotPad63();
    virtual void SlotPad64();
    virtual void SlotPad65();
    virtual void SlotPad66();
    virtual void SlotPad67();
    virtual void SlotPad68();
    virtual void SlotPad69();
    virtual void SlotPad6A();
    virtual void SlotPad6B();
    virtual void SlotPad6C();
    virtual void SlotPad6D();
    virtual void SlotPad6E();
    virtual void SlotPad6F();
    virtual void SlotPad70();
    virtual void SlotPad71();
    virtual void SlotPad72();
    virtual void SlotPad73();
    virtual void SlotPad74();
    virtual void SlotPad75();
    virtual void SlotPad76();
    virtual void SlotPad77();
    virtual void SlotPad78();
    virtual void SlotPad79();
    virtual void SlotPad7A();
    virtual void SlotPad7B();
    virtual void SlotPad7C();
    virtual void SlotPad7D();
    virtual void SlotPad7E();
    virtual void SlotPad7F();
    virtual void SlotPad80();
    virtual void SlotPad81();
    virtual void SlotPad82();
    virtual void SlotPad83();
    virtual void SlotPad84();
    virtual void SlotPad85();
    virtual void SlotPad86();
    virtual void SlotPad87();
    virtual void SlotPad88();
    virtual void SlotPad89();
    virtual void SlotPad8A();
    virtual void SlotPad8B();
    virtual void SlotPad8C();
    virtual void SlotPad8D();
    virtual void SlotPad8E();
    virtual void SlotPad8F();
    virtual void SlotPad90();
    virtual void SlotPad91();
    virtual void SlotPad92();
    virtual void SlotPad93();
    virtual void SlotPad94();
    virtual void SlotPad95();
    virtual void SlotPad96();
    virtual void SlotPad97();
    virtual void SlotPad98();
    virtual void SlotPad99();
    virtual void SlotPad9A();
    virtual void SlotPad9B();
    virtual void SlotPad9C();
    virtual void SlotPad9D();
    virtual void SlotPad9E();
    virtual void SlotPad9F();
    virtual void SlotPadA0();
    virtual void SlotPadA1();
    virtual void SlotPadA2();
    virtual void SlotPadA3();
    virtual void SlotPadA4();
    virtual void SlotPadA5();
    virtual void DrawWeaponMagicHands(bool a_draw);  // A6

    WEAPON_STATE GetWeaponState() const { return actorState2.weaponState; }

    void UpdateWeaponDrawRequest();  // compared: 0x675b90
    std::uint8_t pad08[0xC4];
    ActorState2  actorState2;  // CC
};
