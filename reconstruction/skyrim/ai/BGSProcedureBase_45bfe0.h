// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the pinned procedure code.
// BGSProcedureBase: EXE_RTTI
// ProcedureStateName, text, ProcedureExecutionState, CreateState, GetStateName, Slots00..Slot1D: GUESS(low)
// ProcedureStateRegistry, FindFactory, GetProcedureStateRegistry: GUESS(low)
// ProcedureOptions, optionsStorage, options, unknown08, flags, unknown2C: GUESS(low)
// HasStateName, CreateExecutionState, ReplaceOptions, CopyDefaultStateValue, SetFlag, gDefaultStateValue: GUESS(low)
#pragma once

#include <cstdint>

struct ProcedureStateName
{
    const char* text;
};

class ProcedureExecutionState
{
public:
    virtual void Slot00();
    virtual ProcedureExecutionState* CreateState();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual const ProcedureStateName& GetStateName() const;
};

class ProcedureStateRegistry
{
public:
    ProcedureExecutionState* FindFactory(const ProcedureStateName& name);
};

ProcedureStateRegistry& GetProcedureStateRegistry();

struct ProcedureOptions
{
    std::uint8_t optionsStorage[0x10];
};

class BGSProcedureBase
{
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0A();
    virtual void Slot0B();
    virtual void Slot0C();
    virtual void Slot0D();
    virtual void Slot0E();
    virtual void Slot0F();
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
    virtual void Slot1A();
    virtual void Slot1B();
    virtual void Slot1C();
    virtual void Slot1D();
    virtual const ProcedureStateName& GetStateName() const;

    bool HasStateName(const ProcedureExecutionState& state) const;
    ProcedureExecutionState* CreateExecutionState();
    void ReplaceOptions(ProcedureOptions* replacement);
    std::uint32_t& CopyDefaultStateValue(std::uint32_t& value) const;
    void SetFlag(bool enabled);

protected:
    std::uint8_t unknown08[0x20];
    std::uint32_t flags;
    std::uint32_t unknown2C;
    ProcedureOptions* options;
};
