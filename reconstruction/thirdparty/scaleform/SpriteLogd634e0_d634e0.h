// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// SpriteLogd634e0: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functiond634e0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>
#include <cstdarg>

class Sprited634e0;
// Logd634e0, SpriteRootd634e0, Sprited634e0: GUESS(low) STANDIN; sprite logging base relationship
struct Logd634e0 { virtual ~Logd634e0(); virtual void Print(unsigned,const char*,va_list); };
class SpriteRootd634e0 { public:
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
    virtual void Unk29();
    virtual Logd634e0* GetLog();
    std::uint8_t unknown08[16];
};

class SpriteLogd634e0
{
public:
    std::uint64_t unknown00;

    void Functiond634e0(const char* format, ...);
};

class Sprited634e0 : public SpriteRootd634e0, public SpriteLogd634e0 {};
