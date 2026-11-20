// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESPackage__TopicData; size 0x10
#pragma once

struct TESTopic;
struct TESPackage__TopicData {
    int TopicType_0;
    char _pad_4[4];
    TESTopic* Topic_8;
};
static_assert(sizeof(TESPackage__TopicData) == 16, "TESPackage__TopicData layout differs from the PDB");
