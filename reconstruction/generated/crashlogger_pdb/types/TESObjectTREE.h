// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESObjectTREE; size 0xc8
#pragma once

#include "OBJ_TREE.h"
#include "TESBoundObject_fc790793.h"
#include "TESFullName.h"
#include "TESModel_c52655e4.h"
#include "TESProduceForm.h"
#include "etTreeType.h"
struct BaseTreeData;
struct TESObjectTREE {
    TESBoundObject_fc790793 _base;
    TESModel_c52655e4 _base_TESModel;
    TESFullName _base_TESFullName;
    TESProduceForm _base_TESProduceForm;
    OBJ_TREE data;
    BaseTreeData* baseData;
    etTreeType type;
    unsigned int padC4;
};
static_assert(sizeof(TESObjectTREE) == 200, "TESObjectTREE layout differs from the PDB");
