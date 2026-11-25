// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// MagicItem: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function150a40: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Form150a40, ResolveMagicForm, CastMagicForm, formType150a40, magicType150a40: GUESS(low) STANDIN; form lookup and runtime cast
struct Form150a40 {
    virtual void Unk00();
    virtual void Unk01();
    virtual void Unk02();
    virtual void Unk03();
    virtual void Unk04();
    virtual void Unk05();
    virtual void Unk06();
    virtual void Unk07();
    virtual void Unk08();
    virtual void Unk09();
    virtual void Unk0A();
    virtual void Unk0B();
    virtual void Unk0C();
    virtual void Unk0D();
    virtual void Unk0E();
    virtual void Unk0F();
    virtual void Unk10();
    virtual void Unk11();
    virtual void Unk12();
    virtual void Unk13();
    virtual void Unk14();
    virtual void Unk15();
    virtual void Unk16();
    virtual void Unk17();
    virtual void Unk18();
    virtual void Unk19();
    virtual void Unk1A();
    virtual void Unk1B();
    virtual void Unk1C();
    virtual void Unk1D();
    virtual void Unk1E();
    virtual void Unk1F();
    virtual void Unk20();
    virtual void Unk21();
    virtual void Unk22();
    virtual void Unk23();
    virtual void Unk24();
    virtual void Unk25();
    virtual void Unk26();
    virtual void Unk27();
    virtual void Unk28();
    virtual bool IsMagic();
};
extern "C" Form150a40* ResolveMagicForm(unsigned);
extern "C" void* CastMagicForm(void*,long,const void*,const void*,int);
extern unsigned char formType150a40;
extern unsigned char magicType150a40;

class MagicItem
{
public:

    static MagicItem* Function150a40(unsigned id);
};
