// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// GFxASCharacter, GASObjectInterface_Func10: CRASHLOGGER_PDB(59818@2026.10.24)
// GASEnvironment, GFxCharacter, GASObjectInterface: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// GetASEnvironment, ForwardMember, unk08, Unk_01..Unk_1B: GUESS(low)
#pragma once

#include <cstdint>

class GASEnvironment;

class GFxCharacter
{
public:
    virtual ~GFxCharacter();
    virtual void Unk_01(); virtual void Unk_02(); virtual void Unk_03(); virtual void Unk_04();
    virtual void Unk_05(); virtual void Unk_06(); virtual void Unk_07(); virtual void Unk_08();
    virtual void Unk_09(); virtual void Unk_0A(); virtual void Unk_0B(); virtual void Unk_0C();
    virtual void Unk_0D(); virtual void Unk_0E(); virtual void Unk_0F(); virtual void Unk_10();
    virtual void Unk_11(); virtual void Unk_12(); virtual void Unk_13(); virtual void Unk_14();
    virtual void Unk_15(); virtual void Unk_16(); virtual void Unk_17(); virtual void Unk_18();
    virtual void Unk_19(); virtual void Unk_1A(); virtual void Unk_1B();
    virtual GASEnvironment* GetASEnvironment();  // E0

    std::uint8_t unk08[0x90];  // 08
};
static_assert(sizeof(GFxCharacter) == 0x98, "GFxCharacter size");

class GASObjectInterface
{
public:
    virtual ~GASObjectInterface();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual bool ForwardMember(GASEnvironment* env, void* arg1, void* arg2, void* arg3);  // 18
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual bool GASObjectInterface_Func10(GASEnvironment* env, void* arg1, void* arg2, void* arg3);
};

class GFxASCharacter : public GFxCharacter, public GASObjectInterface
{
public:
    bool GASObjectInterface_Func10(GASEnvironment* env, void* arg1, void* arg2, void* arg3) override;
};
