// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Script; size 0x80
#pragma once

#include "BSSimpleList_RE__SCRIPT_REFERENCED_OBJECT_7814d1f8.h"
#include "BSSimpleList_RE__ScriptVariable_55b7497a.h"
#include "SCRIPT_HEADER.h"
#include "TESForm.h"
struct ScriptData;
struct TESQuest_fe66f8e1;
struct Script {
    TESForm _base;
    SCRIPT_HEADER header;
    unsigned int pad34;
    unsigned char* text;
    ScriptData* data;
    float profilerTimer;
    float questScriptDelay;
    float questScriptGetSecondsBuffer;
    unsigned int pad54;
    TESQuest_fe66f8e1* parentQuest;
    BSSimpleList_RE__SCRIPT_REFERENCED_OBJECT_7814d1f8 refObjects;
    BSSimpleList_RE__ScriptVariable_55b7497a variables;
};
static_assert(sizeof(Script) == 128, "Script layout differs from the PDB");
