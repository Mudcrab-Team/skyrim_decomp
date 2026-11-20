// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESProduceForm; size 0x20
#pragma once

#include "BaseFormComponent.h"
struct BGSSoundDescriptorForm;
struct TESBoundObject_fc790793;
struct TESProduceForm {
    BaseFormComponent _base;
    BGSSoundDescriptorForm* harvestSound;
    TESBoundObject_fc790793* produceItem;
    unsigned char produceChance[4];
    unsigned int pad1C;
};
static_assert(sizeof(TESProduceForm) == 32, "TESProduceForm layout differs from the PDB");
