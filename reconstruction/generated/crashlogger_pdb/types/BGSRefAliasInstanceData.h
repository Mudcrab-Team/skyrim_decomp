// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSRefAliasInstanceData; size 0x18
#pragma once

struct BGSBaseAlias;
struct BSTArray_RE__TESPackage_0280bbb0;
struct TESQuest_fe66f8e1;
struct BGSRefAliasInstanceData {
    TESQuest_fe66f8e1* quest;
    BGSBaseAlias* alias;
    BSTArray_RE__TESPackage_0280bbb0* instancedPackages;
};
static_assert(sizeof(BGSRefAliasInstanceData) == 24, "BGSRefAliasInstanceData layout differs from the PDB");
