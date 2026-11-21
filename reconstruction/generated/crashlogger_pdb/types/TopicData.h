// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TopicData; size 0x10
#pragma once

#include "Type_bad13f76.h"
struct TESTopic_3cb1295e;
struct TopicData {
    Type_bad13f76 type;
    unsigned int pad04;
    TESTopic_3cb1295e* topic;
};
static_assert(sizeof(TopicData) == 16, "TopicData layout differs from the PDB");
