// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSMessage; size 0x68
#pragma once

#include "BSSimpleList_RE__BGSMessage__MESSAGEBOX_BUTTON_b78fa361.h"
#include "MessageFlag.h"
#include "TESDescription.h"
#include "TESForm.h"
#include "TESFullName.h"
struct BGSMenuIcon;
struct TESQuest_fe66f8e1;
struct BGSMessage {
    TESForm _base;
    TESFullName _base_TESFullName;
    TESDescription _base_TESDescription;
    BGSMenuIcon* icon;
    TESQuest_fe66f8e1* ownerQuest;
    BSSimpleList_RE__BGSMessage__MESSAGEBOX_BUTTON_b78fa361 menuButtons;
    MessageFlag flags;
    unsigned int displayTime;
};
static_assert(sizeof(BGSMessage) == 104, "BGSMessage layout differs from the PDB");
