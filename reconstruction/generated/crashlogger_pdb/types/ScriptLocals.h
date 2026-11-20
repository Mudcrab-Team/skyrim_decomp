// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ScriptLocals; size 0x28
#pragma once

struct RE__BSSimpleList_RE__ACTION_OBJECT_c6501490;
struct RE__BSSimpleList_RE__SCRIPT_LOCAL_b8cfe128;
struct SCRIPT_EFFECT_DATA;
struct Script;
struct ScriptLocals {
    Script* masterScript;
    unsigned char flags;
    unsigned char pad09;
    unsigned short pad0A;
    unsigned int pad0C;
    RE__BSSimpleList_RE__ACTION_OBJECT_c6501490* actionList;
    RE__BSSimpleList_RE__SCRIPT_LOCAL_b8cfe128* localList;
    SCRIPT_EFFECT_DATA* scriptEffectData;
};
static_assert(sizeof(ScriptLocals) == 40, "ScriptLocals layout differs from the PDB");
