// Source exposure: mixed (names and layout from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB layout.
// Script, Script::sub_1402E7B90, Script::variables: CRASHLOGGER_PDB(59818@2026.10.24)
// ScriptVariable, ScriptVariable::id, ScriptVariable::isInteger, ScriptVariable::name, ScriptVariableNode: GUESS
#pragma once

#include <cstdint>

struct ScriptVariable
{
    std::uint32_t id;
    std::uint32_t unk04;
    std::uint64_t unk08;
    bool isInteger;
    const char* name;
};

struct ScriptVariableNode
{
    ScriptVariable* item;
    ScriptVariableNode* next;
};

class Script
{
  public:
    char sub_1402E7B90(const char* a_name, std::uint32_t* a_outId);

    std::uint8_t unk00[0x70];
    ScriptVariableNode variables;
};
