// Source exposure: binary-analysis
// Unlock6c8000: GUESS(low) STANDIN; original owner is unknown
// Function6c8000: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
struct Extra6c8000 { std::uint64_t unk00[3]; };
extern void* GetExtraStyle(Extra6c8000*);
struct Middle6c8000 {
    std::uint64_t unk00[13];
    void* style;
};
struct Process6c8000 {
    std::uint64_t unk00;
    std::uint64_t unk08;
    std::uint64_t unk10;
    std::uint64_t unk18;
    Middle6c8000* middle;
};
class Base6c8000 { public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void Slot53();
    virtual void Slot54();
    virtual void Slot55();
    virtual void Slot56();
    virtual void Slot57();
    virtual void Slot58();
    virtual void Slot59();
    virtual void Slot60();
    virtual void Slot61();
    virtual void Slot62();
    virtual void Slot63();
    virtual void Slot64();
    virtual void Slot65();
    virtual void Slot66();
    virtual void Slot67();
    virtual void Slot68();
    virtual void Slot69();
    virtual void Slot70();
    virtual void Slot71();
    virtual void Slot72();
    virtual void Slot73();
    virtual void Slot74();
    virtual void Slot75();
    virtual void Slot76();
    virtual void Slot77();
    virtual void Slot78();
    virtual void Slot79();
    virtual void Slot80();
    virtual void Slot81();
    virtual void Slot82();
    virtual void Slot83();
    virtual void* GetStyle();
};

class Unlock6c8000 {
public:
    std::uint64_t unk00[8];
    Base6c8000* base;
    std::uint64_t unk48, unk50, unk58, unk60, unk68;
    Extra6c8000 extra;
    std::uint64_t unk88[14];
    Process6c8000* process;
    void* Function6c8000();
};
