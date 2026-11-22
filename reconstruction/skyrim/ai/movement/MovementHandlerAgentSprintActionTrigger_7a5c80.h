// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// MovementHandlerAgentSprintActionTrigger::Init: SYMBOLS(fo4-pdb) CRASHLOGGER_PDB(59818@2026.10.24); the vtable slot is not known, so it is declared alone
// MovementHandlerAgentSprintActionTrigger::eState: SYMBOLS(fo4-pdb); FO4 gives the offset 0x38 and an enum type, read here as a 32-bit value
// BSPathingStreamRead, BSPathingStreamRead::ReadValue: SYMBOLS(fo4-pdb) GUESS(low); the method name and slot are placeholders
#pragma once

#include <cstdint>

struct BSPathingStreamRead
{
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void ReadValue(std::uint32_t* out);
};

class MovementHandlerAgentSprintActionTrigger
{
public:
    virtual void Init(BSPathingStreamRead* stream);

    unsigned char pad08[0x30];
    std::uint32_t eState;
};
