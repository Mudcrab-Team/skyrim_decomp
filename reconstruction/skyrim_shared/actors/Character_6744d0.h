// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Character: STANDIN GUESS(low); placeholder class, a view of the virtual table and the process member only
// Character::IsInCombatOrAlarmed: GUESS(low)
// Character::SlotPad00 to Character::SlotPadE2, pad08: GUESS(low); slot and padding placeholders
// IsInCombat, currentProcess: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG's Actor slot 0xE3 and member at 0xF0, 8 bytes later in this build
// AIProcess, ActorPackage, TESPackage, PACKAGE_DATA: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the members the body reads
// currentPackage, packageLock, package, packData, packType, PACKAGE_PROCEDURE_TYPE, kAlarm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG declares packType as an stl::enumeration byte and packageLock as a BSSpinLock, plain types here
// AIProcess::pad00, TESPackage::pad00, PACKAGE_DATA::pad0: GUESS(low); unread bytes before the members used
#pragma once

#include <cstdint>
#include <cstddef>

enum class PACKAGE_PROCEDURE_TYPE : std::uint8_t
{
    kAlarm = 21
};

struct PACKAGE_DATA
{
    std::uint8_t           pad0[4];
    PACKAGE_PROCEDURE_TYPE packType;  // 4
};

class TESPackage
{
public:
    std::uint8_t pad00[0x20];
    PACKAGE_DATA packData;  // 20
};

class ActorPackage
{
public:
    std::uint64_t packageLock;  // 00
    TESPackage*   package;      // 08
};

class AIProcess
{
public:
    std::uint8_t pad00[0x18];
    ActorPackage currentPackage;  // 18
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
    virtual void SlotPadA6();
    virtual void SlotPadA7();
    virtual void SlotPadA8();
    virtual void SlotPadA9();
    virtual void SlotPadAA();
    virtual void SlotPadAB();
    virtual void SlotPadAC();
    virtual void SlotPadAD();
    virtual void SlotPadAE();
    virtual void SlotPadAF();
    virtual void SlotPadB0();
    virtual void SlotPadB1();
    virtual void SlotPadB2();
    virtual void SlotPadB3();
    virtual void SlotPadB4();
    virtual void SlotPadB5();
    virtual void SlotPadB6();
    virtual void SlotPadB7();
    virtual void SlotPadB8();
    virtual void SlotPadB9();
    virtual void SlotPadBA();
    virtual void SlotPadBB();
    virtual void SlotPadBC();
    virtual void SlotPadBD();
    virtual void SlotPadBE();
    virtual void SlotPadBF();
    virtual void SlotPadC0();
    virtual void SlotPadC1();
    virtual void SlotPadC2();
    virtual void SlotPadC3();
    virtual void SlotPadC4();
    virtual void SlotPadC5();
    virtual void SlotPadC6();
    virtual void SlotPadC7();
    virtual void SlotPadC8();
    virtual void SlotPadC9();
    virtual void SlotPadCA();
    virtual void SlotPadCB();
    virtual void SlotPadCC();
    virtual void SlotPadCD();
    virtual void SlotPadCE();
    virtual void SlotPadCF();
    virtual void SlotPadD0();
    virtual void SlotPadD1();
    virtual void SlotPadD2();
    virtual void SlotPadD3();
    virtual void SlotPadD4();
    virtual void SlotPadD5();
    virtual void SlotPadD6();
    virtual void SlotPadD7();
    virtual void SlotPadD8();
    virtual void SlotPadD9();
    virtual void SlotPadDA();
    virtual void SlotPadDB();
    virtual void SlotPadDC();
    virtual void SlotPadDD();
    virtual void SlotPadDE();
    virtual void SlotPadDF();
    virtual void SlotPadE0();
    virtual void SlotPadE1();
    virtual void SlotPadE2();
    virtual bool IsInCombat() const;  // E3

    bool IsInCombatOrAlarmed() const;  // compared: 0x6744d0
    std::uint8_t pad08[0xF0];
    AIProcess*   currentProcess;  // F8
};
